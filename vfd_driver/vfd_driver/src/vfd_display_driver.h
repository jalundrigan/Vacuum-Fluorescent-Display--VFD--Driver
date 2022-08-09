#ifndef _VFD_DISPLAY_DRIVER_H_
#define _VFD_DISPLAY_DRIVER_H_

#include "vfd_pin_driver.h"

typedef enum vfd_return_status_t
{
    VFD_STATUS_FAIL,
    VFD_STATUS_OK
} vfd_return_status_t;

typedef struct vfd_state_t
{
    vfd_seg_index_t current_segment;
    char char_buf[4];
    vfd_symbol_flag_t symbol_flags;
} vfd_state_t;


void vfd_init();
vfd_return_status_t vfd_set_characters(const char *buf);
vfd_return_status_t vfd_display_update_callback();

/*
    TODO: Does this need to have the weak declaration as well?
*/
void vfd_data_error_handler(vfd_state_t *vfd_error_state);

void vfd_enable_symbols_from_flags(uint32_t flags);

void vfd_enable_mail_symbol();
void vfd_enable_power_symbol();
void vfd_enable_house_symbol();
void vfd_enable_5_1_symbol();
void vfd_enable_hdtv_symbol();
void vfd_enable_480_symbol();
void vfd_enable_480_i_symbol();
void vfd_enable_480_p_symbol();
void vfd_enable_colon_symbol();
void vfd_enable_rec_symbol();
void vfd_enable_auto_symbol();
void vfd_enable_1080_symbol();
void vfd_enable_720_p_symbol();
void vfd_enable_720_symbol();
void vfd_enable_720_i_symbol();
void vfd_enable_1080_i_symbol();
void vfd_enable_1080_p_symbol();
void vfd_disable_mail_symbol();
void vfd_disable_power_symbol();
void vfd_disable_house_symbol();
void vfd_disable_5_1_symbol();
void vfd_disable_hdtv_symbol();
void vfd_disable_480_symbol();
void vfd_disable_480_i_symbol();
void vfd_disable_480_p_symbol();
void vfd_disable_colon_symbol();
void vfd_disable_rec_symbol();
void vfd_disable_auto_symbol();
void vfd_disable_1080_symbol();
void vfd_disable_720_p_symbol();
void vfd_disable_720_symbol();
void vfd_disable_720_i_symbol();
void vfd_disable_1080_i_symbol();
void vfd_disable_1080_p_symbol();


#endif /*   _VFD_DISPLAY_DRIVER_H_  */