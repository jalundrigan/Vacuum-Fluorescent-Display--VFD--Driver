#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

#include "i2c_driver.h"

static i2c_rx_state_t i2c_rx_state;

void
i2c_init()
{
    TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWIE); // Enable TWI
    TWAR = (VFD_I2C_ADDRESS << 1);    // Configure slave address

    i2c_rx_state.i2c_rx_complete = RX_NOT_COMPLETE;
    i2c_rx_state.i2c_command = RX_DISABLE;
    i2c_rx_state.byte_target = 0;
    i2c_rx_state.byte_count = 0;
    i2c_rx_state.byte_buf = (uint8_t *)0;
}


ISR(TWI_vect)
{
    // mask TWSR to discard settings bits
    uint8_t twsr_masked = TWSR & 0xFC;

    volatile uint8_t to_twcr = (1 << TWEN) | (1 << TWINT) | (1 << TWIE);

    switch (twsr_masked)
    {
        case 0x60: // Slave address and write bit received. ACK returned.
			asm("nop");
		
            if(i2c_rx_state.i2c_command == RX_ENABLE)
            {
                /*
                    ACK the next packet
                */
                to_twcr |= (1 << TWEA);
                i2c_rx_state.i2c_command = RX_DISABLE;
            }
            /*
                Otherwise, NACK the next packet.
                We will fall into case 0x88 next packet.
            */

            break;

        case 0x80: // Data received. ACK returned.
			asm("nop");
	
            i2c_rx_state.byte_buf[i2c_rx_state.byte_count++] = TWDR;

            if(i2c_rx_state.byte_count < i2c_rx_state.byte_target)
            {
                /*
                    ACK the next packet if we are not done receiving
                */
                to_twcr |= (1 << TWEA);
            }
            /*
                Otherwise NACK the next packet if we are done receiving. 
                We will fall into case 0x88 next packet.
            */

            break;

        case 0x88: // Data received. NACK returned.
			asm("nop");
            /*
                Switch back to not addressed mode and still recognize own address.
            */
			
			//Flush the buffer if we NACK a packet.
			i2c_rx_state.byte_count = 0;
            to_twcr |= (1 << TWEA);
            
			break;

        case 0xA0: // Stop/Repeated Start
			asm("nop");
		
            /*
                Switch back to not addressed mode and still recognize own address.
            */
			if(i2c_rx_state.byte_count == i2c_rx_state.byte_target && i2c_rx_state.i2c_rx_complete == RX_NOT_COMPLETE)
			{
				i2c_rx_state.i2c_rx_complete = RX_COMPLETE;
			}
			
			to_twcr |= (1 << TWEA);
			
            break;
     

        default:
			asm("nop");
          
            break;
    }

    TWCR = to_twcr;
}



void start_new_i2c_rx(uint8_t *buf, uint8_t byte_target)
{
    if(byte_target == 0)
    {
        return;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        i2c_rx_state.i2c_rx_complete = RX_NOT_COMPLETE;
        i2c_rx_state.i2c_command = RX_ENABLE;
        i2c_rx_state.byte_target = byte_target;
        i2c_rx_state.byte_count = 0;
        i2c_rx_state.byte_buf = buf;
    }
}

i2c_rx_complete_t is_i2c_rx_complete()
{
    i2c_rx_complete_t status;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        status = i2c_rx_state.i2c_rx_complete;
    }
    return status;
}