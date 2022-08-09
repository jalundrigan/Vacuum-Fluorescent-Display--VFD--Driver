#include "i2c_driver.h"

//TODO: need some atomic blocking since some code may be called from an ISR


typedef enum comm_packet_state_t
{
    DATA_NOT_READY,
    DATA_READY
} comm_packet_state_t;


comm_packet_state_t is_comm_data_ready;


comm_packet_state_t *comm_read_data(uint8_t num_bytes, uint8_t *comm_data)
{
    // dont start new rx if we have one already occuring
    if(is_comm_data_ready == DATA_NOT_READY)
    {
        return NULL;
    }

    is_comm_data_ready = DATA_NOT_READY;

    start_new_i2c_rx(num_bytes, comm_data);

    return &is_comm_data_ready;
}  


void comm_data_rx_update()
{
    // dont try to fill the buffer if we havent started a new rx
    if(is_comm_data_ready == DATA_READY)
    {
        return;
    }

    i2c_rx_state_t *i2c_rx_state = service_i2c();

    if(i2c_rx_state->i2c_rx_complete == RX_COMPLETE)
    {
        is_comm_data_ready = DATA_READY;
    }
}
