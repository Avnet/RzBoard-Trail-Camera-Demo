/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_cru.h"
#include "r_cru_api.h"
#include "r_riic_master.h"
#include "r_i2c_master_api.h"
#include "rm_ov5645.h"
#include "rm_ovxxxx_api.h"
#include "rm_exposure_control.h"
#include "rm_exposure_control_api.h"
#include "r_uart_api.h"
#include "r_scif_uart.h"
#include "r_mhu_ns.h"
#include "r_gtm.h"
FSP_HEADER
extern cru_instance_t g_cru_for_exposure;
extern cru_instance_ctrl_t g_cru_for_exposure_ctrl;
extern const cru_cfg_t g_cru_for_exposure_cfg;
#ifndef cru_callback
void cru_callback(cru_callback_args_t *p_args);
#endif
/* I2C Master on RIIC Instance. */
extern const i2c_master_instance_t g_i2c_master_for_ov5645;

/** Access the I2C Master instance using these structures when calling API functions directly (::p_api is not used). */
extern iic_master_instance_ctrl_t g_i2c_master_for_ov5645_ctrl;
extern const i2c_master_cfg_t g_i2c_master_for_ov5645_cfg;

#ifndef i2c_callback
void i2c_callback(i2c_master_callback_args_t *p_args);
#endif
/* OV5645 Sensor */
extern const rm_ovxxxx_instance_t g_ov5645_sensor0;
extern rm_ov5645_instance_ctrl_t g_ov5645_sensor0_ctrl;
extern const rm_ovxxxx_cfg_t g_ov5645_sensor0_cfg;
/* Exposure Control */
extern const rm_exposure_control_instance_t g_exposure_ctl0;
extern rm_exposure_control_instance_ctrl_t g_exposure_ctl0_ctrl;
extern const rm_exposure_control_cfg_t g_exposure_ctl0_cfg;
/** UART on SCIF Instance. */
extern const uart_instance_t g_uart2;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern scif_uart_instance_ctrl_t g_uart2_ctrl;
extern const uart_cfg_t g_uart2_cfg;
extern const scif_uart_extended_cfg_t g_uart2_cfg_extend;

#ifndef NULL
void NULL(uart_callback_args_t *p_args);
#endif
/** MHU Instance */
extern const mhu_instance_t g_mhu_ns0;

/** Access the MHU instance using these structures when calling API functions directly (::p_api is not used). */
extern mhu_ns_instance_ctrl_t g_mhu_ns0_ctrl;
extern const mhu_cfg_t g_mhu_ns0_cfg;

#ifndef NULL
void NULL(mhu_callback_args_t *p_args);
#endif
/** GTM Timer Instance */
extern const timer_instance_t g_timer2;

/** Access the GTM instance using these structures when calling API functions directly (::p_api is not used). */
extern gtm_instance_ctrl_t g_timer2_ctrl;
extern const timer_cfg_t g_timer2_cfg;

#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
