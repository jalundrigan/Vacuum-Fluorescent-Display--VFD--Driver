#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>

#include "vfd_display_driver.h"

int main(void)
{
    
    // Configure clock
    CLKPR = (1 << CLKPCE); // enable a change to CLKPR
    CLKPR = 0;             // set prescaler to 1 - 8Mhz clock

    //wdt_enable(WDTO_500MS);
    //wdt_reset();
    //WDTCSR |= (1 << WDIE) | (1 << WDE);

    // Enable interrupts
    //sei();
    
    vfd_init();

    vfd_set_characters("jake");

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
        _delay_ms(5);
        vfd_display_update_callback();
    }
}


/*
ISR(WDT_vect)
{

}
*/