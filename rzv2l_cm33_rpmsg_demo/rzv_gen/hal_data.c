/* generated HAL source file - do not edit */
#include "hal_data.h"
cru_instance_ctrl_t g_cru_for_exposure_ctrl;

cru_buffer_address_t g_cru_for_exposure_buffer_addr =
{ .p_buffer0 = (uint8_t*) (0xA1000000),
  .p_buffer1 = (uint8_t*) (0xA1400000),
  .p_buffer2 = (uint8_t*) (0xA1800000),
  .p_buffer3 = (uint8_t*) (0xA1C00000),
  .p_buffer4 = (uint8_t*) (0xA2000000),
  .p_buffer5 = (uint8_t*) (0xA2400000),
  .p_buffer6 = (uint8_t*) (0xA2800000),
  .p_buffer7 = (uint8_t*) (0xA2C00000), };

const cru_cfg_t g_cru_for_exposure_cfg =
{ .p_callback = cru_callback,
  .p_context = NULL,
  .input_format = CRU_INPUT_FORMAT_YUV422_8BIT,
  .output_format = CRU_OUTPUT_FORMAT_YUV422_UYVY,
  .width = CRU_W1920,
  .height = CRU_H1080,
  .datalane = CRU_DATALANE_2,
  .mbvalid = CRU_1_MB_VALID,
  .cycle_end_ipl = 24,
  .p_buffer_addr = &g_cru_for_exposure_buffer_addr, };

cru_instance_t g_cru_for_exposure =
{ .p_ctrl = &g_cru_for_exposure_ctrl, .p_cfg = &g_cru_for_exposure_cfg, .p_api = &g_cru_on_cru };
iic_master_instance_ctrl_t g_i2c_master_for_ov5645_ctrl;
const riic_master_extended_cfg_t g_i2c_master_for_ov5645_extend =
{ .timeout_mode = IIC_MASTER_TIMEOUT_MODE_SHORT,
  /* Actual calculated bitrate: 396825. Actual calculated duty cycle: 51%. */.clock_settings.brl_value = 25,
  .clock_settings.brh_value = 26,
  .clock_settings.cks_value = 2,
  .noise_filter_stage = 1,
  .naki_irq = RIIC0_NAKI_IRQn,
  .spi_irq = RIIC0_SPI_IRQn,
  .sti_irq = RIIC0_STI_IRQn,
  .ali_irq = RIIC0_ALI_IRQn,
  .tmoi_irq = RIIC0_TMOI_IRQn, };
const i2c_master_cfg_t g_i2c_master_for_ov5645_cfg =
{ .channel = 0,
  .rate = I2C_MASTER_RATE_FAST,
  .slave = 0x3c,
  .addr_mode = I2C_MASTER_ADDR_MODE_7BIT,
#define FSP_NOT_DEFINED (1)
#undef FSP_NOT_DEFINED
  .p_callback = i2c_callback,
  .p_context = NULL,
  .rxi_irq = RIIC0_RI_IRQn,
  .txi_irq = RIIC0_TI_IRQn,
  .tei_irq = RIIC0_TEI_IRQn,
  .ipl = 12,
  .p_extend = &g_i2c_master_for_ov5645_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_master_for_ov5645 =
{ .p_ctrl = &g_i2c_master_for_ov5645_ctrl, .p_cfg = &g_i2c_master_for_ov5645_cfg, .p_api = &g_i2c_master_on_iic };
rm_ov5645_instance_ctrl_t g_ov5645_sensor0_ctrl;

const rm_ovxxxx_cfg_t g_ov5645_sensor0_cfg =
{ .p_i2c_instance = &g_i2c_master_for_ov5645, };

const rm_ovxxxx_instance_t g_ov5645_sensor0 =
{ .p_ctrl = &g_ov5645_sensor0_ctrl, .p_cfg = &g_ov5645_sensor0_cfg, .p_api = &g_ovxxxx_on_ov5645, };
rm_exposure_control_instance_ctrl_t g_exposure_ctl0_ctrl;

const rm_exposure_control_cfg_t g_exposure_ctl0_cfg =
{ .p_ov5645_instance = &g_ov5645_sensor0, .p_cru_instance = &g_cru_for_exposure, .p_context = NULL, .p_extend = NULL, };

const rm_exposure_control_instance_t g_exposure_ctl0 =
{ .p_ctrl = &g_exposure_ctl0_ctrl, .p_cfg = &g_exposure_ctl0_cfg, .p_api = &g_exposure_control_on_exposure_control, };
scif_uart_instance_ctrl_t g_uart2_ctrl;

scif_baud_setting_t g_uart2_baud_setting =
{
/* Baud rate calculated with 0.469% error. */.abcs = 0,
  .bgdm = 1, .cks = 0, .brr = 53, .mddr = (uint8_t) 256, .brme = false };

/** UART extended configuration for UARTonSCIF HAL driver */
const scif_uart_extended_cfg_t g_uart2_cfg_extend =
{ .bri_ipl = 14, .bri_irq = SCIF2_BRK_IRQn, .clock = SCIF_UART_CLOCK_INT, .noise_cancel =
          SCIF_UART_NOISE_CANCELLATION_DISABLE,
  .p_baud_setting = &g_uart2_baud_setting, .rx_fifo_trigger = SCIF_UART_RECEIVE_TRIGGER_MAX, .rts_fifo_trigger =
          SCIF_UART_RTS_TRIGGER_14,
  .uart_mode = SCIF_UART_MODE_RS232, .flow_control = SCIF_UART_FLOW_CONTROL_NONE, .driver_enable_pin =
          (bsp_io_port_pin_t) SCIF_UART_INVALID_16BIT_PARAM, };

/** UART interface configuration */
const uart_cfg_t g_uart2_cfg =
{ .channel = 2,
  .data_bits = UART_DATA_BITS_8,
  .parity = UART_PARITY_OFF,
  .stop_bits = UART_STOP_BITS_1,
  .p_callback = NULL,
  .p_context = NULL,
  .p_extend = &g_uart2_cfg_extend,
  .p_transfer_tx = NULL,
  .p_transfer_rx = NULL,
  .rxi_ipl = 14,
  .txi_ipl = 14,
  .tei_ipl = 14,
  .eri_ipl = 14,
  .rxi_irq = SCIF2_RXI_IRQn,
  .txi_irq = SCIF2_TXI_IRQn,
  .tei_irq = SCIF2_TEI_DRI_IRQn,
  .eri_irq = SCIF2_RERR_IRQn, };

/* Instance structure to use this module. */
const uart_instance_t g_uart2 =
{ .p_ctrl = &g_uart2_ctrl, .p_cfg = &g_uart2_cfg, .p_api = &g_uart_on_scif };
mhu_ns_instance_ctrl_t g_mhu_ns0_ctrl;
const mhu_cfg_t g_mhu_ns0_cfg =
{ .channel = 3, .rx_ipl = 12, .rx_irq = MHU_MSG3_NS_IRQn, .p_callback = NULL, .p_shared_memory = 0, .p_context = NULL, };
/* Instance structure to use this module. */
const mhu_instance_t g_mhu_ns0 =
{ .p_ctrl = &g_mhu_ns0_ctrl, .p_cfg = &g_mhu_ns0_cfg, .p_api = &g_mhu_ns_on_mhu_ns };
gtm_instance_ctrl_t g_timer2_ctrl;
const gtm_extended_cfg_t g_timer2_extend =
{ .generate_interrupt_when_starts = GTM_GIWS_TYPE_DISABLED, .gtm_mode = GTM_TIMER_MODE_INTERVAL, };
const timer_cfg_t g_timer2_cfg =
{ .mode = TIMER_MODE_PERIODIC, .period_counts = 100000 /* Actual period: 0.001 seconds. */, .channel = 2, .p_callback =
          NULL,
  .p_context = NULL, .cycle_end_ipl = 255, .p_extend = &g_timer2_extend,
#if defined(VECTOR_NUMBER_GTM2_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GTM2_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = GTM2_OSTM2INT_IRQn,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t g_timer2 =
{ .p_ctrl = &g_timer2_ctrl, .p_cfg = &g_timer2_cfg, .p_api = &g_timer_on_gtm };
void g_hal_init(void)
{
    g_common_init ();
}
