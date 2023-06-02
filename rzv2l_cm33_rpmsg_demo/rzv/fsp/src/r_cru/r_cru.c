/***********************************************************************************************************************
 * Copyright [2020-2022] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_cru.h"
#include "r_cru_cfg.h"
#include "FreeRTOS.h"
#include "task.h"
#include "platform_info.h"


/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define CRU_OPEN                 (0x435255) /* "CRU" in Hex */

/* LINK registers */
/* Module Configuration Register */
#define CSI2nMCG			0x0

/* Module Control Register 0 */
//#define CSI2nMCT0			0x10
#define CSI2nMCT0_VDLN(x)		((x) << 0)

/* Module Control Register 2 */
//#define CSI2nMCT2			0x18
#define CSI2nMCT2_FRRSKW(x)		((x) << 16)
#define CSI2nMCT2_FRRCLK(x)		((x) << 0)

/* Module Control Register 3 */
//#define CSI2nMCT3			0x1C
#define CSI2nMCT3_RXEN			1

/* Reset Control Register */
#define CSI2nRTCT			0x28
#define CSI2nRTCT_VSRST			1

/* Reset Status Register */
#define CSI2nRTST			0x2C
#define CSI2nRTST_VSRSTS		1

/* Receive Data Type Enable Low Register */
#define CSI2nDTEL_value			0x60

/* Receive Data Type Enable High Register */
#define CSI2nDTEH_value			0x64

/* DPHY registers */
/* D-PHY Control Register 0 */
//#define CSIDPHYCTRL0			0x400
#define CSIDPHYCTRL0_EN_LDO1200		1
#define CSIDPHYCTRL0_EN_BGR		1

/* D-PHY Timing Register 0 */
#define CSIDPHYTIM0_value			0x404
#define CSIDPHYTIM0_TCLK_MISS(x)	((x) << 24)
#define CSIDPHYTIM0_T_INIT(x)		((x) << 0)

/* D-PHY Timing Register 1 */
#define CSIDPHYTIM1_value			0x408
#define CSIDPHYTIM1_THS_PREPARE(x)	((x) << 24)
#define CSIDPHYTIM1_TCLK_PREPARE(x)	((x) << 16)
#define CSIDPHYTIM1_THS_SETTLE(x)	((x) << 8)
#define CSIDPHYTIM1_TCLK_SETTLE(x)	((x) << 0)
#define STOPPED 0
#define STARTING 1
#define RUNNING 2
#define STOPPING 3
#define CSI2_DPHYTIM0    (0x040137B9)
#define CSI2_DPHYTIM1    (0x0A0A1212)
#define CSI2_DPHYSKW0    (0x00001111)
#define CSI2_MCT2        (0x00220011)
#define CSI2_DTEL        (0xF778FF0F)
#define CSI2_DTEH        (0x00FFFF1F)
#define CAST_TO_UINT32                 (0xFFFFFFFFU)
#define CAST_TO_UINT13                 (0x1FFFU)
#define CAST_TO_UINT12                 (0xFFFU)
#define CAST_TO_UINT9                  (0x1FFU)
#define CAST_TO_UINT6                  (0x3FU)
#define CAST_TO_UINT4                  (0xFU)
#define CAST_TO_UINT3                  (0x7U)
#define CAST_TO_UINT2                  (0x3U)
#define CAST_TO_UINT1                  (0x1U)
#define REGVAL_ICnCSCC1 (0x0000129F)
#define REGVAL_ICnCSCC2 (0x01000800)
#define REGVAL_ICnCSCC3 (0x19890D02)
#define REGVAL_ICnCSCC4 (0x06452045)
#define REGVAL_ICnYCCR1 (0x00000107)
#define REGVAL_ICnYCCR2 (0x00640204)
#define REGVAL_ICnYCCR3 (0x0A000100)
#define REGVAL_ICnCBCCR1 (0x00001F68)
#define REGVAL_ICnCBCCR2 (0x01C21ED6)
#define REGVAL_ICnCBCCR3 (0x0A000800)
#define REGVAL_ICnCRCCR1 (0x000001C2)
#define REGVAL_ICnCRCCR2 (0x1FB71E87)
#define REGVAL_ICnCRCCR3 (0x0A000800)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

static const uint8_t capture_input_format[] =
{
     0x18,  /* YUV420 8bit  */
     0x19,  /* YUV420 10bit */
     0x1E,  /* YUV422 8bit  */
     0x1F,  /* YUV422 10bit */
     0x22,  /* RGB565       */
     0x24,  /* RGB888       */
     0x2A,  /* RAW8         */
     0x2B,  /* RAW10        */
     0x2C,  /* RAW12        */
     0x2D,  /* RAW14        */
};

/* This table values are written to CRU register */
static const uint8_t capture_output_format[] =
{
    0x4,      /* YUYV (YUV420) */
    0x5,      /* UYVY (YUV420) */
    0x0,      /* YUYV (YUV422) */
    0x1,      /* UYVY (YUV422) */
    0x3,      /* Y             */
    0x2,      /* YC separation */
    0x0,      /* RGB888 24bit  */
    0x1,      /* RGB888 32bit  */   ///< Upper 8bit : 0x00
    0x3,      /* RGB888 32bit  */   ///< A-R-G-B
    0x2,      /* RGB888 32bit  */   ///< B-G-R-A
};

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
fsp_err_t rzg2l_csi2_stop(cru_instance_ctrl_t *p_ctrl);
fsp_err_t rzg2l_csi2_dphy_setting(cru_instance_ctrl_t *p_ctrl, uint8_t on);

void r_cru_set_slot_addr(cru_instance_ctrl_t *p_ctrl, int32_t slot, uint32_t addr);
void r_cru_initialize_axi(cru_instance_ctrl_t *p_ctrl);
fsp_err_t r_cru_initialize_image_conv(cru_instance_ctrl_t *p_ctrl);
static void r_cru_mipi_link_set(cru_instance_ctrl_t *p_ctrl);
static void r_cru_link_packet_stop(cru_instance_ctrl_t *p_ctrl);
static void r_cru_dphy_stop(cru_instance_ctrl_t *p_ctrl);
static void r_cru_stop_image_processing(cru_instance_ctrl_t *p_ctrl);


/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
void cru_int_isr(void);

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* CSI2 function pointers   */
const cru_api_t g_cru_on_cru =
{
    .open        = R_CRU_Open,
    .s_stream   = R_CRU_Stream,
    .close       = R_CRU_Close,
    .status     = R_CRU_Status,
};

/*******************************************************************************************************************//**
 * @addtogroup CRU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***************************************************************************************************************//**
 * Open and configure the CRU module for operation.
 *
 * Example:
 * @snippet 
 *
 * @retval FSP_SUCCESS                      CRU Module opened successfully.
 * @retval FSP_ERR_ALREADY_OPEN             Driver already open.
 *****************************************************************************************************************/
fsp_err_t R_CRU_Open (cru_ctrl_t * const p_ctrl, cru_cfg_t const * const p_cfg)
{
    cru_instance_ctrl_t * p_instance_ctrl = (cru_instance_ctrl_t *) p_ctrl;
    fsp_err_t err = FSP_SUCCESS;
    uint8_t inf_type; // Input format type - 0: YUV, 1: RGB, 2: RAW
    uint8_t ouf_type; // Output format type - 0: YUV, 1: RGB

#if CRU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(CRU_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif
    p_instance_ctrl->p_cfg = p_cfg;
    p_instance_ctrl->input_format = p_cfg->input_format;
    p_instance_ctrl->output_format = p_cfg->output_format;
    p_instance_ctrl->width = p_cfg->width;
    p_instance_ctrl->height = p_cfg->height;
    p_instance_ctrl->datalane = p_cfg->datalane;
    p_instance_ctrl->p_buffer_addr = p_cfg->p_buffer_addr;
    p_instance_ctrl->mbvalid = p_cfg->mbvalid;
	p_instance_ctrl->p_link_reg = R_CSI2_LINK;
	p_instance_ctrl->p_phy_reg = R_CSI2_PHY;
    p_instance_ctrl->p_im_reg = R_CRU;
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    switch (p_instance_ctrl->input_format)
    {
        case CRU_INPUT_FORMAT_RAW8:
        case CRU_INPUT_FORMAT_RAW10:
        case CRU_INPUT_FORMAT_RAW12:
        case CRU_INPUT_FORMAT_RAW14:
            inf_type = 2;
            break;
        case CRU_INPUT_FORMAT_RGB565:
        case CRU_INPUT_FORMAT_RGB888:
            inf_type = 1;
            break;
        case CRU_INPUT_FORMAT_YUV420_8BIT:
        case CRU_INPUT_FORMAT_YUV420_10BIT:
        case CRU_INPUT_FORMAT_YUV422_8BIT:
        case CRU_INPUT_FORMAT_YUV422_10BIT:
        default:
            inf_type = 0;
            break;
    }

    switch (p_instance_ctrl->output_format)
    {
        case CRU_OUTPUT_FORMAT_RGB888_24BIT:
        case CRU_OUTPUT_FORMAT_RGB888_32BIT:
        case CRU_OUTPUT_FORMAT_ARGB8888:
        case CRU_OUTPUT_FORMAT_BGRA8888:
            ouf_type = 1;
            break;
        case CRU_OUTPUT_FORMAT_YUV420_YUYV:
        case CRU_OUTPUT_FORMAT_YUV420_UYVY:
        case CRU_OUTPUT_FORMAT_YUV422_YUYV:
        case CRU_OUTPUT_FORMAT_YUV422_UYVY:
        case CRU_OUTPUT_FORMAT_YUV422_YC:
        case CRU_OUTPUT_FORMAT_YUV422_Y:
        default:
            ouf_type = 0;
            break;
    }
    if (inf_type != ouf_type)
    {
        p_instance_ctrl->convert_format = 1;
    }
    else
    {
        p_instance_ctrl->convert_format = 0;
    }

	/* Power on */
    R_BSP_MODULE_RSTON(FSP_IP_CRU, 0);
    R_BSP_MODULE_RSTON(FSP_IP_CRU, 1);
    R_BSP_MODULE_RSTON(FSP_IP_CRU, 2);

    // add CLK ON Bit 0
    R_BSP_MODULE_CLKON(FSP_IP_CRU, 0);
    //
    R_BSP_MODULE_CLKON(FSP_IP_CRU, 1);
    R_BSP_MODULE_CLKON(FSP_IP_CRU, 2);
    R_BSP_MODULE_CLKON(FSP_IP_CRU, 3);
    R_BSP_MODULE_CLKON(FSP_IP_CRU, 4);

    /* MIPI-CSI2 input receive start */
    /* Release the CRU from the reset state for the first time (the entire CRU)
     * CPG_RST_CRU.CRU_ARESETN = 1
     * CPG_RST_CRU.CRU_PRESETN = 1
     */
    R_BSP_MODULE_RSTOFF(FSP_IP_CRU, 1);
    R_BSP_MODULE_RSTOFF(FSP_IP_CRU, 2);

    if ((1 == p_instance_ctrl->p_link_reg->CSI2nMCT3_b.RXEN) &&
            (1 == p_instance_ctrl->p_im_reg->ICnEN_b.ICEN))
    {
        //Reception stop flow for the MIPI CSI-2 input
        err = rzg2l_csi2_stop(p_instance_ctrl);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    /* Initializing the D-PHY (MIPI CSI-2 input) */
    err = rzg2l_csi2_dphy_setting(p_instance_ctrl, 1);

    /* Select the MIPI CSI-2 input */
    p_instance_ctrl->p_im_reg->CRUnCTRL_b.VINSEL = 0b0;

    /* Release the CRU from the reset state for the second time (image processing) */
    p_instance_ctrl->p_im_reg->CRUnRST_b.VRESETN = 0b1;

    /* Disable the image processing interrupts */
    p_instance_ctrl->p_im_reg->CRUnIE = 0x00000000;

    /* Clear the image processing interrupt status */
    p_instance_ctrl->p_im_reg->CRUnINTS = 0x001F000F;

    /* FIXME: Initializing the AXI master (MIPI CSI-2 input) */
    r_cru_initialize_axi(p_instance_ctrl);

    /* FIXME: Initializing image processing (MIPI CSI-2 input) */
    err = r_cru_initialize_image_conv(p_instance_ctrl);

    /* FIXME: Enable interrupt for End Frame and IRQ 167 only */
    p_instance_ctrl->p_im_reg->CRUnIE_b.EFE = 1;
    //p_instance_ctrl->p_im_reg->CRUnIE_b.SIE = 1;
    R_BSP_IrqCfgEnable (CRU_IMAGE_CONV_INT_IRQn, 24, p_instance_ctrl);

    /* Enable image processing reception */
    //p_instance_ctrl->p_im_reg->ICnEN_b.ICEN = 0b1;

    /* FIXME: Initializing the LINK (MIPI CSI-2 input) */
    r_cru_mipi_link_set(p_instance_ctrl);

    p_instance_ctrl->open = CRU_OPEN;

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Stream image from MIPI-Camera
 *
 * @note
 * enable: 1 Start capture from MIPI camera
 *         Others: Stop capture
 *
 * Example:
 * @snippet
 *
 * @retval FSP_SUCCESS                 CSI2 Stream image successfully.
 * @retval FSP_ERR_NOT_OPEN            CSI2 module not open.
 *****************************************************************************************************************/
fsp_err_t R_CRU_Stream (cru_ctrl_t * const p_ctrl, uint32_t enable)
{
    cru_instance_ctrl_t * p_instance_ctrl = (cru_instance_ctrl_t *) p_ctrl;

#if CRU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CRU_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    if (enable == 1)
    {
        p_instance_ctrl->p_im_reg->ICnEN_b.ICEN = 0b1;
        // VCLK OFF
        //R_BSP_MODULE_CLKOFF(FSP_IP_CRU, 1);
        // Enable LINK reception CSI2nMCT3, RXEN bit to 1
        //p_instance_ctrl->p_link_reg->CSI2nMCT3_b.RXEN = 0b1;
        // VCLK ON
        //R_BSP_MODULE_CLKON(FSP_IP_CRU, 1);
        // Release the CRU from the reset state, CPG_RST_CRU.CRU_CMN_RSTB = 1
        R_BSP_MODULE_RSTOFF(FSP_IP_CRU, 0);

        /* ≥ 1 ms wait */
        //R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
		//vTaskDelay(1);
    }
    else
    {
        /* Stop the operation of Image processing */
        p_instance_ctrl->p_im_reg->ICnEN_b.ICEN = 0b0;
    }

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Close the CRU module.
 *
 * @retval FSP_SUCCESS          CRU Module closed successfully.
 * @retval FSP_ERR_ASSERTION    An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN		CRU module not open. *****************************************************************************************************************/
fsp_err_t R_CRU_Close (cru_ctrl_t * const p_ctrl)
{
    cru_instance_ctrl_t * p_instance_ctrl = (cru_instance_ctrl_t *) p_ctrl;

#if CRU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CRU_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Disable interrupts */
    p_instance_ctrl->p_im_reg->CRUnIE_b.SFE      = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.EFE      = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.SIE      = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.WIE      = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.SDFEOVWE = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.SDDECEE  = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.SDSLVEE  = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.SDFOE    = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.FEOVWE   = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.DECEE    = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.SLVEE    = 0b0;
    p_instance_ctrl->p_im_reg->CRUnIE_b.FOE      = 0b0;

    rzg2l_csi2_stop(p_instance_ctrl);

	R_BSP_CLKOFF(BSP_CLK_CRU, 0);
	R_BSP_CLKOFF(BSP_CLK_CRU, 1);
	R_BSP_CLKOFF(BSP_CLK_CRU, 2);
	R_BSP_CLKOFF(BSP_CLK_CRU, 3);
	R_BSP_CLKOFF(BSP_CLK_CRU, 4);

    /* Mark the module as closed */
    p_instance_ctrl->open  = 0U;

    return FSP_SUCCESS;
}


fsp_err_t R_CRU_Status (cru_ctrl_t * const p_ctrl, cru_status_t * p_buffer_status)
{
    cru_instance_ctrl_t * p_instance_ctrl = (cru_instance_ctrl_t *) p_ctrl;
    uint32_t buffer_index;

#if CRU_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CRU_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_buffer_status);
#endif

    buffer_index = p_instance_ctrl->p_im_reg->AMnMBS_b.MBSTS;
    p_buffer_status->buf_index = buffer_index;
    switch (buffer_index)
    {
        case 0:
            p_buffer_status->p_buffer = (uint32_t *) ((uint32_t) p_instance_ctrl->p_buffer_addr->p_buffer0 & CAST_TO_UINT32);
            break;
        case 1:
            p_buffer_status->p_buffer = (uint32_t *) ((uint32_t) p_instance_ctrl->p_buffer_addr->p_buffer1 & CAST_TO_UINT32);
            break;
        case 2:
            p_buffer_status->p_buffer = (uint32_t *) ((uint32_t) p_instance_ctrl->p_buffer_addr->p_buffer2 & CAST_TO_UINT32);
            break;
        case 3:
            p_buffer_status->p_buffer = (uint32_t *) ((uint32_t) p_instance_ctrl->p_buffer_addr->p_buffer3 & CAST_TO_UINT32);
            break;
        case 4:
            p_buffer_status->p_buffer = (uint32_t *) ((uint32_t) p_instance_ctrl->p_buffer_addr->p_buffer4 & CAST_TO_UINT32);
            break;
        case 5:
            p_buffer_status->p_buffer = (uint32_t *) ((uint32_t) p_instance_ctrl->p_buffer_addr->p_buffer5 & CAST_TO_UINT32);
            break;
        case 6:
            p_buffer_status->p_buffer = (uint32_t *) ((uint32_t) p_instance_ctrl->p_buffer_addr->p_buffer6 & CAST_TO_UINT32);
            break;
        case 7:
            p_buffer_status->p_buffer = (uint32_t *) ((uint32_t) p_instance_ctrl->p_buffer_addr->p_buffer7 & CAST_TO_UINT32);
            break;
        default:
            break;
    }

    return FSP_SUCCESS;
}



/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Internal CRU private function.
 **********************************************************************************************************************/

fsp_err_t rzg2l_csi2_stop(cru_instance_ctrl_t *p_ctrl)
{
    /* Determining Link packet stop */
    r_cru_link_packet_stop(p_ctrl);

	/* Stop DPHY reception */
	rzg2l_csi2_dphy_setting(p_ctrl, 0);

	/* Stop LINK reception */
	p_ctrl->p_link_reg->CSI2nMCT3_b.RXEN = 0b0;

	/* Request a software reset of the LINK Video Pixel Interface */
	p_ctrl->p_link_reg->CSI2nRTCT_b.VSRST = CSI2nRTCT_VSRST;

	while (1) {
		/* Make sure that the execution status is not during a reset */
        
		if (p_ctrl->p_link_reg->CSI2nRTST_b.VSRSTS == 0)
			break;
	};
    
    /* Stopping image processing reception */
    r_cru_stop_image_processing(p_ctrl);

	return FSP_SUCCESS;
}

/* -----------------------------------------------------------------------------
 * DPHY setting
 */

fsp_err_t rzg2l_csi2_dphy_setting(cru_instance_ctrl_t *p_ctrl, uint8_t on)
{
	fsp_err_t err = FSP_SUCCESS;

	if (1 == on)
    {
		p_ctrl->p_phy_reg->CSIDPHYTIM0 = CSI2_DPHYTIM0;
		p_ctrl->p_phy_reg->CSIDPHYTIM1 = CSI2_DPHYTIM1;

	    /* skew adjustment setting */
		p_ctrl->p_phy_reg->CSIDPHYSKW0  = CSI2_DPHYSKW0;

	    /* D-PHY control setting */
		p_ctrl->p_phy_reg->CSIDPHYCTRL0_b.CAL_EN_HSRX_OFS = 0b1;

		/* Set the EN_BGR bit */
		p_ctrl->p_phy_reg->CSIDPHYCTRL0_b.EN_BGR = 0b1;

		/* Delay 20us to be stable */
	    R_BSP_SoftwareDelay(20, BSP_DELAY_UNITS_MICROSECONDS);

		/* Set the EN_LDO1200 bit */
	    p_ctrl->p_phy_reg->CSIDPHYCTRL0_b.EN_LDO1200 = 0b1;

		/* Delay 10us to be stable */
        R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);
        R_BSP_MODULE_CLKON(FSP_IP_CRU, 0);
	}
	else
	{
		r_cru_dphy_stop(p_ctrl);
	}

	return err;
}

void cru_int_isr (void)
{
    IRQn_Type   irq;

    cru_callback_args_t args;
    uint32_t event_flag;
    uint32_t scan_line_flag;
    uint32_t frame_end_flag;
    uint32_t frame_start_flag;
    uint32_t reg_val;
    uint32_t buffer_index;

    /* Variable to handle update image address */
    volatile uint32_t *mb_address[8];
    static uint8_t image_count = 0;
    static uint8_t mb_index = 0;
    static uint8_t mb_pre_index = 0;
    cru_mbvalid_t mb_num_cfg;


    irq = R_FSP_CurrentIrqGet();

    cru_instance_ctrl_t  * p_ctrl = (cru_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    buffer_index = p_ctrl->p_im_reg->AMnMBS_b.MBSTS;

    /* clear event flag */
    event_flag = 0;

    /* get register value of  interrupt status (CRUnINIS) */
    reg_val           = p_ctrl->p_im_reg->CRUnINTS;
    scan_line_flag   = (reg_val >> 18) & CAST_TO_UINT1;
    frame_end_flag   = (reg_val >> 17) & CAST_TO_UINT1;
    frame_start_flag = (reg_val >> 16) & CAST_TO_UINT1;

    /* Check which interrupt is generated */
    if (frame_start_flag == 0b1)
    {
        event_flag |= CRU_EVENT_FRAME_START;
    }
    else
    {
        /* Do Nothing */
    }

    if (frame_end_flag == 0b1)
    {
        event_flag |= CRU_EVENT_FRAME_END;

        /* Get index of memory bank */
        mb_index = p_ctrl->p_im_reg->AMnMBS_b.MBSTS;

        /* Get configuration of used memory bank  */
        mb_num_cfg = p_ctrl->mbvalid;

        /* Update memory bank value if used 1 bank */
        if(mb_num_cfg == CRU_1_MB_VALID)
        {
            mb_address[0] = &p_ctrl->p_im_reg->AMnMB1ADDRL;
            *mb_address[0] += 0x400000;
        }

        /* Update memory bank value if used 4 bank */
        else if (mb_num_cfg == CRU_4_MB_VALID)
        {
            /* pre index from 0 to 1 and index from 2 to 3, update address for mb1 and mb2 */
            if((mb_pre_index < 2) && (mb_index >= 2))
            {
                mb_address[0] = &p_ctrl->p_im_reg->AMnMB1ADDRL;
                mb_address[1] = &p_ctrl->p_im_reg->AMnMB2ADDRL;
                *mb_address[0] += 0x1000000;
                *mb_address[1] += 0x1000000;
//                *mb_address[0] += 0x400000;
//                *mb_address[1] += 0x400000;
            }
            /* pre index from 2 to 3 and index from 0 to 1, update address for mb3 and mb4 */
            else if((mb_pre_index >= 2) && (mb_index < 2))
            {
                mb_address[2] = &p_ctrl->p_im_reg->AMnMB3ADDRL;
                mb_address[3] = &p_ctrl->p_im_reg->AMnMB4ADDRL;
                *mb_address[2] += 0x1000000;
                *mb_address[3] += 0x1000000;
//                *mb_address[2] += 0x400000;
//                *mb_address[3] += 0x400000;
            }
        }

        /* Update memory bank value if used 8 bank */
        else
        {
            /* pre index from 0 to 3 and index from 4 to 7, update address from mb1 to mb4 */
            if((mb_pre_index < 4) && (mb_index >= 4))
            {
                mb_address[0] = &p_ctrl->p_im_reg->AMnMB1ADDRL;
                mb_address[1] = &p_ctrl->p_im_reg->AMnMB2ADDRL;
                mb_address[2] = &p_ctrl->p_im_reg->AMnMB3ADDRL;
                mb_address[3] = &p_ctrl->p_im_reg->AMnMB4ADDRL;
                *mb_address[0] += 0x2000000;
                *mb_address[1] += 0x2000000;
                *mb_address[2] += 0x2000000;
                *mb_address[3] += 0x2000000;
            }
            /* pre index from 4 to 7 and index from 0 to 3, update address from mb5 to mb8 */
            else if((mb_pre_index >= 4) && (mb_index < 4))
            {
                mb_address[4] = &p_ctrl->p_im_reg->AMnMB5ADDRL;
                mb_address[5] = &p_ctrl->p_im_reg->AMnMB6ADDRL;
                mb_address[6] = &p_ctrl->p_im_reg->AMnMB7ADDRL;
                mb_address[7] = &p_ctrl->p_im_reg->AMnMB8ADDRL;
                *mb_address[4] += 0x2000000;
                *mb_address[5] += 0x2000000;
                *mb_address[6] += 0x2000000;
                *mb_address[7] += 0x2000000;
            }
        }

        /* Update mb_pre_index value */
        mb_pre_index = mb_index;

        /* Stop the stream when 60 images are received */
        image_count ++;
        LPRINTF ("image count = %d\n", image_count);

        if(image_count >= 60)
        {
            R_CRU_Stream (p_ctrl, 0);
            __NOP();
        }
    }
    else
    {
        /* Do Nothing */
    }

    if (scan_line_flag == 0b1)
    {
        event_flag |= CRU_EVENT_SCAN_LINE;
    }
    else
    {
        /* Do Nothing */
    }

    /* Call back callback function if it is registered */
    if (NULL != p_ctrl->p_callback)
    {
        args.event     = event_flag;
        args.buf_index = buffer_index;
        p_ctrl->p_callback(&args);
    }
    else
    {
        /* Do Nothing */
    }

    /* Clear interrupt flag */
    if (scan_line_flag == 0b1)
    {
        p_ctrl->p_im_reg->CRUnINTS_b.SIS = 1;
    }
    else
    {
        /* Do Nothing */
    }

    if (frame_end_flag == 0b1)
    {
        p_ctrl->p_im_reg->CRUnINTS_b.EFS = 1;
    }
    else
    {
        /* Do Nothing */
    }

    if (frame_start_flag == 0b1)
    {
        p_ctrl->p_im_reg->CRUnINTS_b.SFS = 1;
    }
    else
    {
        /* Do Nothing */
    }
}

void r_cru_initialize_axi(cru_instance_ctrl_t *p_ctrl)
{
    /* Set image data memory banks.
     * Currently, we will use maximum address.
     */
    p_ctrl->p_im_reg->AMnMBVALID_b.MBVALID = p_ctrl->mbvalid;
    if (0x0 != p_ctrl->p_buffer_addr->p_buffer0)
    {
        p_ctrl->p_im_reg->AMnMB1ADDRL = (uint32_t) p_ctrl->p_buffer_addr->p_buffer0 & CAST_TO_UINT32;;
        p_ctrl->p_im_reg->AMnMB1ADDRH = 0x00000000;
    }
    if (0x0 != p_ctrl->p_buffer_addr->p_buffer1)
    {
        p_ctrl->p_im_reg->AMnMB2ADDRL = (uint32_t) p_ctrl->p_buffer_addr->p_buffer1 & CAST_TO_UINT32;
        p_ctrl->p_im_reg->AMnMB2ADDRH = 0x00000000;
    }
    if (0x0 != p_ctrl->p_buffer_addr->p_buffer2)
    {
        p_ctrl->p_im_reg->AMnMB3ADDRL = (uint32_t) p_ctrl->p_buffer_addr->p_buffer2 & CAST_TO_UINT32;
        p_ctrl->p_im_reg->AMnMB3ADDRH = 0x00000000;
    }
    if (0x0 != p_ctrl->p_buffer_addr->p_buffer3)
    {
        p_ctrl->p_im_reg->AMnMB4ADDRL = (uint32_t) p_ctrl->p_buffer_addr->p_buffer3 & CAST_TO_UINT32;
        p_ctrl->p_im_reg->AMnMB4ADDRH = 0x00000000;
    }
    if (0x0 != p_ctrl->p_buffer_addr->p_buffer4)
    {
        p_ctrl->p_im_reg->AMnMB5ADDRL = (uint32_t) p_ctrl->p_buffer_addr->p_buffer4 & CAST_TO_UINT32;
        p_ctrl->p_im_reg->AMnMB5ADDRH = 0x00000000;
    }
    if (0x0 != p_ctrl->p_buffer_addr->p_buffer5)
    {
        p_ctrl->p_im_reg->AMnMB6ADDRL = (uint32_t) p_ctrl->p_buffer_addr->p_buffer5 & CAST_TO_UINT32;
        p_ctrl->p_im_reg->AMnMB6ADDRH = 0x00000000;
    }
    if (0x0 != p_ctrl->p_buffer_addr->p_buffer6)
    {
        p_ctrl->p_im_reg->AMnMB7ADDRL = (uint32_t) p_ctrl->p_buffer_addr->p_buffer6 & CAST_TO_UINT32;
        p_ctrl->p_im_reg->AMnMB7ADDRH = 0x00000000;
    }
    if (0x0 != p_ctrl->p_buffer_addr->p_buffer7)
    {
        p_ctrl->p_im_reg->AMnMB8ADDRL = (uint32_t) p_ctrl->p_buffer_addr->p_buffer7 & CAST_TO_UINT32;
        p_ctrl->p_im_reg->AMnMB8ADDRH = 0x00000000;
    }

    p_ctrl->p_im_reg->AMnUVAOFL = 0x00000000;
    p_ctrl->p_im_reg->AMnUVAOFH = 0x00000000;

    p_ctrl->p_im_reg->AMnAXIATTR_b.AXILEN = 0b0000;
    //p_ctrl->p_im_reg->AMnFIFO_b.FIFOOVFREC = 0b1;

    p_ctrl->p_im_reg->AMnFIFO_b.FIFOOVFREC = 0b0;
    /* AXI Master BID check setting */
    p_ctrl->p_im_reg->AMnAXIBID_b.BIDCHK = 0b1;
    /* AXI Master transfer stop setting */
    p_ctrl->p_im_reg->AMnAXISTP_b.AXI_STOP = 0b0;
}

fsp_err_t r_cru_initialize_image_conv(cru_instance_ctrl_t *p_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;
    uint8_t use_ptn_generate = 0;

    /* FIXME: Add code for Pattern generator used */
    if (use_ptn_generate)
    {
        p_ctrl->p_im_reg->ICnTICTRL1_b.TIEN = 1;
        p_ctrl->p_im_reg->ICnTICTRL1_b.TIMODE = 1;
        // monochrome generate
        p_ctrl->p_im_reg->ICnTICTRL2_b.TIPTNY2 = 0x52;
        p_ctrl->p_im_reg->ICnTICTRL2_b.TIPTNU2 = 0x5A;
        p_ctrl->p_im_reg->ICnTICTRL2_b.TIPTNV2 = 0xF0;
        p_ctrl->p_im_reg->ICnTISIZE1_b.TIPPL = 0x780;
        p_ctrl->p_im_reg->ICnTISIZE2_b.TIN = 0x438;
        p_ctrl->p_im_reg->ICnTISIZE2_b.TIM = 0x1;

        // pattern generate
//        p_ctrl->p_im_reg->ICnTICTRL1_b.TIPTNY1 = 0x52;
//        p_ctrl->p_im_reg->ICnTICTRL1_b.TIPTNU1 = 0x5A;
//        p_ctrl->p_im_reg->ICnTICTRL1_b.TIPTNV1 = 0xF0;
//        p_ctrl->p_im_reg->ICnTISIZE1_b.TIPPL = 0x780;
//        p_ctrl->p_im_reg->ICnTISIZE2_b.TIN = 0x438;
//        p_ctrl->p_im_reg->ICnTISIZE2_b.TIM = 0x00;
    }
    else
    {
        if (0 == p_ctrl->p_im_reg->CRUnCTRL_b.VINSEL)
        {
            /* Let ICnMC as defauult:
             * VCSEL = 0 (chanel 0)
             * INF = 0x1E: YUV422 8-bit
             */
            p_ctrl->p_im_reg->ICnMC_b.VCSEL = 0x0;
            p_ctrl->p_im_reg->ICnMC_b.INF = capture_input_format[p_ctrl->input_format] & CAST_TO_UINT6;
            p_ctrl->p_im_reg->ICnMC_b.RAWSTTYP = 0 & CAST_TO_UINT2;
        }
    }

    /* Set modes */
    // Keep as default-
    p_ctrl->p_im_reg->ICnMC_b.ICTHR = 0b0;
    p_ctrl->p_im_reg->ICnMC_b.DECTHR   = 0b1;
    p_ctrl->p_im_reg->ICnMC_b.CLPTHR   = 0b1;
    if ((p_ctrl->input_format >= CRU_INPUT_FORMAT_RAW8) && (p_ctrl->input_format <= CRU_INPUT_FORMAT_RAW14))
    {
        p_ctrl->p_im_reg->ICnMC_b.DEMTHR   = 0b0;
    }
    else
    {
        p_ctrl->p_im_reg->ICnMC_b.DEMTHR   = 0b1;
    }
    /* setting Linear Matrix */
    p_ctrl->p_im_reg->ICnMC_b.LMXTHR   = 0b1 & CAST_TO_UINT1;

    if (1 == p_ctrl->convert_format)
    {
        p_ctrl->p_im_reg->ICnMC_b.CSCTHR   = 0b0;
    }
    else
    {
        p_ctrl->p_im_reg->ICnMC_b.CSCTHR   = 0b1;
    }

    /* disable LUT (10bit to 8bit) */
    p_ctrl->p_im_reg->ICnMC_b.LUTTHR   = 0b1;

    /* setting Statistics */
    p_ctrl->p_im_reg->ICnMC_b.STITHR   = 0b1 & CAST_TO_UINT1;

    /* FIXME: Support Frame subsampling */

    /* FIXME: Support Image clipping */
    p_ctrl->p_im_reg->ICnMC_b.CLP  = 0b11;

    /* select offset binary of U and V */
    p_ctrl->p_im_reg->ICnMC_b.IBINSEL  = 0b0;

    /* setting RGB Extension */
    p_ctrl->p_im_reg->ICnMC_b.DES0     = 0 & CAST_TO_UINT1;

    /** Setting the frame thinning interval */
    if(p_ctrl->p_im_reg->ICnMC_b.DECTHR == 0b0)
    {
        p_ctrl->p_im_reg->ICnDEC_b.FRMDEC = 0b0000;
    }

    /** Settings image clip position */
    if (p_ctrl->p_im_reg->ICnMC_b.CLPTHR == 0b0)
    {
        p_ctrl->p_im_reg->ICnSLPrC_b.SLPrC = 0 & CAST_TO_UINT12;
        p_ctrl->p_im_reg->ICnELPrC_b.ELPrC = p_ctrl->height & CAST_TO_UINT12;
        p_ctrl->p_im_reg->ICnSPPrC_b.SPPrC = 0 & CAST_TO_UINT12;
        p_ctrl->p_im_reg->ICnEPPrC_b.EPPrC = p_ctrl->width & CAST_TO_UINT12;
    }

    /** Linear Matrix processing settings */
    if ((p_ctrl->p_im_reg->ICnMC_b.DEMTHR == 0b0) && (p_ctrl->p_im_reg->ICnMC_b.LMXTHR == 0b0))
    {
        /* FIXME: Support Linear Matrix */
    }
    /** Statistics processing settings */
    if (p_ctrl->p_im_reg->ICnMC_b.STITHR == 0b0)
    {
        /* FIXME: Support Statistics processing */
    }

    /** Color space conversion processing settings */
    if (p_ctrl->p_im_reg->ICnMC_b.CSCTHR == 0b0)
    {
        if((p_ctrl->input_format == CRU_INPUT_FORMAT_YUV422_8BIT) ||
            (p_ctrl->input_format == CRU_INPUT_FORMAT_YUV422_10BIT))
        {
            /** Color space conversion (YUV to RGB conversion) settings */
            p_ctrl->p_im_reg->ICnCSCC1 = REGVAL_ICnCSCC1;
            p_ctrl->p_im_reg->ICnCSCC2 = REGVAL_ICnCSCC2;
            p_ctrl->p_im_reg->ICnCSCC3 = REGVAL_ICnCSCC3;
            p_ctrl->p_im_reg->ICnCSCC4 = REGVAL_ICnCSCC4;
        }
        else
        {
            /** Color space conversion (RGB to YUV conversion) settings */
            /* RGB->YCbCr Y coefficient */
            p_ctrl->p_im_reg->ICnYCCR1 = REGVAL_ICnYCCR1;
            p_ctrl->p_im_reg->ICnYCCR2 = REGVAL_ICnYCCR2;
            p_ctrl->p_im_reg->ICnYCCR3 = REGVAL_ICnYCCR3;

            /* RGB->YCbCr Cr coefficient */
            p_ctrl->p_im_reg->ICnCBCCR1 = REGVAL_ICnCBCCR1;
            p_ctrl->p_im_reg->ICnCBCCR2 = REGVAL_ICnCBCCR2;
            p_ctrl->p_im_reg->ICnCBCCR3 = REGVAL_ICnCBCCR3;

            /* RGB->YCbCr Cr coefficient */
            p_ctrl->p_im_reg->ICnCRCCR1 = REGVAL_ICnCRCCR1;
            p_ctrl->p_im_reg->ICnCRCCR2 = REGVAL_ICnCRCCR2;
            p_ctrl->p_im_reg->ICnCRCCR3 = REGVAL_ICnCRCCR3;
        }
    }

    if ( p_ctrl->p_im_reg->ICnMC_b.LUTTHR == 0b0 )
    {
        /** LUT data storage processing */
    }

    /** Output data format setting */
    p_ctrl->p_im_reg->ICnDMR = 0x00000000;

    /* RGB data order setting */
    if ( p_ctrl->output_format >= CRU_OUTPUT_FORMAT_RGB888_24BIT)
    {
        p_ctrl->p_im_reg->ICnDMR_b.RGBMODE = capture_output_format[p_ctrl->output_format] & CAST_TO_UINT2;
    }

    /* YUV data order setting */
    if (p_ctrl->output_format <= CRU_OUTPUT_FORMAT_YUV422_Y)
    {
        p_ctrl->p_im_reg->ICnDMR_b.YCMODE = capture_output_format[p_ctrl->output_format] & CAST_TO_UINT3;
    }

    /* YUV output binary setting */
    p_ctrl->p_im_reg->ICnDMR_b.OBINSEL = 0b0;

    /* Alpha value setting in ARGB format */
    p_ctrl->p_im_reg->ICnDMR_b.A8BIT = 0x00;

    /** Interrupt-related settings */
//    p_ctrl->p_im_reg->ICnSI_b.SI = 0x000;
    //p_ctrl->p_im_reg->ICnSI_b.SI = 0x438;
    p_ctrl->p_im_reg->ICnSI_b.SI = 0x438;
    p_ctrl->p_im_reg->ICnINTCTRL_b.DECINTE = 0b0;
    p_ctrl->p_im_reg->ICnEWC_b.EWC = 0x0000;

    return err;
}

static void r_cru_mipi_link_set(cru_instance_ctrl_t *p_ctrl)
{
     /* disable de-scrambling */
    p_ctrl->p_link_reg->CSI2nMCT0_b.LFSREN = 0b0;

     /* ECC  0:26bit 1:24bit*/
    p_ctrl->p_link_reg->CSI2nMCT0_b.ECCV13 = 0b0;

     /* number of used data lanes */
    p_ctrl->p_link_reg->CSI2nMCT0_b.VDLN = p_ctrl->datalane;

     /* internal setting parameter */
    p_ctrl->p_link_reg->CSI2nMCT2 = CSI2_MCT2;

     /*input data type setting, all format enable */
    p_ctrl->p_link_reg->CSI2nDTEL = 0xf778ff0f;
    p_ctrl->p_link_reg->CSI2nDTEH = 0x00ffff1f;

     /* generic short packet FIFO */
     //CSI2LINK->GSCT = 0x00010000;


     /* enable LINK receive */
    p_ctrl->p_link_reg->CSI2nMCT3_b.RXEN = 0b1;;
}

static void r_cru_link_packet_stop(cru_instance_ctrl_t *p_ctrl)
{

    /* wait for a frame to be received for a period of one frame */
    while(p_ctrl->p_link_reg->CSI2nRXST_b.RACTDET == 1)
    {
        /* clear CSI2nRXST.RACTDET */
        p_ctrl->p_link_reg->CSI2nRXSC_b.RACTDETC = 0b1;
    }
}

static void r_cru_dphy_stop(cru_instance_ctrl_t *p_ctrl)
{
    /* Reset the CRU (D-PHY) */
    //R_CPG->CPG_RST_CRU_b.UNIT0_RSTB = 0b0;
    R_BSP_MODULE_RSTOFF(FSP_IP_CRU, 0);


    /* Stop the D-PHY clock */
    //R_CPG->CPG_CLKON_CRU_b.CLK0_ON = 0b0;
    R_BSP_CLKOFF(BSP_CLK_CRU, 0);

    /* Cancel the EN_LDO1200 register settings */
    p_ctrl->p_phy_reg->CSIDPHYCTRL0_b.EN_LDO1200 = 0b0;

    /* Cancel the EN_BGR register settings */
    p_ctrl->p_phy_reg->CSIDPHYCTRL0_b.EN_BGR = 0b0;
}

static void r_cru_stop_image_processing(cru_instance_ctrl_t *p_ctrl)
{
    /* Stop the operation of Image Processing*/
    p_ctrl->p_im_reg->ICnEN_b.ICEN = 0b0;

    /* Image data has not been received yet */
    while(p_ctrl->p_im_reg->ICnMS_b.IA == 1)
    {
        /*
         * No operation
         */
    }

    /* wait until the FIFO becomes empty */
    while(p_ctrl->p_im_reg->AMnFIFOPNTR_b.FIFORPNTR_Y != R_CRU->AMnFIFOPNTR_b.FIFOWPNTR)
    {
        /*
         * No operation
         */
    }

    /* Request the AXI bus to stop */
    p_ctrl->p_im_reg->AMnAXISTP_b.AXI_STOP = 0b1;

    /* Check AXi bus stopped */
    while(p_ctrl->p_im_reg->AMnAXISTPACK_b.AXI_STOP_ACK == 0)
    {
        /*
         * No operation
         */
    }

    /* Cancel the AXI bus stop request */
    p_ctrl->p_im_reg->AMnAXISTP_b.AXI_STOP = 0b0;

    /* Reset the CRU */
    //R_CPG->CPG_RSTMON_CRU_b.RST2_MON = 0b0;
    R_BSP_MODULE_RSTON(FSP_IP_CRU, 2);

    /* Reset the CRU */
    p_ctrl->p_im_reg->CRUnRST = 0b0;
}

