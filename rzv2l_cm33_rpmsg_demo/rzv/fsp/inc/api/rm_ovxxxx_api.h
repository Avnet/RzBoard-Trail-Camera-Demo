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
 * @defgroup RM_OVXXXX_API OVXXXX Middleware Interface
 * @brief Interface for OVXXXX Middleware functions.
 *
 * @section RM_OVXXXX_API_Summary Summary
 * The OVXXXX interface provides OVXXXX functionality.
 *
 * The OVXXXX interface can be implemented by:
 * - @ref RM_OV5645
 *
 * @{
 **********************************************************************************************************************/

#ifndef RM_OVXXXX_API_H_
#define RM_OVXXXX_API_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_riic_master.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef struct reg_value {
    uint16_t reg;
    uint8_t val;
} reg_value_t;

/** OVXXXX Configuration */
typedef struct st_rm_ovxxxx_cfg
{
    i2c_master_instance_t const * p_i2c_instance;                  ///< Pointer to I2C master instance.
    void const                * p_context;                   ///< Pointer to the user-provided context.
    void const                * p_extend;                    ///< Pointer to extended configuration by instance of interface.
} rm_ovxxxx_cfg_t;

/** OVXXXX control block.  Allocate an instance specific control block to pass into the OVXXXX API calls.
 * @par Implemented as
 * - rm_ovxxxx_instance_ctrl_t
 */
typedef void rm_ovxxxx_ctrl_t;

/** OVXXXX APIs */
typedef struct st_rm_ovxxxx_api
{
    /** Open sensor.
     * @par Implemented as
     * - @ref RM_OV5645_Open()
     *
     * @param[in]  p_ctrl       Pointer to control structure.
     * @param[in]  p_cfg        Pointer to configuration structure.
     */
    fsp_err_t (* open)(rm_ovxxxx_ctrl_t * const p_ctrl, rm_ovxxxx_cfg_t const * const p_cfg);

    /** Close OVXXXX.
     * @par Implemented as
     * - @ref RM_OV5645_Close()
     *
     * @param[in]  p_ctrl       Pointer to control structure.
     */
    fsp_err_t (* close)(rm_ovxxxx_ctrl_t * const p_ctrl);

    /** Stream image */
    fsp_err_t (* s_stream)(rm_ovxxxx_ctrl_t * const p_ctrl, uint32_t enable);
} rm_ovxxxx_api_t;

/** OVXXXX instance */
typedef struct st_rm_ovxxxx_instance
{
    rm_ovxxxx_ctrl_t      * p_ctrl;    /**< Pointer to the control structure for this instance */
    rm_ovxxxx_cfg_t const * p_cfg;     /**< Pointer to the configuration structure for this instance */
    rm_ovxxxx_api_t const * p_api;     /**< Pointer to the API structure for this instance */
} rm_ovxxxx_instance_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/


/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_FOOTER

#endif                                 /* RM_OVXXXX_API_H_*/

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_OVXXXX_API)
 **********************************************************************************************************************/
