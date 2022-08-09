#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "src/vfd_display_driver.h"
#include "src/i2c_driver.h"

void do_vfd_bist();
void do_i2c_bist();


int main(void)
{
    
    // Configure clock
    CLKPR = (1 << CLKPCE); // enable a change to CLKPR
    CLKPR = 0;             // set prescaler to 1 - 8Mhz clock

    //wdt_enable(WDTO_500MS);
    //wdt_reset();
    //WDTCSR |= (1 << WDIE) | (1 << WDE);

    i2c_init();
    vfd_init();

    sei();

    //do_vfd_bist();
    //do_i2c_bist();

    vfd_set_characters("INIT");

    uint8_t buf[5];
    start_new_i2c_rx(buf, 5);

    for(;;)
    {
        if(is_i2c_rx_complete() == RX_COMPLETE)
        {
            if(buf[0] == 0x01)
            {
                vfd_set_characters(&(buf[1]));
            }
            else if(buf[0] == 0x02)
            {
                uint32_t symbol_flags = 0x00000000;
                symbol_flags |= (buf[1] << 24);
                symbol_flags |= (buf[2] << 16);
                symbol_flags |= (buf[3] << 8);
                symbol_flags |= (buf[4] << 0);

                vfd_enable_symbols_from_flags(symbol_flags);
            }

            start_new_i2c_rx(buf, 5);
        }

		_delay_ms(1);
        vfd_display_update_callback();
    }
}

void do_i2c_bist()
{
    uint8_t buf[10];
	uint8_t low = 0;

    start_new_i2c_rx(buf, 5);

    for(;;)
    {
        if(is_i2c_rx_complete() == RX_COMPLETE)
        {
			if(low % 2 == 0)
			{
				if(buf[0] != ((uint8_t)(0x10) | low))
				{
					asm("nop");
				}
				if(buf[1] != ((uint8_t)(0x20) | low))
				{
					asm("nop");
				}
				if(buf[2] != ((uint8_t)(0x30) | low))
				{
					asm("nop");
				}
				if(buf[3] != ((uint8_t)(0x40) | low))
				{
					asm("nop");
				}
				if(buf[4] != ((uint8_t)(0x50) | low))
				{
					asm("nop");
				}
			}
			else
			{
				if(buf[0] != 0xde)
				{
					asm("nop");
				}
				if(buf[1] != 0xde)
				{
					asm("nop");
				}
				if(buf[2] != 0xde)
				{
					asm("nop");
				}
				if(buf[3] != 0xde)
				{
					asm("nop");
				}
				if(buf[4] != 0xde)
				{
					asm("nop");
				}	
			}
			
			low ++;
			
            start_new_i2c_rx(buf, 5);
        }
    }
}

void do_vfd_bist()
{
    char disp[4] = "0000";
    uint16_t flip_counter = 0;
    uint8_t seg_counter = 0;

    vfd_set_characters("BIST");
    for(;;)
    {
        flip_counter ++;
        flip_counter %= 3000;
        if(flip_counter == 0)
        {
            break;
        }
        _delay_ms(1);
        vfd_display_update_callback();
    }
    
    vfd_set_characters("8888");
    for(;;)
    {
        flip_counter ++;
        flip_counter %= 3000;
        if(flip_counter == 0)
        {
            break;
        }
        _delay_ms(1);
        vfd_display_update_callback();
    }
    
    for(;;)
    {
        flip_counter ++;
        flip_counter %= 500;
        if(flip_counter == 0)
        {
            disp[seg_counter] += 1;
            if(disp[seg_counter] > '9')
            {
                disp[seg_counter] = '0';
                seg_counter ++;
                if(seg_counter == 4)
                {
                    break;
                }
            }
        }
        vfd_set_characters(disp);
        _delay_ms(1);
        vfd_display_update_callback();
    }

    vfd_set_characters("\0\0\0\0");
    seg_counter = 0;
    for(;;)
    {
        flip_counter ++;
        flip_counter %= 1000;
        if(flip_counter == 0)
        {
            if(seg_counter > 16)
            {
                vfd_disable_1080_p_symbol();
                break;
            }

            switch(seg_counter)
            {
                case 0:
                    vfd_enable_mail_symbol();
                    break;

                case 1:
                    vfd_enable_power_symbol();
                    vfd_disable_mail_symbol();
                    break;

                case 2:
                    vfd_enable_house_symbol();
                    vfd_disable_power_symbol();
                    break;

                case 3:
                    vfd_enable_5_1_symbol();
                    vfd_disable_house_symbol();
                    break;

                case 4:
                    vfd_enable_hdtv_symbol();
                    vfd_disable_5_1_symbol();
                    break;

                case 5:
                    vfd_enable_colon_symbol();
                    vfd_disable_hdtv_symbol();
                    break;

                case 6:
                    vfd_enable_rec_symbol();
                    vfd_disable_colon_symbol();
                    break;

                case 7:
                    vfd_enable_auto_symbol();
                    vfd_disable_rec_symbol();
                    break;

                case 8:
                    vfd_enable_480_symbol();
                    vfd_disable_auto_symbol();
                    break;

                case 9:
                    vfd_enable_480_i_symbol();
                    vfd_disable_480_symbol();
                    break;

                case 10:
                    vfd_enable_480_p_symbol();
                    vfd_disable_480_i_symbol();
                    break;

                case 11:
                    vfd_enable_720_symbol();
                    vfd_disable_480_p_symbol();
                    break;

                case 12:
                    vfd_enable_720_i_symbol();
                    vfd_disable_720_symbol();
                    break;

                case 13:
                    vfd_enable_720_p_symbol();
                    vfd_disable_720_i_symbol();
                    break;

                case 14:
                    vfd_enable_1080_symbol();
                    vfd_disable_720_p_symbol();
                    break;

                case 15:
                    vfd_enable_1080_i_symbol();
                    vfd_disable_1080_symbol();
                    break;

                case 16:
                    vfd_enable_1080_p_symbol();
                    vfd_disable_1080_i_symbol();
                    break;
            }

            seg_counter ++;
        }
        _delay_ms(1);
        vfd_display_update_callback();
    }


    vfd_set_characters("DONE");
    vfd_enable_mail_symbol();
    vfd_enable_power_symbol();
    vfd_enable_house_symbol();
    vfd_enable_5_1_symbol();
    vfd_enable_hdtv_symbol();
    vfd_enable_480_symbol();
    vfd_enable_480_i_symbol();
    vfd_enable_480_p_symbol();
	vfd_enable_colon_symbol();
    vfd_enable_rec_symbol();
    vfd_enable_auto_symbol();
    vfd_enable_1080_symbol();
    vfd_enable_720_p_symbol();
    vfd_enable_720_symbol();
    vfd_enable_720_i_symbol();
    vfd_enable_1080_i_symbol();
    vfd_enable_1080_p_symbol();

    for(;;)
    {
        flip_counter ++;
        flip_counter %= 3000;
        if(flip_counter == 0)
        {
            break;
        }
        _delay_ms(1);
        vfd_display_update_callback();
    }

}

/*
ISR(WDT_vect)
{

}
*/