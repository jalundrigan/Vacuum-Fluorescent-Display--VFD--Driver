#include <avr/io.h>
#include "vfd_pin_driver.h"

/*
    TODO: return values for error checking
*/

void vfd_init_pins()
{
    SEL_0_OUT_EN;
    SEL_1_OUT_EN;
    SEL_2_OUT_EN;
    SEL_3_OUT_EN;
    SEL_4_OUT_EN;

    A_OUT_EN;
    B_OUT_EN;
    C_OUT_EN;
    D_OUT_EN;
    E_OUT_EN;
    F_OUT_EN;
    G_OUT_EN;

    SYMB_MAIL_OUT_EN;
    SYMB_POWER_OUT_EN;
    SYMB_HOUSE_OUT_EN;
    SYMB_5_1_OUT_EN;
    SYMB_HDTV_OUT_EN;
    SYMB_480_OUT_EN;
    SYMB_480_i_OUT_EN;
    SYMB_480_p_OUT_EN;
    SYMB_COLON_OUT_EN;
    SYMB_REC_OUT_EN;
    SYMB_AUTO_OUT_EN;
    SYMB_1080_OUT_EN;
    SYMB_720_p_OUT_EN;
    SYMB_720_OUT_EN;
    SYMB_720_i_OUT_EN;
    SYMB_1080_i_OUT_EN;
    SYMB_1080_p_OUT_EN;

    // toggle OC1A on compare match
    TCCR1A |= (1 << COM1A0);
    // CTC mode
    TCCR1B |= (1 << WGM12);
    // clock scale by 64
    TCCR1B |= (1 << CS11 | 1 << CS10);
    // compare to 1
    OCR1A = 0x0000;
    // connect OC1A to PB1
    DDRB |= (1 << DDB1);

    vfd_clear_all_select_lines();
    vfd_clear_all_data_pins();
}

void 
vfd_clear_all_data_pins()
{
    DISABLE_A;
    DISABLE_B;
    DISABLE_C;
    DISABLE_D;
    DISABLE_E;
    DISABLE_F;
    DISABLE_G;

    DISABLE_SYMB_MAIL;
    DISABLE_SYMB_POWER;
    DISABLE_SYMB_HOUSE;
    DISABLE_SYMB_5_1;
    DISABLE_SYMB_HDTV;
    DISABLE_SYMB_480;
    DISABLE_SYMB_480_i;
    DISABLE_SYMB_480_p;
    DISABLE_SYMB_COLON;
    DISABLE_SYMB_REC;
    DISABLE_SYMB_AUTO;
    DISABLE_SYMB_1080;
    DISABLE_SYMB_720_p;
    DISABLE_SYMB_720;
    DISABLE_SYMB_720_i;
    DISABLE_SYMB_1080_i;
    DISABLE_SYMB_1080_p;
}

void 
vfd_clear_all_select_lines()
{
    UNSELECT_0;
    UNSELECT_1;
    UNSELECT_2;
    UNSELECT_3;
    UNSELECT_4;
}

void 
vfd_set_select_line(vfd_seg_index_t segment)
{
    switch(segment)
    {
        case 0:
            SELECT_0;
            break;
        
        case 1:
            SELECT_1;
            break;
        
        case 2:
            SELECT_2;
            break;
        
        case 3:
            SELECT_3;
            break;
        
        case 4:
            SELECT_4;
            break;
    }
}

void 
vfd_set_symbol(vfd_symbol_flag_t symbol_flags)
{
    if(symbol_flags & SYMB_FLAG_MAIL)
    {
        ENABLE_SYMB_MAIL;
    }

    if(symbol_flags & SYMB_FLAG_POWER)
    {
        ENABLE_SYMB_POWER;
    }

    if(symbol_flags & SYMB_FLAG_HOUSE)
    {
        ENABLE_SYMB_HOUSE;
    }

    if(symbol_flags & SYMB_FLAG_5_1)
    {
        ENABLE_SYMB_5_1;
    }

    if(symbol_flags & SYMB_FLAG_HDTV)
    {
        ENABLE_SYMB_HDTV;
    }

    if(symbol_flags & SYMB_FLAG_480)
    {
        ENABLE_SYMB_480;
    }

    if(symbol_flags & SYMB_FLAG_480_i)
    {
        ENABLE_SYMB_480_i;
    }

    if(symbol_flags & SYMB_FLAG_480_p)
    {
        ENABLE_SYMB_480_p;
    }

    if(symbol_flags & SYMB_FLAG_COLON)
    {
        ENABLE_SYMB_COLON;
    }

    if(symbol_flags & SYMB_FLAG_REC)
    {
        ENABLE_SYMB_REC;
    }

    if(symbol_flags & SYMB_FLAG_AUTO)
    {
        ENABLE_SYMB_AUTO;
    }

    if(symbol_flags & SYMB_FLAG_1080)
    {
        ENABLE_SYMB_1080;
    }

    if(symbol_flags & SYMB_FLAG_720_p)
    {
        ENABLE_SYMB_720_p;
    }

    if(symbol_flags & SYMB_FLAG_720)
    {
        ENABLE_SYMB_720;
    }

    if(symbol_flags & SYMB_FLAG_720_i)
    {
        ENABLE_SYMB_720_i;
    }

    if(symbol_flags & SYMB_FLAG_1080_i)
    {
        ENABLE_SYMB_1080_i;
    }

    if(symbol_flags & SYMB_FLAG_1080_p)
    {
        ENABLE_SYMB_1080_p;
    }
}

void
vfd_set_7_segment(char val)
{
    switch (val)
    {
        case '0':
            ENABLE_A;
            ENABLE_B;
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            break;
        case '1':
            ENABLE_B;
            ENABLE_C;
            break;
        case '2':
            ENABLE_A;
            ENABLE_B;
            ENABLE_D;
            ENABLE_E;
            ENABLE_G;
            break;
        case '3':
            ENABLE_A;
            ENABLE_B;
            ENABLE_C;
            ENABLE_D;
            ENABLE_G;
            break;
        case '4':
            ENABLE_B;
            ENABLE_C;
            ENABLE_F;
            ENABLE_G;
            break;
        case '5':
            ENABLE_A;
            ENABLE_C;
            ENABLE_D;
            ENABLE_F;
            ENABLE_G;
            break;
        case '6':
            ENABLE_A;
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case '7':
            ENABLE_A;
            ENABLE_B;
            ENABLE_C;
            break;
        case '8':
            ENABLE_A;
            ENABLE_B;
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case '9':
            ENABLE_A;
            ENABLE_B;
            ENABLE_C;
            ENABLE_D;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'A':
        case 'a':
            ENABLE_A;
            ENABLE_B;
            ENABLE_C;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'B':
        case 'b':
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'C':
        case 'c':
            ENABLE_A;
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            break;
        case 'D':
        case 'd':
            ENABLE_B;
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            ENABLE_G;
            break;
        case 'E':
        case 'e':
            ENABLE_A;
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'F':
        case 'f':
            ENABLE_A;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'G':
        case 'g':
            ENABLE_A;
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            break;
        case 'H':
        case 'h':
            ENABLE_C;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'I':
        case 'i':
            ENABLE_C;
            break;
        case 'J':
        case 'j':
            ENABLE_B;
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            break;
        case 'K':
        case 'k':
            ENABLE_A;
            ENABLE_C;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'L':
        case 'l':
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            break;
        case 'M':
        case 'm':
            ENABLE_A;
            ENABLE_C;
            ENABLE_E;
            ENABLE_G;
            break;
        case 'N':
        case 'n':
            ENABLE_C;
            ENABLE_E;
            ENABLE_G;
            break;
        case 'O':
        case 'o':
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            ENABLE_G;
            break;
        case 'P':
        case 'p':
            ENABLE_A;
            ENABLE_B;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'Q':
        case 'q':
            ENABLE_A;
            ENABLE_B;
            ENABLE_C;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'R':
        case 'r':
            ENABLE_E;
            ENABLE_G;
            break;
        case 'S':
        case 's':
            ENABLE_A;
            ENABLE_C;
            ENABLE_D;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'T':
        case 't':
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'U':
        case 'u':
            ENABLE_B;
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            ENABLE_F;
            break;
        case 'V':
        case 'v':
            ENABLE_C;
            ENABLE_D;
            ENABLE_E;
            break;
        case 'W':
        case 'w':
            ENABLE_B;
            ENABLE_D;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'X':
        case 'x':
            ENABLE_C;
            ENABLE_E;
            break;
        case 'Y':
        case 'y':
            ENABLE_B;
            ENABLE_C;
            ENABLE_D;
            ENABLE_F;
            ENABLE_G;
            break;
        case 'Z':
        case 'z':
            ENABLE_A;
            ENABLE_B;
            ENABLE_D;
            ENABLE_E;
            break;
        case '-':
            ENABLE_G;
            break;
        case '\0':
            // null character switches the vfd character off
            DISABLE_A;
            DISABLE_B;
            DISABLE_C;
            DISABLE_D;
            DISABLE_E;
            DISABLE_F;
            DISABLE_G;
            break;
        default:
            // TODO: some return value indicating error
            break;
    }
}