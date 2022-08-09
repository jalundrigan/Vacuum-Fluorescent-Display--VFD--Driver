#ifndef _VFD_PIN_DRIVER_H_
#define _VFD_PIN_DRIVER_H_

#include <avr/io.h>

typedef uint32_t vfd_symbol_flag_t;
typedef uint8_t vfd_seg_index_t;

void vfd_init_pins();
void vfd_clear_all_data_pins();
void vfd_clear_all_select_lines();
void vfd_set_select_line(vfd_seg_index_t segment);
void vfd_set_symbol(vfd_symbol_flag_t symbol_flags);
void vfd_set_7_segment(char val);


/*
    ==================== Line select ====================
*/

/*
    Line select ports
*/
#define SEL_0_PORT    PORTC
#define SEL_1_PORT    PORTC
#define SEL_2_PORT    PORTC
#define SEL_3_PORT    PORTC
#define SEL_4_PORT    PORTB

/*
    Line select pins
*/
#define SEL_0         PORTC0
#define SEL_1         PORTC1
#define SEL_2         PORTC2
#define SEL_3         PORTC3
#define SEL_4         PORTB0

/*
    Line select config registers
*/
#define SEL_0_CFG_REG    DDRC
#define SEL_1_CFG_REG    DDRC
#define SEL_2_CFG_REG    DDRC
#define SEL_3_CFG_REG    DDRC
#define SEL_4_CFG_REG    DDRB

/*
    Line select config register indices
*/
#define SEL_0_CFG_IND         DDC0
#define SEL_1_CFG_IND         DDC1
#define SEL_2_CFG_IND         DDC2
#define SEL_3_CFG_IND         DDC3
#define SEL_4_CFG_IND         DDB0


/*
    ==================== 7-segment ====================
*/

/*
    7-segment ports 
*/
#define SEG_A_PORT  PORTD
#define SEG_B_PORT  PORTD
#define SEG_C_PORT  PORTD
#define SEG_D_PORT  PORTD
#define SEG_E_PORT  PORTD
#define SEG_F_PORT  PORTD
#define SEG_G_PORT  PORTD

/*
    7-segment pins 
*/
#define SEG_A       PORTD0
#define SEG_B       PORTD1
#define SEG_C       PORTD2
#define SEG_D       PORTD3
#define SEG_E       PORTD4
#define SEG_F       PORTD5
#define SEG_G       PORTD6

/*
    7-segment config registers 
*/
#define SEG_A_CFG_REG  DDRD
#define SEG_B_CFG_REG  DDRD
#define SEG_C_CFG_REG  DDRD
#define SEG_D_CFG_REG  DDRD
#define SEG_E_CFG_REG  DDRD
#define SEG_F_CFG_REG  DDRD
#define SEG_G_CFG_REG  DDRD

/*
    7-segment config register indices 
*/
#define SEG_A_CFG_IND  DDD0
#define SEG_B_CFG_IND  DDD1
#define SEG_C_CFG_IND  DDD2
#define SEG_D_CFG_IND  DDD3
#define SEG_E_CFG_IND  DDD4
#define SEG_F_CFG_IND  DDD5
#define SEG_G_CFG_IND  DDD6


/*
    ==================== Symbols ====================
*/

/*
    Symbol ports
*/
#define SYMB_MAIL_PORT      PORTB
#define SYMB_POWER_PORT     PORTC
#define SYMB_HOUSE_PORT     PORTB
#define SYMB_5_1_PORT       PORTB
#define SYMB_HDTV_PORT      PORTB
#define SYMB_480_PORT       PORTB
#define SYMB_480_i_PORT     PORTB
#define SYMB_480_p_PORT     PORTB
#define SYMB_COLON_PORT     PORTD
#define SYMB_REC_PORT       PORTD
#define SYMB_AUTO_PORT      PORTD
#define SYMB_1080_PORT      PORTD
#define SYMB_720_p_PORT     PORTD
#define SYMB_720_PORT       PORTD
#define SYMB_720_i_PORT     PORTD
#define SYMB_1080_i_PORT    PORTD
#define SYMB_1080_p_PORT    PORTD

/*
    Symbol pins
*/
#define SYMB_MAIL           PORTB0
#define SYMB_POWER          PORTC7
#define SYMB_HOUSE          PORTB2
#define SYMB_5_1            PORTB3
#define SYMB_HDTV           PORTB4
#define SYMB_480            PORTB5
#define SYMB_480_i          PORTB6
#define SYMB_480_p          PORTB7
#define SYMB_COLON          PORTD7
#define SYMB_REC            PORTD7
#define SYMB_AUTO           PORTD0
#define SYMB_1080           PORTD1
#define SYMB_720_p          PORTD2
#define SYMB_720            PORTD3
#define SYMB_720_i          PORTD4
#define SYMB_1080_i         PORTD5
#define SYMB_1080_p         PORTD6

/*
    Symbol ports config registers
*/
#define SYMB_MAIL_CFG_REG      DDRB
#define SYMB_POWER_CFG_REG     DDRC
#define SYMB_HOUSE_CFG_REG     DDRB
#define SYMB_5_1_CFG_REG       DDRB
#define SYMB_HDTV_CFG_REG      DDRB
#define SYMB_480_CFG_REG       DDRB
#define SYMB_480_i_CFG_REG     DDRB
#define SYMB_480_p_CFG_REG     DDRB
#define SYMB_COLON_CFG_REG     DDRD
#define SYMB_REC_CFG_REG       DDRD
#define SYMB_AUTO_CFG_REG      DDRD
#define SYMB_1080_CFG_REG      DDRD
#define SYMB_720_p_CFG_REG     DDRD
#define SYMB_720_CFG_REG       DDRD
#define SYMB_720_i_CFG_REG     DDRD
#define SYMB_1080_i_CFG_REG    DDRD
#define SYMB_1080_p_CFG_REG    DDRD

/*
    Symbol ports config register indices
*/
#define SYMB_MAIL_CFG_IND      DDB0
#define SYMB_POWER_CFG_IND     DDC7
#define SYMB_HOUSE_CFG_IND     DDB2
#define SYMB_5_1_CFG_IND       DDB3
#define SYMB_HDTV_CFG_IND      DDB4
#define SYMB_480_CFG_IND       DDB5
#define SYMB_480_i_CFG_IND     DDB6
#define SYMB_480_p_CFG_IND     DDB7
#define SYMB_COLON_CFG_IND     DDD7
#define SYMB_REC_CFG_IND       DDD7
#define SYMB_AUTO_CFG_IND      DDD0
#define SYMB_1080_CFG_IND      DDD1
#define SYMB_720_p_CFG_IND     DDD2
#define SYMB_720_CFG_IND       DDD3
#define SYMB_720_i_CFG_IND     DDD4
#define SYMB_1080_i_CFG_IND    DDD5
#define SYMB_1080_p_CFG_IND    DDD6

/*
    ==================== Basic DIO ====================
*/

/*
    Line select enable
*/
#define SELECT_0 (SEL_0_PORT |= (1 << SEL_0))
#define SELECT_1 (SEL_1_PORT |= (1 << SEL_1))
#define SELECT_2 (SEL_2_PORT |= (1 << SEL_2))
#define SELECT_3 (SEL_3_PORT |= (1 << SEL_3))
#define SELECT_4 (SEL_4_PORT |= (1 << SEL_4))

/*
    Line select disable
*/
#define UNSELECT_0 (SEL_0_PORT &= ~(1 << SEL_0))
#define UNSELECT_1 (SEL_1_PORT &= ~(1 << SEL_1))
#define UNSELECT_2 (SEL_2_PORT &= ~(1 << SEL_2))
#define UNSELECT_3 (SEL_3_PORT &= ~(1 << SEL_3))
#define UNSELECT_4 (SEL_4_PORT &= ~(1 << SEL_4))

/*
    Line select output enable
*/
#define SEL_0_OUT_EN (SEL_0_CFG_REG |= (1 << SEL_0_CFG_IND))
#define SEL_1_OUT_EN (SEL_1_CFG_REG |= (1 << SEL_1_CFG_IND))
#define SEL_2_OUT_EN (SEL_2_CFG_REG |= (1 << SEL_2_CFG_IND))
#define SEL_3_OUT_EN (SEL_3_CFG_REG |= (1 << SEL_3_CFG_IND))
#define SEL_4_OUT_EN (SEL_4_CFG_REG |= (1 << SEL_4_CFG_IND))

/*
    7-segment segment enable
*/
#define ENABLE_A (SEG_A_PORT &= ~(1 << SEG_A))
#define ENABLE_B (SEG_B_PORT &= ~(1 << SEG_B))
#define ENABLE_C (SEG_C_PORT &= ~(1 << SEG_C))
#define ENABLE_D (SEG_D_PORT &= ~(1 << SEG_D))
#define ENABLE_E (SEG_E_PORT &= ~(1 << SEG_E))
#define ENABLE_F (SEG_F_PORT &= ~(1 << SEG_F))
#define ENABLE_G (SEG_G_PORT &= ~(1 << SEG_G))

/*
    7-segment segment disable
*/
#define DISABLE_A (SEG_A_PORT |= (1 << SEG_A))
#define DISABLE_B (SEG_B_PORT |= (1 << SEG_B))
#define DISABLE_C (SEG_C_PORT |= (1 << SEG_C))
#define DISABLE_D (SEG_D_PORT |= (1 << SEG_D))
#define DISABLE_E (SEG_E_PORT |= (1 << SEG_E))
#define DISABLE_F (SEG_F_PORT |= (1 << SEG_F))
#define DISABLE_G (SEG_G_PORT |= (1 << SEG_G))

/*
    7-segment segment output enable
*/
#define A_OUT_EN (SEG_A_CFG_REG |= (1 << SEG_A_CFG_IND))
#define B_OUT_EN (SEG_B_CFG_REG |= (1 << SEG_B_CFG_IND))
#define C_OUT_EN (SEG_C_CFG_REG |= (1 << SEG_C_CFG_IND))
#define D_OUT_EN (SEG_D_CFG_REG |= (1 << SEG_D_CFG_IND))
#define E_OUT_EN (SEG_E_CFG_REG |= (1 << SEG_E_CFG_IND))
#define F_OUT_EN (SEG_F_CFG_REG |= (1 << SEG_F_CFG_IND))
#define G_OUT_EN (SEG_G_CFG_REG |= (1 << SEG_G_CFG_IND))

/*
    Symbol enable
*/
#define ENABLE_SYMB_MAIL        //(SYMB_MAIL_PORT &= ~(1 << SYMB_MAIL))
#define ENABLE_SYMB_POWER       (SYMB_POWER_PORT &= ~(1 << SYMB_POWER))
#define ENABLE_SYMB_HOUSE       (SYMB_HOUSE_PORT &= ~(1 << SYMB_HOUSE))
#define ENABLE_SYMB_5_1         (SYMB_5_1_PORT &= ~(1 << SYMB_5_1))
#define ENABLE_SYMB_HDTV        (SYMB_HDTV_PORT &= ~(1 << SYMB_HDTV))
#define ENABLE_SYMB_480         (SYMB_480_PORT &= ~(1 << SYMB_480))
#define ENABLE_SYMB_480_i       (SYMB_480_i_PORT &= ~(1 << SYMB_480_i))
#define ENABLE_SYMB_480_p       (SYMB_480_p_PORT &= ~(1 << SYMB_480_p))
#define ENABLE_SYMB_COLON       (SYMB_COLON_PORT &= ~(1 << SYMB_COLON))
#define ENABLE_SYMB_REC         (SYMB_REC_PORT &= ~(1 << SYMB_REC))
#define ENABLE_SYMB_AUTO        (SYMB_AUTO_PORT &= ~(1 << SYMB_AUTO))
#define ENABLE_SYMB_1080        (SYMB_1080_PORT &= ~(1 << SYMB_1080))
#define ENABLE_SYMB_720_p       (SYMB_720_p_PORT &= ~(1 << SYMB_720_p))
#define ENABLE_SYMB_720         (SYMB_720_PORT &= ~(1 << SYMB_720))
#define ENABLE_SYMB_720_i       (SYMB_720_i_PORT &= ~(1 << SYMB_720_i))
#define ENABLE_SYMB_1080_i      (SYMB_1080_i_PORT &= ~(1 << SYMB_1080_i))
#define ENABLE_SYMB_1080_p      (SYMB_1080_p_PORT &= ~(1 << SYMB_1080_p))

/*
    Symbol disable
*/
#define DISABLE_SYMB_MAIL         (SYMB_MAIL_PORT |= (1 << SYMB_MAIL))
#define DISABLE_SYMB_POWER        (SYMB_POWER_PORT |= (1 << SYMB_POWER))
#define DISABLE_SYMB_HOUSE        (SYMB_HOUSE_PORT |= (1 << SYMB_HOUSE))
#define DISABLE_SYMB_5_1          (SYMB_5_1_PORT |= (1 << SYMB_5_1))
#define DISABLE_SYMB_HDTV         (SYMB_HDTV_PORT |= (1 << SYMB_HDTV))
#define DISABLE_SYMB_480          (SYMB_480_PORT |= (1 << SYMB_480))
#define DISABLE_SYMB_480_i        (SYMB_480_i_PORT |= (1 << SYMB_480_i))
#define DISABLE_SYMB_480_p        (SYMB_480_p_PORT |= (1 << SYMB_480_p))
#define DISABLE_SYMB_COLON        (SYMB_COLON_PORT |= (1 << SYMB_COLON))
#define DISABLE_SYMB_REC          (SYMB_REC_PORT |= (1 << SYMB_REC))
#define DISABLE_SYMB_AUTO         (SYMB_AUTO_PORT |= (1 << SYMB_AUTO))
#define DISABLE_SYMB_1080         (SYMB_1080_PORT |= (1 << SYMB_1080))
#define DISABLE_SYMB_720_p        (SYMB_720_p_PORT |= (1 << SYMB_720_p))
#define DISABLE_SYMB_720          (SYMB_720_PORT |= (1 << SYMB_720))
#define DISABLE_SYMB_720_i        (SYMB_720_i_PORT |= (1 << SYMB_720_i))
#define DISABLE_SYMB_1080_i       (SYMB_1080_i_PORT |= (1 << SYMB_1080_i))
#define DISABLE_SYMB_1080_p       (SYMB_1080_p_PORT |= (1 << SYMB_1080_p))

/*
    Symbol output enable
*/
#define SYMB_MAIL_OUT_EN         (SYMB_MAIL_CFG_REG |= (1 << SYMB_MAIL_CFG_IND))
#define SYMB_POWER_OUT_EN        (SYMB_POWER_CFG_REG |= (1 << SYMB_POWER_CFG_IND))
#define SYMB_HOUSE_OUT_EN        (SYMB_HOUSE_CFG_REG |= (1 << SYMB_HOUSE_CFG_IND))
#define SYMB_5_1_OUT_EN          (SYMB_5_1_CFG_REG |= (1 << SYMB_5_1_CFG_IND))
#define SYMB_HDTV_OUT_EN         (SYMB_HDTV_CFG_REG |= (1 << SYMB_HDTV_CFG_IND))
#define SYMB_480_OUT_EN          (SYMB_480_CFG_REG |= (1 << SYMB_480_CFG_IND))
#define SYMB_480_i_OUT_EN        (SYMB_480_i_CFG_REG |= (1 << SYMB_480_i_CFG_IND))
#define SYMB_480_p_OUT_EN        (SYMB_480_p_CFG_REG |= (1 << SYMB_480_p_CFG_IND))
#define SYMB_COLON_OUT_EN        (SYMB_COLON_CFG_REG |= (1 << SYMB_COLON_CFG_IND))
#define SYMB_REC_OUT_EN          (SYMB_REC_CFG_REG |= (1 << SYMB_REC_CFG_IND))
#define SYMB_AUTO_OUT_EN         (SYMB_AUTO_CFG_REG |= (1 << SYMB_AUTO_CFG_IND))
#define SYMB_1080_OUT_EN         (SYMB_1080_CFG_REG |= (1 << SYMB_1080_CFG_IND))
#define SYMB_720_p_OUT_EN        (SYMB_720_p_CFG_REG |= (1 << SYMB_720_p_CFG_IND))
#define SYMB_720_OUT_EN          (SYMB_720_CFG_REG |= (1 << SYMB_720_CFG_IND))
#define SYMB_720_i_OUT_EN        (SYMB_720_i_CFG_REG |= (1 << SYMB_720_i_CFG_IND))
#define SYMB_1080_i_OUT_EN       (SYMB_1080_i_CFG_REG |= (1 << SYMB_1080_i_CFG_IND))
#define SYMB_1080_p_OUT_EN       (SYMB_1080_p_CFG_REG |= (1 << SYMB_1080_p_CFG_IND))

/*
    ==================== Flags ====================
*/

/*
    Symbol flags
*/
#define SYMB_FLAG_MAIL          ((vfd_symbol_flag_t)1 << 0)
#define SYMB_FLAG_POWER         ((vfd_symbol_flag_t)1 << 1)
#define SYMB_FLAG_HOUSE         ((vfd_symbol_flag_t)1 << 2)
#define SYMB_FLAG_5_1           ((vfd_symbol_flag_t)1 << 3)
#define SYMB_FLAG_HDTV          ((vfd_symbol_flag_t)1 << 4)
#define SYMB_FLAG_480           ((vfd_symbol_flag_t)1 << 5)
#define SYMB_FLAG_480_i         ((vfd_symbol_flag_t)1 << 6)
#define SYMB_FLAG_480_p         ((vfd_symbol_flag_t)1 << 7)
#define SYMB_FLAG_COLON         ((vfd_symbol_flag_t)1 << 8)
#define SYMB_FLAG_REC           ((vfd_symbol_flag_t)1 << 9)
#define SYMB_FLAG_AUTO          ((vfd_symbol_flag_t)1 << 10)
#define SYMB_FLAG_1080          ((vfd_symbol_flag_t)1 << 11)
#define SYMB_FLAG_720_p         ((vfd_symbol_flag_t)1 << 12)
#define SYMB_FLAG_720           ((vfd_symbol_flag_t)1 << 13)
#define SYMB_FLAG_720_i         ((vfd_symbol_flag_t)1 << 14)
#define SYMB_FLAG_1080_i        ((vfd_symbol_flag_t)1 << 15)
#define SYMB_FLAG_1080_p        ((vfd_symbol_flag_t)1 << 16)


#endif /*   _VFD_PIN_DRIVER_H_  */