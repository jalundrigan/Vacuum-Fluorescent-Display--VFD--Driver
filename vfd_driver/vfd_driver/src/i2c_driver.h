#ifndef _I2C_DRIVER_H_
#define _I2C_DRIVER_H_

#define VFD_I2C_ADDRESS 99


typedef enum i2c_rx_complete_t
{
    RX_NOT_COMPLETE,
    RX_COMPLETE
} i2c_rx_complete_t;

typedef enum i2c_command_t
{
    RX_DISABLE,
    RX_ENABLE
} i2c_command_t;


typedef struct i2c_rx_state_t
{
    i2c_rx_complete_t i2c_rx_complete;
    i2c_command_t i2c_command;
    uint8_t byte_target;
    uint8_t byte_count;
    uint8_t *byte_buf;
} i2c_rx_state_t;


void i2c_init();
void start_new_i2c_rx(uint8_t *buf, uint8_t byte_target);
i2c_rx_complete_t is_i2c_rx_complete();

#endif /*   _I2C_DRIVER_H_  */