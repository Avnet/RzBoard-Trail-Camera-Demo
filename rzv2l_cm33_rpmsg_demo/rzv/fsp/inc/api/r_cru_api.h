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

#ifndef R_CRU_API_H
#define R_CRU_API_H

/*******************************************************************************************************************//**
 * @ingroup RENESAS_INTERFACES
 * @defgroup CRU_API CRU Interface
 * @brief Interface for CRU peripheral
 *
 * @section CRU_INTERFACE_SUMMARY Summary
 * The CRU interface provides common APIs for CRU HAL drivers and supports the following features:
 * - Opening and closing the CRU module.
 * - Stream data from MIPI-Camera sensor
 *
 * Implemented by:
 * - @ref CRU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Includes board and MCU related header files. */
#include "bsp_api.h"
#include "r_cru_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum e_cru_input_format
{
    CRU_INPUT_FORMAT_YUV420_8BIT      = 0,  ///< YUV420 8bit
    CRU_INPUT_FORMAT_YUV420_10BIT     = 1,  ///< YUV420 10bit
    CRU_INPUT_FORMAT_YUV422_8BIT      = 2,  ///< YUV422 8bit
    CRU_INPUT_FORMAT_YUV422_10BIT     = 3,  ///< YUV422 10bit
    CRU_INPUT_FORMAT_RGB565           = 4,  ///< RGB565
    CRU_INPUT_FORMAT_RGB888           = 5,  ///< RGB888
    CRU_INPUT_FORMAT_RAW8             = 6,  ///< RAW8
    CRU_INPUT_FORMAT_RAW10            = 7,  ///< RAW10
    CRU_INPUT_FORMAT_RAW12            = 8,  ///< RAW12
    CRU_INPUT_FORMAT_RAW14            = 9,  ///< RAW14
} cru_input_format_t;

typedef enum e_cru_output_format
{
    CRU_OUTPUT_FORMAT_YUV420_YUYV       = 0,    ///< YUV420 YUYV 8bit
    CRU_OUTPUT_FORMAT_YUV420_UYVY       = 1,    ///< YUV420 UYVY 8bit
    CRU_OUTPUT_FORMAT_YUV422_YUYV       = 2,    ///< YUV422 YUYV 8bit
    CRU_OUTPUT_FORMAT_YUV422_UYVY       = 3,    ///< YUV422 UYVY 8bit
    CRU_OUTPUT_FORMAT_YUV422_YC         = 4,    ///< YUV422 YC separation
    CRU_OUTPUT_FORMAT_YUV422_Y          = 5,    ///< YUV422 Y only
    CRU_OUTPUT_FORMAT_RGB888_24BIT      = 6,    ///< RGB888 24BIT
    CRU_OUTPUT_FORMAT_RGB888_32BIT      = 7,    ///< RGB888 32BIT (Upper 8bit is 0x00)
    CRU_OUTPUT_FORMAT_ARGB8888          = 8,    ///< ARGB8888
    CRU_OUTPUT_FORMAT_BGRA8888          = 9,    ///< BGRA888
} cru_output_format_t;

typedef enum e_cru_datalane
{
    CRU_DATALANE_1     = 1,        ///< use one datalane
    CRU_DATALANE_2     = 2,        ///< use two datalane
    CRU_DATALANE_4     = 4         ///< use four datalane
} cru_datalane_t;

typedef enum e_cru_mbvalid
{
    CRU_1_MB_VALID     = 0x1,        ///< one transfer destination
    CRU_4_MB_VALID     = 0xF,        ///< four transfer destinations
    CRU_8_MB_VALID     = 0xFF,       ///< eight transfer destinations
} cru_mbvalid_t;

typedef enum e_cru_width
{
    CRU_W1920     = 1920,
    CRU_W1280     = 1280,
} cru_width_t;

typedef enum e_cru_height
{
    CRU_H1080     = 1080,
    CRU_H720     = 720,
} cru_height_t;

/** CRU events table for image conv int */
typedef enum e_cru_event_image_conv_int
{
    CRU_EVENT_FRAME_START   = 0x0001,    ///< Interrupt for Frame Start
    CRU_EVENT_FRAME_END     = 0x0002,    ///< Interrupt for Frame End
    CRU_EVENT_SCAN_LINE     = 0x0004,    ///< Interrupt for Scan Line
} cru_event_image_conv_int_t;
 
/** Callback function parameter data */
typedef struct st_cru_callback_args
{
    uint32_t event;
    uint32_t buf_index;
} cru_callback_args_t;

/** buffer address */
typedef struct st_cru_buffer_address
{
    uint8_t                     * p_buffer0;        ///< Pointer to buffer1 to write image into
    uint8_t                     * p_buffer1;        ///< Pointer to buffer2 to write image into
    uint8_t                     * p_buffer2;        ///< Pointer to buffer3 to write image into
    uint8_t                     * p_buffer3;        ///< Pointer to buffer4 to write image into
    uint8_t                     * p_buffer4;        ///< Pointer to buffer5 to write image into
    uint8_t                     * p_buffer5;        ///< Pointer to buffer6 to write image into
    uint8_t                     * p_buffer6;        ///< Pointer to buffer7 to write image into
    uint8_t                     * p_buffer7;        ///< Pointer to buffer8 to write image into
} cru_buffer_address_t;

/** CAMERA status */
typedef struct e_cru_status_t
{
    uint32_t     * p_buffer;           ///< Pointer to active buffer
    uint32_t       buf_index;
} cru_status_t;

/** CRU Configuration */
typedef struct st_cru_cfg
{
    void (* p_callback)(cru_callback_args_t * p_args);

    /** Placeholder for user data.  Passed to the user callback in @ref cru_callback_args_t. */
    void const * p_context;
    cru_input_format_t input_format;
    cru_output_format_t output_format;
    cru_width_t width;
    cru_height_t height;
    cru_datalane_t datalane;
    cru_mbvalid_t  mbvalid;
    uint8_t   cycle_end_ipl;              ///< Cycle end interrupt priority
    IRQn_Type cycle_end_irq;              ///< Cycle end interrupt
    cru_buffer_address_t  *p_buffer_addr;
} cru_cfg_t;

/** CRU control block.  Allocate an instance specific control block to pass into the CEC API calls.
 * @par Implemented as
 * - cru_instance_ctrl_t
 */
typedef void cru_ctrl_t;

/** Shared Interface definition for CRU */
typedef struct st_cru_api
{
    /** Open function for CRU
     * @par Implemented as
     * - @ref R_CRU_Open()
     *
     * @param[in,out]  p_ctrl           Pointer to the CRU control block. Must be declared by user. Value set here.
     * @param[in]      p_cfg            Pointer to CRU configuration structure. All elements of this structure must be set by user.
     */
    fsp_err_t (* open)(cru_ctrl_t * const p_ctrl, cru_cfg_t const * const p_cfg);

    /** Stream image.
     * @par Implemented as
     * - @ref R_CRU_Stream()
     *
     * @param[in]     p_ctrl            Pointer to CRU instance control block.
     * @param[out]    enable            Enable/Disable streaming.
     */
    fsp_err_t (* s_stream)(cru_ctrl_t * const p_ctrl, uint32_t enable);

    /** Close function for CRU device
     * @par Implemented as
     * - @ref R_CRU_Close()
     *
     * @param[in]     p_ctrl            Pointer to CRU instance control block
     */
    fsp_err_t (* close)(cru_ctrl_t * const p_ctrl);

    /** Check status CRU
     * @par Implemented as
     * - @ref R_CRU_Status()
     *
     * @param[in]     p_ctrl            Pointer to CRU instance control block
     */
    fsp_err_t (* status)(cru_ctrl_t * const p_ctrl, cru_status_t * p_buffer_status);
} cru_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_cru_instance
{
    cru_ctrl_t      * p_ctrl;          ///< Pointer to the control structure for this instance
    cru_cfg_t const * p_cfg;           ///< Pointer to the configuration structure for this instance
    cru_api_t const * p_api;           ///< Pointer to the API structure for this instance
} cru_instance_t;

/*******************************************************************************************************************//**
 * @} (end addtogroup CRU_API)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
