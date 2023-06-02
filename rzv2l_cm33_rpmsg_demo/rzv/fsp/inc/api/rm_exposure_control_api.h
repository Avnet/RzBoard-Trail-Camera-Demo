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

/*******************************************************************************************************************//**
 * @ingroup RENESAS_INTERFACES
 * @defgroup RM_EXPOSURE_CONTROL_API Middleware Interface
 * @brief Interface for EXPOSURE CONTROL Middleware functions.
 *
 * @section RM_EXPOSURE CONTROL_API_Summary Summary
 * The EXPOSURE CONTROL interface provides EXPOSURE CONTROL functionality.
 *
 * The EXPOSURE CONTROL interface can be implemented by:
 * - @ref RM_EXPOSURE CONTROL
 *
 * @{
 **********************************************************************************************************************/

#ifndef RM_EXPOSURE_API_H_
#define RM_EXPOSURE_API_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "rm_ovxxxx_api.h"
#include "r_cru_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** RM_EXPOSURE Configuration */
typedef struct st_rm_exposure_control_cfg
{
    cru_instance_t const * p_cru_instance;
    rm_ovxxxx_instance_t const * p_ov5645_instance;
    void const                * p_context;                   ///< Pointer to the user-provided context.
    void const                * p_extend;                    ///< Pointer to extended configuration by instance of interface.
} rm_exposure_control_cfg_t;

/** exposure_control control block.  Allocate an instance specific control block to pass into the exposure_control API calls.
 * @par Implemented as
 * - rm_exposure_control_instance_ctrl_t
 */
typedef void rm_exposure_control_ctrl_t;

/** OVXXXX APIs */
typedef struct st_rm_exposure_control_api
{
    /** Start for exposure control
     * @par Implemented as
     * - @ref RM_EXPOSURE_Start()
     *
     * @param[in]  p_ctrl       Pointer to control structure.
     * @param[in]  p_cfg        Pointer to configuration structure.
     */
    fsp_err_t (* start)(rm_exposure_control_ctrl_t * const p_ctrl, rm_exposure_control_cfg_t const * const p_cfg);

    /** Stop exposure control
     * @par Implemented as
     * - @ref RM_EXPOSURE_Stop()
     *
     * @param[in]  p_ctrl       Pointer to control structure.
     */
    fsp_err_t (* stop)(rm_exposure_control_ctrl_t * const p_ctrl);

} rm_exposure_control_api_t;

/** OVXXXX instance */
typedef struct st_rm_exposure_control_instance
{
    rm_exposure_control_ctrl_t      * p_ctrl;    /**< Pointer to the control structure for this instance */
    rm_exposure_control_cfg_t const * p_cfg;     /**< Pointer to the configuration structure for this instance */
    rm_exposure_control_api_t const * p_api;     /**< Pointer to the API structure for this instance */
} rm_exposure_control_instance_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/


/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_FOOTER

#endif                                 /* RM_EXPOSURE_API_H_*/

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_EXPOSURE_API)
 **********************************************************************************************************************/
