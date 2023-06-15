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

#ifndef R_CRU_H
#define R_CRU_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_cru_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup CSI2
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
/* Number of HW buffers */
#define HW_BUFFER_MAX		8
#define HW_BUFFER_DEFAULT	4

/* Address alignment mask for HW buffers */
#define HW_BUFFER_MASK	0x1ff

/* Maximum bumber of CSI2 virtual channels */
#define CSI2_VCHANNEL	4

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* CRU instance   */
typedef struct st_cru_instance_ctrl
{
	uint32_t       open;         // Flag to determine if the device is open
	cru_cfg_t const * p_cfg;   // Pointer to the configuration structure
    void (* p_callback)(cru_callback_args_t * p_arg); // Pointer to callback
    cru_callback_args_t * p_callback_memory;  // Pointer to pre-allocated callback argument
    void const            * p_context;          // Pointer to context to be passed into callback function
	R_CSI2_LINK_Type		* p_link_reg;    // Base register for this channel
	R_CSI2_PHY_Type			* p_phy_reg;	// Base register for this channel
	R_CRU_IM_Type           * p_im_reg;    // Base register for this channel
    cru_input_format_t input_format;
    cru_output_format_t output_format;
    cru_width_t width;
    cru_height_t height;
    cru_datalane_t datalane;
    cru_mbvalid_t  mbvalid;
	cru_buffer_address_t   * p_buffer_addr;
    int32_t hsfreq;
    uint8_t convert_format;
} cru_instance_ctrl_t;


/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const cru_api_t g_cru_on_cru;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_CRU_Open(cru_ctrl_t * const p_ctrl, cru_cfg_t const * const p_cfg);
fsp_err_t R_CRU_Stream(cru_ctrl_t * const p_ctrl, uint32_t enable);
fsp_err_t R_CRU_Close(cru_ctrl_t * const p_ctrl);
fsp_err_t R_CRU_Status (cru_ctrl_t * const p_ctrl, cru_status_t * p_buffer_status);

/*******************************************************************************************************************//**
 * @} (end defgroup CEC)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
