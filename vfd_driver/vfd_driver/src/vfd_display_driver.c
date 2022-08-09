#include <avr/io.h>
#include <util/delay.h>
#include "vfd_pin_driver.h"
#include "vfd_display_driver.h"

static vfd_state_t vfd_state;

void vfd_init()
{
    vfd_state.current_segment = (vfd_seg_index_t)0;
    vfd_state.char_buf[0] = '\0';
    vfd_state.char_buf[1] = '\0';
    vfd_state.char_buf[2] = '\0';
    vfd_state.char_buf[3] = '\0';
    vfd_state.symbol_flags = (vfd_symbol_flag_t)0;

    vfd_init_pins();
}

// simple dumb string copy with no error checks
vfd_return_status_t vfd_set_characters(const char *buf)
{
    vfd_state.char_buf[0] = buf[0];
    vfd_state.char_buf[1] = buf[1];
    vfd_state.char_buf[2] = buf[2];
    vfd_state.char_buf[3] = buf[3];

    return VFD_STATUS_OK;
}


// up to the user at which frequency they wish to call this at but it should be at least: TODO
vfd_return_status_t vfd_display_update_callback()
{
    vfd_clear_all_data_pins();
    vfd_clear_all_select_lines();

    //_delay_us(500);
    _delay_ms(1); 

    switch(vfd_state.current_segment)
    {
        case 0:
        case 2:
        case 3:
            vfd_set_7_segment(vfd_state.char_buf[3 - vfd_state.current_segment]);
            break;

        case 1:
            vfd_set_7_segment(vfd_state.char_buf[3 - vfd_state.current_segment]);
            /*
                The colon is an additional option for select line 1.
                We must not set the remaining symbols as some of them share the same
                data pins as the seven segment.
            */
            if(vfd_state.symbol_flags & SYMB_FLAG_COLON)
            {
                vfd_set_symbol(SYMB_FLAG_COLON);
            }
            break;
        
        case 4:
            /*
                The colon is not an option for select line 4.
                Make sure we don't set it or else we will see the REC symbol 
                light up.
            */
            vfd_set_symbol((vfd_state.symbol_flags) & (~SYMB_FLAG_COLON));
            break;
        
        default:
            vfd_data_error_handler(&vfd_state);
            return VFD_STATUS_FAIL;
    }

    vfd_set_select_line(vfd_state.current_segment);

    vfd_state.current_segment ++;
    vfd_state.current_segment %= 5;

    return VFD_STATUS_OK;
}

// user can override this if they wish to receive the fault
__attribute__((weak)) void vfd_data_error_handler(vfd_state_t *vfd_error_state)
{
}

void vfd_enable_symbols_from_flags(uint32_t flags)
{
    vfd_state.symbol_flags = (vfd_symbol_flag_t)flags;
}

/*
    Symbol enable functions
*/
void vfd_enable_mail_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_MAIL;
}

void vfd_enable_power_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_POWER;
}

void vfd_enable_house_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_HOUSE;
}

void vfd_enable_5_1_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_5_1;
}

void vfd_enable_hdtv_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_HDTV;
}

void vfd_enable_480_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_480;
}

void vfd_enable_480_i_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_480_i;
}

void vfd_enable_480_p_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_480_p;
}

void vfd_enable_colon_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_COLON;
}

void vfd_enable_rec_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_REC;
}

void vfd_enable_auto_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_AUTO;
}

void vfd_enable_1080_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_1080;
}

void vfd_enable_720_p_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_720_p;
}

void vfd_enable_720_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_720;
}

void vfd_enable_720_i_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_720_i;
}

void vfd_enable_1080_i_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_1080_i;
}

void vfd_enable_1080_p_symbol()
{
    vfd_state.symbol_flags |= SYMB_FLAG_1080_p;
}


/*
    Symbol disable functions
*/
void vfd_disable_mail_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_MAIL;
}

void vfd_disable_power_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_POWER;
}

void vfd_disable_house_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_HOUSE;
}

void vfd_disable_5_1_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_5_1;
}

void vfd_disable_hdtv_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_HDTV;
}

void vfd_disable_480_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_480;
}

void vfd_disable_480_i_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_480_i;
}

void vfd_disable_480_p_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_480_p;
}

void vfd_disable_colon_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_COLON;
}

void vfd_disable_rec_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_REC;
}

void vfd_disable_auto_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_AUTO;
}

void vfd_disable_1080_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_1080;
}

void vfd_disable_720_p_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_720_p;
}

void vfd_disable_720_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_720;
}

void vfd_disable_720_i_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_720_i;
}

void vfd_disable_1080_i_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_1080_i;
}

void vfd_disable_1080_p_symbol()
{
    vfd_state.symbol_flags &= ~SYMB_FLAG_1080_p;
}

