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
#include "rm_exposure_control.h"
#include "rm_ov5645.h"
#include "r_cru.h"
#include "platform_info.h"
#include "task.h"
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define RM_EXP_OPEN           (0x455850U)
#define BUFFER_FLAG     0xA0000000

/***********************************************************************************************************************
 * Global function prototypes
 **********************************************************************************************************************/
extern bsp_leds_t g_bsp_leds;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/


/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
void cru_callback (cru_callback_args_t * p_args);
/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
rm_exposure_control_api_t const g_exposure_control_on_exposure_control =
{
    .start        = RM_EXPOSURE_Start,
    .stop         = RM_EXPOSURE_Stop,
};

uint32_t flag = 0;
TickType_t tc;
/*******************************************************************************************************************//**
 * @addtogroup RM_OV5645
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief Start for exposure control. Implements @ref rm_exposure_control_api_t::start.
 *
 * @retval FSP_SUCCESS                  Start successfully
 * @retval FSP_ERR_ASSERTION            Null pointer, or one or more configuration options is invalid.
 * @retval FSP_ERR_ALREADY_OPEN         Module is already start.  This module can only be started once.
 **********************************************************************************************************************/
fsp_err_t RM_EXPOSURE_Start(rm_exposure_control_ctrl_t * const p_api_ctrl, rm_exposure_control_cfg_t const * const p_cfg)
{
    R_BSP_PinWrite((bsp_io_port_pin_t) g_bsp_leds.p_leds[0], BSP_IO_LEVEL_HIGH);

    fsp_err_t err = FSP_SUCCESS;
    rm_exposure_control_instance_ctrl_t * p_ctrl = (rm_exposure_control_instance_ctrl_t *) p_api_ctrl;
    cru_status_t buffer_status;

#if RM_OV5645_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT (NULL != p_ctrl);
    FSP_ASSERT (NULL != p_cfg);
    FSP_ASSERT (NULL != p_cfg->p_instance);
    FSP_ERROR_RETURN (RM_EXP_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    p_ctrl->p_cru_instance    = p_cfg->p_cru_instance;
    p_ctrl->p_ov5645_instance = p_cfg->p_ov5645_instance;
    p_ctrl->p_context            = p_cfg->p_context;
    p_ctrl->p_extend        = p_cfg->p_extend;
    //LPRINTF ("RM_EXPOSURE_Start\n");

    err = p_cfg->p_ov5645_instance->p_api->open (p_ctrl->p_ov5645_instance->p_ctrl, p_ctrl->p_ov5645_instance->p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    err = p_cfg->p_ov5645_instance->p_api->s_stream (p_ctrl->p_ov5645_instance->p_ctrl, 1);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    err = p_cfg->p_cru_instance->p_api->open (p_ctrl->p_cru_instance->p_ctrl, p_ctrl->p_cru_instance->p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    //err = p_cfg->p_cru_instance->p_api->status (p_ctrl->p_cru_instance->p_ctrl, &buffer_status);

    err = p_cfg->p_cru_instance->p_api->s_stream (p_ctrl->p_cru_instance->p_ctrl, 1);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    tc = xTaskGetTickCount();
    LPRINTF ("Camera started - run time = %d\n", tc);
    R_BSP_PinWrite((bsp_io_port_pin_t) g_bsp_leds.p_leds[0], BSP_IO_LEVEL_LOW);

    while (1)
    {
        if (1 == flag)
            break;
    }
//    err = p_cfg->p_cru_instance->p_api->status (p_ctrl->p_cru_instance->p_ctrl, &buffer_status);
//    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    while (1 == flag)
    {
        cru_instance_ctrl_t * cru_ctrl = (cru_instance_ctrl_t *) p_cfg->p_cru_instance->p_ctrl;
        if (cru_ctrl->p_im_reg->CRUnINTS == 0)
        {
            /* Get 1st image only */
            //err = p_cfg->p_cru_instance->p_api->s_stream(p_ctrl->p_cru_instance->p_ctrl, 0);
            //FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
            /* End get 1st image */
            /* Finished capture 1 buffer */
            flag = 0;
            //LPRINTF ("Camera first image - run time = %d\n", tc);
        }
    }

    R_BSP_PinWrite((bsp_io_port_pin_t) g_bsp_leds.p_leds[0], BSP_IO_LEVEL_HIGH);
    p_ctrl->open                 = RM_EXP_OPEN;
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Stop exposure control. Implements @ref rm_exposure_control_api_t::stop.
 *
 * @retval FSP_SUCCESS              Successfully closed.
 * @retval FSP_ERR_ASSERTION        Null pointer passed as a parameter.
 * @retval FSP_ERR_NOT_OPEN         Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_EXPOSURE_Stop (rm_exposure_control_ctrl_t * const p_api_ctrl)
{
    rm_exposure_control_instance_ctrl_t * p_ctrl = (rm_exposure_control_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t err = FSP_SUCCESS;

#if RM_OV5645_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(RM_EXP_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    err = RM_OV5645_STREAM(p_ctrl->p_ov5645_instance->p_ctrl,0);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    
    err = RM_OV5645_Close(p_ctrl->p_ov5645_instance->p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    err = R_CRU_Stream(p_ctrl->p_cru_instance->p_ctrl,0);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    
    err = R_CRU_Close(p_ctrl->p_cru_instance->p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    
    /* Clear Open flag */
    p_ctrl->open = 0;

    return FSP_SUCCESS;
}

typedef struct
{
    union
    {
        volatile uint32_t flag;
    };
} buffer_flag;
#define CM33_flag    ((buffer_flag *) BUFFER_FLAG)

void cru_callback (cru_callback_args_t * p_args)
{
    uint32_t status;
    uint32_t buf_index;
    status = p_args->event;
    buf_index = p_args->buf_index;
    if (status == CRU_EVENT_FRAME_END)
    {
        flag = 1;
        CM33_flag->flag = buf_index;
        tc = xTaskGetTickCountFromISR();
        LPRINTF ("cru_callback status = %d - runtime = %d\n", status, tc);
    }
}
