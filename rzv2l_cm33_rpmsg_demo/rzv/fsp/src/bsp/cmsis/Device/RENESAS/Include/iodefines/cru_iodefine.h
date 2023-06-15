/***********************************************************************************************************************
 * Copyright 2022 Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics Corporation and/or its affiliates and may only
 * be used with products of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.
 * Renesas products are sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for
 * the selection and use of Renesas products and Renesas assumes no liability.  No license, express or implied, to any
 * intellectual property right is granted by Renesas.  This software is protected under all applicable laws, including
 * copyright laws. Renesas reserves the right to change or discontinue this software and/or this documentation.
 * THE SOFTWARE AND DOCUMENTATION IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND
 * TO THE FULLEST EXTENT PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY,
 * INCLUDING WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE
 * SOFTWARE OR DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR
 * DOCUMENTATION (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER,
 * INCLUDING, WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY
 * LOST PROFITS, OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * File Name    : cru_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for cru.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef CRU_IODEFINE_H
#define CRU_IODEFINE_H

typedef struct
{
    /* H'000 */
    union
    {
        __IM uint32_t CSI2nMCG;
        struct
        {
            __IM uint32_t  VER    : 4;
            uint32_t              : 4;
            __IM uint32_t SDLN    : 4;
            uint32_t              : 4;
            __IM uint32_t GSNM    : 8;
            uint32_t              : 8;
        } CSI2nMCG_b;
    };

    __IM uint32_t RESERVED[3];
    /* H'010 */
    union
    {
        __IOM uint32_t CSI2nMCT0;
        struct
        {
            __IOM uint32_t VDLN   : 4;
            uint32_t              : 4;
            uint32_t              : 8;
            __IOM uint32_t ZLMD   : 1;
            __IOM uint32_t EDMD   : 1;
            uint32_t              : 1;
            __IOM uint32_t RVMD   : 1;
            uint32_t              : 4;
            __IOM uint32_t ECCV13  : 1;
            __IOM uint32_t LFSREN : 1;
            uint32_t              : 6;
        } CSI2nMCT0_b;
    };

    /* H'014 */
    __IM uint32_t RESERVED1;
    /* H'018 */
    union
    {
        __IOM uint32_t CSI2nMCT2;
        struct
        {
            __IOM uint32_t FRRCLK : 9;
            uint32_t              : 7;
            __IOM uint32_t FRRSKW  : 9;
            uint32_t              : 7;
        } CSI2nMCT2_b;
    };

    /* H'01C */
    union
    {
        __IOM uint32_t CSI2nMCT3;
        struct
        {
            __IOM uint32_t RXEN : 1;
            uint32_t            : 7;
            uint32_t            : 8;
            uint32_t            : 8;
            uint32_t            : 8;
        } CSI2nMCT3_b;
    };

    __IM uint32_t RESERVED2[2];
    /* H'028 */
    union
    {
        __IOM uint32_t CSI2nRTCT;
        struct
        {
            __IOM uint32_t VSRST    : 1;
            uint32_t                : 7;
            uint32_t                : 8;
            uint32_t                : 8;
            uint32_t                : 8;
        } CSI2nRTCT_b;
    };

    /* H'02C */
    union
    {
        __IM uint32_t CSI2nRTST;
        struct
        {
            __IM uint32_t VSRSTS    : 1;
            uint32_t                : 7;
            uint32_t                : 8;
            uint32_t                : 8;
            uint32_t                : 8;
        } CSI2nRTST_b;
    };

    /* H'030 */
    __IM uint32_t RESERVED3;
    __IM uint32_t RESERVED4[3];
    /* H'040 */
    union
    {
        __IOM uint32_t CSI2nEPCT;
        struct
        {
            __IOM uint32_t SLP   : 15;
            __IOM uint32_t EPDOP : 1;
            __IOM uint32_t SSP   : 15;
            __IOM uint32_t EPDEN  : 1;
        } CSI2nEPCT_b;
    };

    __IM uint32_t RESERVED5[3];
    /* H'050 */
    union
    {
        __IM uint32_t CSI2nMIST;
        struct
        {
            __IM uint32_t DL0S  : 1;
            __IM uint32_t DL1S  : 1;
            __IM uint32_t DL2S  : 1;
            __IM uint32_t DL3S  : 1;
            uint32_t            : 4;
            __IM uint32_t PMS   : 1;
            __IM uint32_t GSTS  : 1;
            __IM uint32_t RXS   : 1;
            uint32_t            : 5;
            __IM uint32_t VC0S  : 1;
            __IM uint32_t VC1S  : 1;
            __IM uint32_t VC2S  : 1;
            __IM uint32_t VC3S  : 1;
            uint32_t            : 4;
            uint32_t            : 8;
        } CSI2nMIST_b;
    };

    __IM uint32_t RESERVED6[3];
    /* H'060 */
    union
    {
        __IOM uint32_t CSI2nDTEL;
        struct
        {
            uint32_t                    : 8;
            __IOM uint32_t GSPC1        : 1;        /*Generic Short Packet Code 1*/
            __IOM uint32_t GSPC2        : 1;
            __IOM uint32_t GSPC3        : 1;
            __IOM uint32_t GSPC4        : 1;
            __IOM uint32_t GSPC5        : 1;
            __IOM uint32_t GSPC6        : 1;
            __IOM uint32_t GSPC7        : 1;
            __IOM uint32_t GSPC8        : 1;
            uint32_t                    : 3;
            __IOM uint32_t GLPT1        : 1;        /*Generic long packet data type 1*/
            __IOM uint32_t GLPT2        : 1;
            __IOM uint32_t GLPT3        : 1;
            __IOM uint32_t GLPT4        : 1;
            uint32_t                    : 1;
            __IOM uint32_t YUV420_8bit  : 1;
            __IOM uint32_t YUV420_10bit : 1;
            __IOM uint32_t LYUV420_8bit : 1;        /*Legacy YUV420 8-bit*/
            uint32_t                    : 1;
            __IOM uint32_t SYUV420_8bit : 1;        /*Chorma Shifted Pixel Sampling*/
            __IOM uint32_t SYUV420_10bit : 1;
            __IOM uint32_t YUV422_8bit  : 1;
            __IOM uint32_t YUV422_10bit : 1;
        } CSI2nDTEL_b;
    };

    /* H'064 */
    union
    {
        __IOM uint32_t CSI2nDTEH;
        struct
        {
            __IOM uint32_t RGB444       : 1;
            __IOM uint32_t RGB555       : 1;
            __IOM uint32_t RGB565       : 1;
            __IOM uint32_t RGB666       : 1;
            __IOM uint32_t RGB888       : 1;
            uint32_t                    : 3;
            __IOM uint32_t RAW6         : 1;
            __IOM uint32_t RAW7         : 1;
            __IOM uint32_t RAW8         : 1;
            __IOM uint32_t RAW10        : 1;
            __IOM uint32_t RAW12        : 1;
            __IOM uint32_t RAW14        : 1;
            __IOM uint32_t RAW16        : 1;
            __IOM uint32_t RAW20        : 1;
            __IOM uint32_t User8bit1    : 1;        /*User Defined 8-bit Data Type 1*/
            __IOM uint32_t User8bit2    : 1;
            __IOM uint32_t User8bit3    : 1;
            __IOM uint32_t User8bit4    : 1;
            __IOM uint32_t User8bit5    : 1;
            __IOM uint32_t User8bit6    : 1;
            __IOM uint32_t User8bit7    : 1;
            __IOM uint32_t User8bit8    : 1;
            uint32_t                    : 8;
        } CSI2nDTEH_b;
    };

    __IM uint32_t RESERVED7[1];
    /* H'070 */
    union
    {
        __IM uint32_t CSI2nRXST;
        struct
        {
            __IM uint32_t FRM0       : 1;
            __IM uint32_t FRM1       : 1;
            __IM uint32_t FRM2       : 1;
            __IM uint32_t FRM3       : 1;
            uint32_t                 : 4;
            uint32_t                 : 8;
            __IM uint32_t RACT       : 1;
            __IM uint32_t RACTDET    : 1;
            uint32_t                 : 6;
            uint32_t                 : 8;
        } CSI2nRXST_b;
    };

    /* H'074 */
    union
    {
        __IOM uint32_t CSI2nRXSC;
        struct
        {
            uint32_t                 : 8;
            uint32_t                 : 8;
            uint32_t                 : 1;
            __IOM uint32_t RACTDETC  : 1;
            uint32_t                 : 6;
            uint32_t                 : 8;
        } CSI2nRXSC_b;
    };

    /* H'078 */
    union
    {
        __IOM uint32_t CSI2nRXIE;
        struct
        {
            uint32_t                 : 8;
            uint32_t                 : 8;
            uint32_t                 : 1;
            __IOM uint32_t RACTDETE  : 1;
            uint32_t                 : 6;
            uint32_t                 : 8;
        } CSI2nRXIE_b;
    };

    __IM uint32_t RESERVED8;
    /* H'080 */
    union
    {
        __IM uint32_t CSI2nDLST0;
        struct
        {
            __IM uint32_t ESH  : 1;
            __IM uint32_t ESS  : 1;
            __IM uint32_t ECT  : 1;
            __IM uint32_t EES  : 1;
            uint32_t           : 4;
            uint32_t           : 8;
            __IM uint32_t EUL  : 1;
            __IM uint32_t RUL  : 1;
            uint32_t           : 6;
            __IM uint32_t ULP  : 1;
            uint32_t           : 7;
        } CSI2nDLST0_b;
    };

    /* H'084 */
    union
    {
        __IOM uint32_t CSI2nDLSC0;
        struct
        {
            __IOM uint32_t ESHC  : 1;
            __IOM uint32_t ESSC  : 1;
            __IOM uint32_t ECTC  : 1;
            __IOM uint32_t EESC  : 1;
            uint32_t             : 4;
            uint32_t             : 8;
            __IOM uint32_t EULC  : 1;
            __IOM uint32_t RULC  : 1;
            uint32_t             : 6;
            uint32_t             : 8;
        } CSI2nDLSC0_b;
    };

    /* H'088 */
    union
    {
        __IOM uint32_t CSI2nDLIE0;
        struct
        {
            __IOM uint32_t ESHE  : 1;
            __IOM uint32_t ESSE  : 1;
            __IOM uint32_t ECTE  : 1;
            __IOM uint32_t EESE  : 1;
            uint32_t             : 4;
            uint32_t             : 8;
            __IOM uint32_t EULE  : 1;
            __IOM uint32_t RULE  : 1;
            uint32_t             : 6;
            uint32_t             : 8;
        } CSI2nDLIE0_b;
    };

    __IM uint32_t RESERVED9;
    /* H'090 */
    union
    {
        __IM uint32_t CSI2nDLST1;
        struct
        {
            __IM uint32_t ESH  : 1;
            __IM uint32_t ESS  : 1;
            __IM uint32_t ECT  : 1;
            __IM uint32_t EES  : 1;
            uint32_t           : 4;
            uint32_t           : 8;
            __IM uint32_t EUL  : 1;
            __IM uint32_t RUL  : 1;
            uint32_t           : 6;
            __IM uint32_t ULP  : 1;
            uint32_t           : 7;
        } CSI2nDLST1_b;
    };

    /* H'094 */
    union
    {
        __IOM uint32_t CSI2nDLSC1;
        struct
        {
            __IOM uint32_t ESHC  : 1;
            __IOM uint32_t ESSC  : 1;
            __IOM uint32_t ECTC  : 1;
            __IOM uint32_t EESC  : 1;
            uint32_t             : 4;
            uint32_t             : 8;
            __IOM uint32_t EULC  : 1;
            __IOM uint32_t RULC  : 1;
            uint32_t             : 6;
            uint32_t             : 8;
        } CSI2nDLSC1_b;
    };

    /* H'098 */
    union
    {
        __IOM uint32_t CSI2nDLIE1;
        struct
        {
            __IOM uint32_t ESHE  : 1;
            __IOM uint32_t ESSE  : 1;
            __IOM uint32_t ECTE  : 1;
            __IOM uint32_t EESE  : 1;
            uint32_t             : 4;
            uint32_t             : 8;
            __IOM uint32_t EULE  : 1;
            __IOM uint32_t RULE  : 1;
            uint32_t             : 6;
            uint32_t             : 8;
        } CSI2nDLIE1_b;
    };

    __IM uint32_t RESERVED10;
    /* H'0A0 */
    union
    {
        __IM uint32_t CSI2nDLST2;
        struct
        {
            __IM uint32_t ESH  : 1;
            __IM uint32_t ESS  : 1;
            __IM uint32_t ECT  : 1;
            __IM uint32_t EES  : 1;
            uint32_t           : 4;
            uint32_t           : 8;
            __IM uint32_t EUL  : 1;
            __IM uint32_t RUL  : 1;
            uint32_t           : 6;
            __IM uint32_t ULP  : 1;
            uint32_t           : 7;
        } CSI2nDLST2_b;
    };

    /* H'0A4 */
    union
    {
        __IOM uint32_t CSI2nDLSC2;
        struct
        {
            __IOM uint32_t ESHC  : 1;
            __IOM uint32_t ESSC  : 1;
            __IOM uint32_t ECTC  : 1;
            __IOM uint32_t EESC  : 1;
            uint32_t             : 4;
            uint32_t             : 8;
            __IOM uint32_t EULC  : 1;
            __IOM uint32_t RULC  : 1;
            uint32_t             : 6;
            uint32_t             : 8;
        } CSI2nDLSC2_b;
    };

    /* H'0A8 */
    union
    {
        __IOM uint32_t CSI2nDLIE2;
        struct
        {
            __IOM uint32_t ESHE  : 1;
            __IOM uint32_t ESSE  : 1;
            __IOM uint32_t ECTE  : 1;
            __IOM uint32_t EESE  : 1;
            uint32_t             : 4;
            uint32_t             : 8;
            __IOM uint32_t EULE  : 1;
            __IOM uint32_t RULE  : 1;
            uint32_t             : 6;
            uint32_t             : 8;
        } CSI2nDLIE2_b;
    };

    __IM uint32_t RESERVED11;
    /* H'0B0 */
    union
    {
        __IM uint32_t CSI2nDLST3;
        struct
        {
            __IM uint32_t ESH  : 1;
            __IM uint32_t ESS  : 1;
            __IM uint32_t ECT  : 1;
            __IM uint32_t EES  : 1;
            uint32_t           : 4;
            uint32_t           : 8;
            __IM uint32_t EUL  : 1;
            __IM uint32_t RUL  : 1;
            uint32_t           : 6;
            __IM uint32_t ULP  : 1;
            uint32_t           : 7;
        } CSI2nDLST3_b;
    };

    /* H'0B4 */
    union
    {
        __IOM uint32_t CSI2nDLSC3;
        struct
        {
            __IOM uint32_t ESHC  : 1;
            __IOM uint32_t ESSC  : 1;
            __IOM uint32_t ECTC  : 1;
            __IOM uint32_t EESC  : 1;
            uint32_t             : 4;
            uint32_t             : 8;
            __IOM uint32_t EULC  : 1;
            __IOM uint32_t RULC  : 1;
            uint32_t             : 6;
            uint32_t             : 8;
        } CSI2nDLSC3_b;
    };

    /* H'0B8 */
    union
    {
        __IOM uint32_t CSI2nDLIE3;
        struct
        {
            __IOM uint32_t ESHE  : 1;
            __IOM uint32_t ESSE  : 1;
            __IOM uint32_t ECTE  : 1;
            __IOM uint32_t EESE  : 1;
            uint32_t             : 4;
            uint32_t             : 8;
            __IOM uint32_t EULE  : 1;
            __IOM uint32_t RULE  : 1;
            uint32_t             : 6;
            uint32_t             : 8;
        } CSI2nDLIE3_b;
    };

    __IM uint32_t RESERVED12[17];
    /* H'100 */
    union
    {
        __IM uint32_t CSI2nVCST0;
        struct
        {
            __IM uint32_t MLF  : 1;
            __IM uint32_t ECD  : 1;
            __IM uint32_t CRC  : 1;
            __IM uint32_t IDE  : 1;
            __IM uint32_t WCE  : 1;
            __IM uint32_t ECC  : 1;
            __IM uint32_t ECN  : 1;
            uint32_t           : 1;
            __IM uint32_t FRS  : 1;
            __IM uint32_t FRD  : 1;
            uint32_t           : 6;
            __IM uint32_t OVF  : 1;
            uint32_t           : 7;
            __IM uint32_t FSR  : 1;
            __IM uint32_t FER  : 1;
            __IM uint32_t LSR  : 1;
            __IM uint32_t LER  : 1;
            uint32_t           : 4;
        } CSI2nVCST0_b;
    };

    /* H'104 */
    union
    {
        __IOM uint32_t CSI2nVCSC0;
        struct
        {
            __IOM uint32_t MLFC  : 1;
            __IOM uint32_t ECDC  : 1;
            __IOM uint32_t CRCC  : 1;
            __IOM uint32_t IDEC  : 1;
            __IOM uint32_t WCEC  : 1;
            __IOM uint32_t ECCC  : 1;
            __IOM uint32_t ECNC  : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSC  : 1;
            __IOM uint32_t FRDC  : 1;
            uint32_t             : 4;
            __IOM uint32_t AMLFC : 1;
            __IOM uint32_t AECDC : 1;
            __IOM uint32_t OVFC  : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRC  : 1;
            __IOM uint32_t FERC  : 1;
            __IOM uint32_t LSRC  : 1;
            __IOM uint32_t LERC  : 1;
            uint32_t             : 4;
        } CSI2nVCSC0_b;
    };

    /* H'108 */
    union
    {
        __IOM uint32_t CSI2nVCIE0;
        struct
        {
            __IOM uint32_t MLFE  : 1;
            __IOM uint32_t ECDE  : 1;
            __IOM uint32_t CRCE  : 1;
            __IOM uint32_t IDEE  : 1;
            __IOM uint32_t WCEE  : 1;
            __IOM uint32_t ECCE  : 1;
            __IOM uint32_t ECNE  : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSE  : 1;
            __IOM uint32_t FRDE  : 1;
            uint32_t             : 6;
            __IOM uint32_t OVFE  : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRE  : 1;
            __IOM uint32_t FERE  : 1;
            __IOM uint32_t LSRE  : 1;
            __IOM uint32_t LERE  : 1;
            uint32_t             : 4;
        } CSI2nVCIE0_b;
    };

    __IM uint32_t RESERVED13;
    /* H'110 */
    union
    {
        __IM uint32_t CSI2nVCST1;
        struct
        {
            __IM uint32_t MLF  : 1;
            __IM uint32_t ECD  : 1;
            __IM uint32_t CRC  : 1;
            __IM uint32_t IDE  : 1;
            __IM uint32_t WCE  : 1;
            __IM uint32_t ECC  : 1;
            __IM uint32_t ECN  : 1;
            uint32_t           : 1;
            __IM uint32_t FRS  : 1;
            __IM uint32_t FRD  : 1;
            uint32_t           : 6;
            __IM uint32_t OVF  : 1;
            uint32_t           : 7;
            __IM uint32_t FSR  : 1;
            __IM uint32_t FER  : 1;
            __IM uint32_t LSR  : 1;
            __IM uint32_t LER  : 1;
            uint32_t           : 4;
        } CSI2nVCST1_b;
    };

    /* H'114 */
    union
    {
        __IOM uint32_t CSI2nVCSC1;
        struct
        {
            __IOM uint32_t MLFC  : 1;
            __IOM uint32_t ECDC  : 1;
            __IOM uint32_t CRCC  : 1;
            __IOM uint32_t IDEC  : 1;
            __IOM uint32_t WCEC  : 1;
            __IOM uint32_t ECCC  : 1;
            __IOM uint32_t ECNC  : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSC  : 1;
            __IOM uint32_t FRDC  : 1;
            uint32_t             : 4;
            __IOM uint32_t AMLFC : 1;
            __IOM uint32_t AECDC : 1;
            __IOM uint32_t OVFC  : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRC  : 1;
            __IOM uint32_t FERC  : 1;
            __IOM uint32_t LSRC  : 1;
            __IOM uint32_t LERC  : 1;
            uint32_t             : 4;
        } CSI2nVCSC1_b;
    };

    /* H'118 */
    union
    {
        __IOM uint32_t CSI2nVCIE1;
        struct
        {
            __IOM uint32_t MLFE  : 1;
            __IOM uint32_t ECDE  : 1;
            __IOM uint32_t CRCE  : 1;
            __IOM uint32_t IDEE  : 1;
            __IOM uint32_t WCEE  : 1;
            __IOM uint32_t ECCE  : 1;
            __IOM uint32_t ECNE  : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSE  : 1;
            __IOM uint32_t FRDE  : 1;
            uint32_t             : 6;
            __IOM uint32_t OVFE  : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRE  : 1;
            __IOM uint32_t FERE  : 1;
            __IOM uint32_t LSRE  : 1;
            __IOM uint32_t LERE  : 1;
            uint32_t             : 4;
        } CSI2nVCIE1_b;
    };

    __IM uint32_t RESERVED14;
    /* H'120 */
    union
    {
        __IM uint32_t CSI2nVCST2;
        struct
        {
            __IM uint32_t MLF  : 1;
            __IM uint32_t ECD  : 1;
            __IM uint32_t CRC  : 1;
            __IM uint32_t IDE  : 1;
            __IM uint32_t WCE  : 1;
            __IM uint32_t ECC  : 1;
            __IM uint32_t ECN  : 1;
            uint32_t           : 1;
            __IM uint32_t FRS  : 1;
            __IM uint32_t FRD  : 1;
            uint32_t           : 6;
            __IM uint32_t OVF  : 1;
            uint32_t           : 7;
            __IM uint32_t FSR  : 1;
            __IM uint32_t FER  : 1;
            __IM uint32_t LSR  : 1;
            __IM uint32_t LER  : 1;
            uint32_t           : 4;
        } CSI2nVCST2_b;
    };

    /* H'124 */
    union
    {
        __IOM uint32_t CSI2nVCSC2;
        struct
        {
            __IOM uint32_t MLFC  : 1;
            __IOM uint32_t ECDC  : 1;
            __IOM uint32_t CRCC  : 1;
            __IOM uint32_t IDEC  : 1;
            __IOM uint32_t WCEC  : 1;
            __IOM uint32_t ECCC  : 1;
            __IOM uint32_t ECNC  : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSC  : 1;
            __IOM uint32_t FRDC  : 1;
            uint32_t             : 4;
            __IOM uint32_t AMLFC : 1;
            __IOM uint32_t AECDC : 1;
            __IOM uint32_t OVFC  : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRC  : 1;
            __IOM uint32_t FERC  : 1;
            __IOM uint32_t LSRC  : 1;
            __IOM uint32_t LERC  : 1;
            uint32_t             : 4;
        } CSI2nVCSC2_b;
    };

    /* H'128 */
    union
    {
        __IOM uint32_t CSI2nVCIE2;
        struct
        {
            __IOM uint32_t MLFE  : 1;
            __IOM uint32_t ECDE  : 1;
            __IOM uint32_t CRCE  : 1;
            __IOM uint32_t IDEE  : 1;
            __IOM uint32_t WCEE  : 1;
            __IOM uint32_t ECCE  : 1;
            __IOM uint32_t ECNE  : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSE  : 1;
            __IOM uint32_t FRDE  : 1;
            uint32_t             : 6;
            __IOM uint32_t OVFE  : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRE  : 1;
            __IOM uint32_t FERE  : 1;
            __IOM uint32_t LSRE  : 1;
            __IOM uint32_t LERE  : 1;
            uint32_t             : 4;
        } CSI2nVCIE2_b;
    };

    __IM uint32_t RESERVED15;
    /* H'130 */
    union
    {
        __IM uint32_t CSI2nVCST3;
        struct
        {
            __IM uint32_t MLF  : 1;
            __IM uint32_t ECD  : 1;
            __IM uint32_t CRC  : 1;
            __IM uint32_t IDE  : 1;
            __IM uint32_t WCE  : 1;
            __IM uint32_t ECC  : 1;
            __IM uint32_t ECN  : 1;
            uint32_t           : 1;
            __IM uint32_t FRS  : 1;
            __IM uint32_t FRD  : 1;
            uint32_t           : 6;
            __IM uint32_t OVF  : 1;
            uint32_t           : 7;
            __IM uint32_t FSR  : 1;
            __IM uint32_t FER  : 1;
            __IM uint32_t LSR  : 1;
            __IM uint32_t LER  : 1;
            uint32_t           : 4;
        } CSI2nVCST3_b;
    };

    /* H'134 */
    union
    {
        __IOM uint32_t CSI2nVCSC3;
        struct
        {
            __IOM uint32_t MLFC  : 1;
            __IOM uint32_t ECDC  : 1;
            __IOM uint32_t CRCC  : 1;
            __IOM uint32_t IDEC  : 1;
            __IOM uint32_t WCEC  : 1;
            __IOM uint32_t ECCC  : 1;
            __IOM uint32_t ECNC  : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSC  : 1;
            __IOM uint32_t FRDC  : 1;
            uint32_t             : 4;
            __IOM uint32_t AMLFC : 1;
            __IOM uint32_t AECDC : 1;
            __IOM uint32_t OVFC  : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRC  : 1;
            __IOM uint32_t FERC  : 1;
            __IOM uint32_t LSRC  : 1;
            __IOM uint32_t LERC  : 1;
            uint32_t             : 4;
        } CSI2nVCSC3_b;
    };

    /* H'138 */
    union
    {
        __IOM uint32_t CSI2nVCIE3;
        struct
        {
            __IOM uint32_t MLFE  : 1;
            __IOM uint32_t ECDE  : 1;
            __IOM uint32_t CRCE  : 1;
            __IOM uint32_t IDEE  : 1;
            __IOM uint32_t WCEE  : 1;
            __IOM uint32_t ECCE  : 1;
            __IOM uint32_t ECNE  : 1;
            uint32_t             : 1;
            __IOM uint32_t FRSE  : 1;
            __IOM uint32_t FRDE  : 1;
            uint32_t             : 6;
            __IOM uint32_t OVFE  : 1;
            uint32_t             : 7;
            __IOM uint32_t FSRE  : 1;
            __IOM uint32_t FERE  : 1;
            __IOM uint32_t LSRE  : 1;
            __IOM uint32_t LERE  : 1;
            uint32_t             : 4;
        } CSI2nVCIE3_b;
    };

    __IM uint32_t RESERVED16[49];

    /* H'200 */
    union
    {
        __IM uint32_t CSI2nPMST;
        struct
        {
            __IM uint32_t DSX  : 1;
            __IM uint32_t DSN  : 1;
            __IM uint32_t CSX  : 1;
            __IM uint32_t CSN  : 1;
            __IM uint32_t DUX  : 1;
            __IM uint32_t DUN  : 1;
            __IM uint32_t CUX  : 1;
            __IM uint32_t CUN  : 1;
            uint32_t           : 6;
            __IM uint32_t CLSS : 1;
            __IM uint32_t CLUL : 1;
            __IM uint32_t DLSS : 4;
            uint32_t           : 4;
            __IM uint32_t DLUL : 4;
            uint32_t           : 4;
        } CSI2nPMST_b;
    };

    /* H'204 */
    union
    {
        __IOM uint32_t CSI2nPMSC;
        struct
        {
            __IOM uint32_t DSXC  : 1;
            __IOM uint32_t DSNC  : 1;
            __IOM uint32_t CSXC  : 1;
            __IOM uint32_t CSNC  : 1;
            __IOM uint32_t DUXC  : 1;
            __IOM uint32_t DUNC  : 1;
            __IOM uint32_t CUXC  : 1;
            __IOM uint32_t CUNC  : 1;
            uint32_t             : 8;
            uint32_t             : 8;
            uint32_t             : 8;
        } CSI2nPMSC_b;
    };

    /* H'208 */
    union
    {
        __IOM uint32_t CSI2nPMIE;
        struct
        {
            __IOM uint32_t DSXE  : 1;
            __IOM uint32_t DSNE  : 1;
            __IOM uint32_t CSXE  : 1;
            __IOM uint32_t CSNE  : 1;
            __IOM uint32_t DUXE  : 1;
            __IOM uint32_t DUNE  : 1;
            __IOM uint32_t CUXE  : 1;
            __IOM uint32_t CUNE  : 1;
            uint32_t             : 8;
            uint32_t             : 8;
            uint32_t             : 8;
        } CSI2nPMIE_b;
    };

    __IM uint32_t RESERVED17[29];
    /* H'280 */
    union
    {
        __IOM uint32_t CSI2nGSCT;
        struct
        {
            __IOM uint32_t SHTH  : 7;
            uint32_t             : 1;
            uint32_t             : 8;
            __IOM uint32_t GFIF  : 1;
            uint32_t             : 7;
            uint32_t             : 8;
        } CSI2nGSCT_b;
    };

    /* H'284 */
    union
    {
        __IM uint32_t CSI2nGSST;
        struct
        {
            __IM uint32_t GNE   : 1;
            __IM uint32_t GTH   : 1;
            uint32_t            : 2;
            __IM uint32_t GOV   : 1;
            uint32_t            : 3;
            __IM uint32_t PNUM  : 8;
            __IM uint32_t GCD   : 1;
            __IM uint32_t STRDS : 1;
            uint32_t            : 6;
            uint32_t            : 8;
        } CSI2nGSST_b;
    };

    /* H'288 */
    union
    {
        __IOM uint32_t CSI2nGSSC;
        struct
        {
            uint32_t             : 4;
            __IOM uint32_t GOVC  : 1;
            uint32_t             : 3;
            uint32_t             : 8;
            uint32_t             : 8;
            uint32_t             : 8;
        } CSI2nGSSC_b;
    };

    /* H'28C */
    union
    {
        __IOM uint32_t CSI2nGSIE;
        struct
        {
            __IOM uint32_t GNEE   : 1;
            __IOM uint32_t GTHE   : 1;
            uint32_t              : 2;
            __IOM uint32_t GOVE   : 1;
            uint32_t              : 3;
            uint32_t              : 8;
            uint32_t              : 8;
            uint32_t              : 8;
        } CSI2nGSIE_b;
    };

    /* H'290 */
    union
    {
        __IM uint32_t CSI2nGSHT;
        struct
        {
            __IM uint32_t SPDT   : 16;
            __IM uint32_t DTYP   : 6;
            uint32_t             : 2;
            __IM uint32_t SPVC   : 4;
            uint32_t             : 4;
        } CSI2nGSHT_b;
    };

    /* H'294 */
    union
    {
        __IOM uint32_t CSI2nGSIU;
        struct
        {
            __IOM uint32_t FINC   : 1;
            uint32_t              : 7;
            __IOM uint32_t GFCLR  : 1;
            uint32_t              : 7;
            __IOM uint32_t GFEN   : 1;
            uint32_t              : 7;
            uint32_t              : 8;
        } CSI2nGSIU_b;
    };

} R_CSI2_LINK_Type;

typedef struct
{
    /* H'00 */
    union
    {
        __IOM uint32_t CSIDPHYCTRL0;
        struct
        {
            __IOM uint32_t  EN_BGR       : 1;
            __IOM uint32_t  EN_LDO1200   : 1;
            uint32_t                       : 14;
            __IOM uint32_t CAL_EN_HSRX_OFS : 1;
            uint32_t                       : 15;
        } CSIDPHYCTRL0_b;
    };

    /* H'04 */
    union
    {
        __IOM uint32_t CSIDPHYTIM0;
        struct
        {
            __IOM uint32_t  T_INIT     : 19;
            uint32_t                   : 5;
            __IM uint32_t  EN_LDO1200  : 8;
        } CSIDPHYTIM0_b;
    };

    /* H'08 */
    union
    {
        __IOM uint32_t CSIDPHYTIM1;
        struct
        {
            __IOM uint32_t  TCLK_SETTLE  : 8;
            __IOM uint32_t  THS_SETTLE   : 8;
            __IOM uint32_t  TCLK_PREPARE : 8;
            __IOM uint32_t  THS_PREPARE  : 8;
        } CSIDPHYTIM1_b;
    };

    __IM uint32_t RESERVED[21];
    /* H'60 */
    union
    {
        __IOM uint32_t CSIDPHYSKW0;
        struct
        {
            __IOM uint32_t  UTIL_DL0_SKW_ADJ       : 3;
            uint32_t                               : 1;
            __IOM uint32_t  UTIL_DL1_SKW_ADJ       : 3;
            uint32_t                               : 1;
            __IOM uint32_t  UTIL_DL2_SKW_ADJ       : 3;
            uint32_t                               : 1;
            __IOM uint32_t  UTIL_DL3_SKW_ADJ       : 3;
            uint32_t                               : 1;
            uint32_t                               : 8;
            uint32_t                               : 8;
        } CSIDPHYSKW0_b;
    };
} R_CSI2_PHY_Type;

typedef struct
{
    /* H’0000 */
    union
    {
        __IOM uint32_t CRUnCTRL;
        struct
        {
            __IOM uint32_t  VINSEL   : 1;
            uint32_t                 : 7;
            uint32_t                 : 8;
            uint32_t                 : 8;
            uint32_t                 : 8;
        } CRUnCTRL_b;
    };

    /* H’0004 */
    union
    {
        __IOM uint32_t CRUnIE;
        struct
        {
            __IOM uint32_t  FOE      : 1;
            __IOM uint32_t  SLVEE    : 1;
            __IOM uint32_t  DECEE    : 1;
            __IOM uint32_t  FEOVWE   : 1;
            uint32_t                 : 4;
            __IOM uint32_t SDFOE    : 1;
            __IOM uint32_t SDSLVEE  : 1;
            __IOM uint32_t SDDECEE  : 1;
            __IOM uint32_t SDFEOVWE : 1;
            uint32_t                : 4;
            __IOM uint32_t  SFE      : 1;
            __IOM uint32_t  EFE      : 1;
            __IOM uint32_t  SIE      : 1;
            __IOM uint32_t  WIE      : 1;
            __IOM uint32_t  CEE      : 1;
            uint32_t                 : 3;
            uint32_t                 : 8;
        } CRUnIE_b;
    };

    /* H’0008 */
    union
    {
        __IOM uint32_t CRUnINTS;
        struct
        {
            __IOM uint32_t  FOS      : 1;
            __IOM uint32_t  SLVES    : 1;
            __IOM uint32_t  DECES    : 1;
            __IOM uint32_t  FEOVWS   : 1;
            uint32_t                 : 4;
            __IOM uint32_t SDFOS    : 1;
            __IOM uint32_t SDSLVES  : 1;
            __IOM uint32_t SDDECES  : 1;
            __IOM uint32_t SDFEOVWS : 1;
            uint32_t                : 4;
            __IOM uint32_t  SFS      : 1;
            __IOM uint32_t  EFS      : 1;
            __IOM uint32_t  SIS      : 1;
            __IOM uint32_t  WIS      : 1;
            __IOM uint32_t  CES      : 1;
            uint32_t                 : 3;
            uint32_t                 : 8;
        } CRUnINTS_b;
    };

    /* H’000C */
    union
    {
        __IOM uint32_t CRUnRST;
        struct
        {
            __IOM uint32_t  VRESETN   : 1;
            uint32_t                 : 7;
            uint32_t                 : 8;
            uint32_t                 : 8;
            uint32_t                 : 8;
        } CRUnRST_b;
    };

    /* Reserved H’000C-H’007F */
    __IM uint32_t RESERVED[28];
    /* H’0080 */
    union
    {
        __IOM uint32_t CRUnCOM;
        struct
        {
            __IOM uint32_t  COMMON      : 32;
        } CRUnCOM_b;
    };

    /* Reserved H’0084-H’00FF */
    __IM uint32_t RESERVED1[31];
    /* H’0100 */
    union
    {
        __IOM uint32_t AMnMB1ADDRL;
        struct
        {
            uint32_t                    : 9;
            __IOM uint32_t  MB1ADDRL    : 23;
        } AMnMB1ADDRL_b;
    };

    /* H’0104 */
    union
    {
        __IOM uint32_t AMnMB1ADDRH;
        struct
        {
            __IOM uint32_t  MB1ADDRH       : 2;
            uint32_t                       : 6;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMB1ADDRH_b;
    };

    /* H’0108 */
    union
    {
        __IOM uint32_t AMnMB2ADDRL;
        struct
        {
            uint32_t                    : 9;
            __IOM uint32_t  MB2ADDRL    : 23;
        } AMnMB2ADDRL_b;
    };

    /* H’010C */
    union
    {
        __IOM uint32_t AMnMB2ADDRH;
        struct
        {
            __IOM uint32_t  MB2ADDRH       : 2;
            uint32_t                       : 6;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMB2ADDRH_b;
    };

    /* H’0110 */
    union
    {
        __IOM uint32_t AMnMB3ADDRL;
        struct
        {
            uint32_t                    : 9;
            __IOM uint32_t  MB3ADDRL    : 23;
        } AMnMB3ADDRL_b;
    };

    /* H’0114 */
    union
    {
        __IOM uint32_t AMnMB3ADDRH;
        struct
        {
            __IOM uint32_t  MB3ADDRH       : 2;
            uint32_t                       : 6;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMB3ADDRH_b;
    };

    /* H’0118 */
    union
    {
        __IOM uint32_t AMnMB4ADDRL;
        struct
        {
            uint32_t                    : 9;
            __IOM uint32_t  MB4ADDRL    : 23;
        } AMnMB4ADDRL_b;
    };

    /* H’011C */
    union
    {
        __IOM uint32_t AMnMB4ADDRH;
        struct
        {
            __IOM uint32_t  MB4ADDRH       : 2;
            uint32_t                       : 6;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMB4ADDRH_b;
    };

    /* H’0120 */
    union
    {
        __IOM uint32_t AMnMB5ADDRL;
        struct
        {
            uint32_t                    : 9;
            __IOM uint32_t  MB5ADDRL    : 23;
        } AMnMB5ADDRL_b;
    };


    /* H’0124 */
    union
    {
        __IOM uint32_t AMnMB5ADDRH;
        struct
        {
            __IOM uint32_t  MB5ADDRH       : 2;
            uint32_t                       : 6;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMB5ADDRH_b;
    };

    /* H’0128 */
    union
    {
        __IOM uint32_t AMnMB6ADDRL;
        struct
        {
            uint32_t                    : 9;
            __IOM uint32_t  MB6ADDRL    : 23;
        } AMnMB6ADDRL_b;
    };

    /* H’012C */
    union
    {
        __IOM uint32_t AMnMB6ADDRH;
        struct
        {
            __IOM uint32_t  MB6ADDRH       : 2;
            uint32_t                       : 6;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMB6ADDRH_b;
    };

    /* H’0130 */
    union
    {
        __IOM uint32_t AMnMB7ADDRL;
        struct
        {
            uint32_t                    : 9;
            __IOM uint32_t  MB7ADDRL    : 23;
        } AMnMB7ADDRL_b;
    };

    /* H’0134 */
    union
    {
        __IOM uint32_t AMnMB7ADDRH;
        struct
        {
            __IOM uint32_t  MB7ADDRH       : 2;
            uint32_t                       : 6;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMB7ADDRH_b;
    };

    /* H’0138 */
    union
    {
        __IOM uint32_t AMnMB8ADDRL;
        struct
        {
            uint32_t                    : 9;
            __IOM uint32_t  MB8ADDRL    : 23;
        } AMnMB8ADDRL_b;
    };

    /* H’013C */
    union
    {
        __IOM uint32_t AMnMB8ADDRH;
        struct
        {
            __IOM uint32_t  MB8ADDRH       : 2;
            uint32_t                       : 6;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMB8ADDRH_b;
    };

    /* H’0140 */
    union
    {
        __IOM uint32_t AMnUVAOFL;
        struct
        {
            uint32_t                    : 9;
            __IOM uint32_t  UVAOFL    : 23;
        } AMnUVAOFL_b;
    };

    /* H’0144 */
    union
    {
        __IOM uint32_t AMnUVAOFH;
        struct
        {
            __IOM uint32_t  UVAOFH         : 3;
            uint32_t                       : 5;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnUVAOFH_b;
    };

    /* H’0148 */
    union
    {
        __IOM uint32_t AMnMBVALID;
        struct
        {
            __IOM uint32_t  MBVALID        : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMBVALID_b;
    };

    /* H’014C */
    union
    {
        __IOM uint32_t AMnMBS;
        struct
        {
            __IM uint32_t  MBSTS           : 3;
            uint32_t                       : 5;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnMBS_b;
    };

    /* Reserved H’0150-H’0154 */
    __IM uint32_t RESERVED2[2];
    /* H’0158 */
    union
    {
        __IOM uint32_t AMnAXIATTR;
        struct
        {
            __IOM uint32_t  AXILEN         : 4;
            uint32_t                       : 4;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnAXIATTR_b;
    };

    /* Reserved H’015C-H’015F */
    __IM uint32_t RESERVED3;
    /* H’0160 */
    union
    {
        __IOM uint32_t AMnFIFO;
        struct
        {
            __IOM uint32_t  FIFOOVFREC     : 1;
            uint32_t                       : 7;
            uint32_t                       : 8;
            uint32_t                       : 8;
            uint32_t                       : 8;
        } AMnFIFO_b;
    };

    /* H’0164 */
    union
    {
        __IOM uint32_t AMnFIFOTRST;
        struct
        {
            __IOM uint32_t  AXI_TRANS_START      : 1;
            uint32_t                             : 7;
            uint32_t                             : 8;
            uint32_t                             : 8;
            uint32_t                             : 8;
        } AMnFIFOTRST_b;
    };

    /* H’0168 */
    union
    {
        __IOM uint32_t AMnFIFOPNTR;
        struct
        {
            __IM uint32_t  FIFOWPNTR      : 8;
            uint32_t                      : 8;
            __IM uint32_t  FIFORPNTR_Y    : 8;
            __IM uint32_t  FIFORPNTR_UV   : 8;
        } AMnFIFOPNTR_b;
    };

    /* Reserved H’016C*/
    __IM uint32_t RESERVED4;
    /* Reserved H’0170*/
    union
    {
        __IOM uint32_t AMnAXIBID;
        struct
        {
            __IOM uint32_t BIDCHK : 1;
            uint32_t              : 31;
        } AMnAXIBID_b;
    };

    /* H’0174 */
    union
    {
        __IOM uint32_t AMnAXISTP;
        struct
        {
            __IOM uint32_t  AXI_STOP      : 1;
            uint32_t                      : 7;
            uint32_t                      : 8;
            uint32_t                      : 8;
            uint32_t                      : 8;
        } AMnAXISTP_b;
    };

    /* H’0178 */
    union
    {
        __IOM uint32_t AMnAXISTPACK;
        struct
        {
            __IM uint32_t  AXI_STOP_ACK      : 1;
            uint32_t                         : 7;
            uint32_t                         : 8;
            uint32_t                         : 8;
            uint32_t                         : 8;
        } AMnAXISTPACK_b;
    };

    /* Reserved H’017C - H'01FF*/
    __IM uint8_t RESERVED5[20];
    union
    {
        __IOM uint32_t AMnSDMB1ADDRL;
        struct
        {
            uint32_t                  : 8;
            __IOM uint32_t SDMB1ADDRL : 24;
        } AMnSDMB1ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB1ADDRH;
        struct
        {
            __IOM uint32_t SDMB1ADDRH : 3;
            uint32_t                  : 29;
        } AMnSDMB1ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB2ADDRL;
        struct
        {
            uint32_t                  : 8;
            __IOM uint32_t SDMB2ADDRL : 24;
        } AMnSDMB2ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB2ADDRH;
        struct
        {
            __IOM uint32_t SDMB2ADDRH : 3;
            uint32_t                  : 29;
        } AMnSDMB2ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB3ADDRL;
        struct
        {
            uint32_t                  : 8;
            __IOM uint32_t SDMB3ADDRL : 24;
        } AMnSDMB3ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB3ADDRH;
        struct
        {
            __IOM uint32_t SDMB3ADDRH : 3;
            uint32_t                  : 29;
        } AMnSDMB3ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB4ADDRL;
        struct
        {
            uint32_t                  : 8;
            __IOM uint32_t SDMB4ADDRL : 24;
        } AMnSDMB4ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB4ADDRH;
        struct
        {
            __IOM uint32_t SDMB4ADDRH : 3;
            uint32_t                  : 29;
        } AMnSDMB4ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB5ADDRL;
        struct
        {
            uint32_t                  : 8;
            __IOM uint32_t SDMB5ADDRL : 24;
        } AMnSDMB5ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB5ADDRH;
        struct
        {
            __IOM uint32_t SDMB5ADDRH : 3;
            uint32_t                  : 29;
        } AMnSDMB5ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB6ADDRL;
        struct
        {
            uint32_t                  : 8;
            __IOM uint32_t SDMB6ADDRL : 24;
        } AMnSDMB6ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB6ADDRH;
        struct
        {
            __IOM uint32_t SDMB6ADDRH : 3;
            uint32_t                  : 29;
        } AMnSDMB6ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB7ADDRL;
        struct
        {
            uint32_t                  : 8;
            __IOM uint32_t SDMB7ADDRL : 24;
        } AMnSDMB7ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB7ADDRH;
        struct
        {
            __IOM uint32_t SDMB7ADDRH : 3;
            uint32_t                  : 29;
        } AMnSDMB7ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB8ADDRL;
        struct
        {
            uint32_t                  : 8;
            __IOM uint32_t SDMB8ADDRL : 24;
        } AMnSDMB8ADDRL_b;
    };
    union
    {
        __IOM uint32_t AMnSDMB8ADDRH;
        struct
        {
            __IOM uint32_t SDMB8ADDRH : 3;
            uint32_t                  : 29;
        } AMnSDMB8ADDRH_b;
    };
    union
    {
        __IOM uint32_t AMnSDMBVALID;
        struct
        {
            __IOM uint32_t SDMBVALID : 8;
            uint32_t                 : 24;
        } AMnSDMBVALID_b;
    };
    union
    {
        __IM uint32_t AMnSDMBS;
        struct
        {
            __IM uint32_t SDMBSTS : 3;
            uint32_t              : 29;
        } AMnSDMBS_b;
    };
    union
    {
        __IOM uint32_t AMnSDAXIATTR;
        struct
        {
            __IOM uint32_t SDAXILEN : 4;
            uint32_t                : 3;
            uint32_t                : 1;
            uint32_t                : 2;
            uint32_t                : 2;
            uint32_t                : 2;
            uint32_t                : 2;
            uint32_t                : 7;
            uint32_t                : 1;
            uint32_t                : 4;
            uint32_t                : 4;
        } AMnSDAXIATTR_b;
    };
    __IM uint8_t RESERVED6[4];
    union
    {
        __IOM uint32_t AMnSDFIFO;
        struct
        {
            __IOM uint32_t SDFIFOOVFREC : 1;
            uint32_t                    : 31;
        } AMnSDFIFO_b;
    };
    union
    {
        __IOM uint32_t AMnSDFIFOTRST;
        struct
        {
            __IOM uint32_t SDAXI_TRANS_START : 1;
            uint32_t                         : 31;
        } AMnSDFIFOTRST_b;
    };
    union
    {
        __IM uint32_t AMnSDFIFOPNTR;
        struct
        {
            __IM uint32_t SDFIFOWPNTR : 5;
            uint32_t                  : 11;
            __IM uint32_t SDFIFORPNTR : 5;
            uint32_t                  : 11;
        } AMnSDFIFOPNTR_b;
    };
    __IM uint8_t RESERVED7[4];
    union
    {
        __IOM uint32_t AMnSDAXIBID;
        struct
        {
            __IOM uint32_t SDBIDCHK : 1;
            uint32_t                : 31;
        } AMnSDAXIBID_b;
    };
    union
    {
        __IOM uint32_t AMnSDAXISTP;
        struct
        {
            __IOM uint32_t SD_AXI_STOP : 1;
            uint32_t                   : 31;
        } AMnSDAXISTP_b;
    };
    union
    {
        __IM uint32_t AMnSDAXISTPACK;
        struct
        {
            __IM uint32_t SD_AXI_STOP_ACK : 1;
            uint32_t                      : 31;
        } AMnSDAXISTPACK_b;
    };
    __IM uint8_t RESERVED60[4];

    /* H’0200 */
    union
    {
        __IOM uint32_t ICnEN;
        struct
        {
            __IOM uint32_t  ICEN      : 1;
            uint32_t                  : 7;
            uint32_t                  : 8;
            uint32_t                  : 8;
            uint32_t                  : 8;
        } ICnEN_b;
    };

    /* H’0204 */
    union
    {
        __IOM uint32_t ICnREGC;
        struct
        {
            __IOM uint32_t  REFEN      : 1;
            uint32_t                   : 7;
            uint32_t                   : 8;
            uint32_t                   : 8;
            uint32_t                   : 8;
        } ICnREGC_b;
    };

    /* H’0208 */
    union
    {
        __IOM uint32_t ICnMC;
        struct
        {
            __IOM uint32_t  ICTHR      : 1;
            __IOM uint32_t  DECTHR     : 1;
            __IOM uint32_t  CLPTHR     : 1;
            __IOM uint32_t DEMTHR   : 1;
            __IOM uint32_t LMXTHR   : 1;
            __IOM uint32_t  CSCTHR     : 1;
            __IOM uint32_t  LUTTHR     : 1;
            __IOM uint32_t STITHR   : 1;
            uint32_t                : 4;
            __IOM uint32_t  CLP        : 2;
            __IOM uint32_t  IBINSEL    : 1;
            __IOM uint32_t DES0     : 1;
            __IOM uint32_t  INF        : 6;
            __IOM uint32_t  VCSEL      : 2;
            __IOM uint32_t RAWSTTYP : 2;
            uint32_t                : 6;
        } ICnMC_b;
    };

    __IM uint32_t RESERVED10;

    /* H’0210 */
    union
    {
        __IOM uint32_t ICnSLPrC;
        struct
        {
            __IOM uint32_t SLPrC    :12;
            uint32_t                :4;
            uint32_t                :16;
        } ICnSLPrC_b;
    };

    /* H’0214 */
    union
    {
        __IOM uint32_t ICnELPrC;
        struct
        {
            __IOM uint32_t ELPrC    :12;
            uint32_t                :4;
            uint32_t                :16;
        } ICnELPrC_b;
    };

    /* H’0218 */
    union
    {
        __IOM uint32_t ICnSPPrC;
        struct
        {
            __IOM uint32_t SPPrC    :12;
            uint32_t                :4;
            uint32_t                :16;
        } ICnSPPrC_b;
    };

    /* H’021C */
    union
    {
        __IOM uint32_t ICnEPPrC;
        struct
        {
            __IOM uint32_t EPPrC    :12;
            uint32_t                :4;
            uint32_t                :16;
        } ICnEPPrC_b;
    };

    /* H’0220 */
    union
    {
        __IOM uint32_t ICnSI;
        struct
        {
            __IOM uint32_t SI    :12;
            uint32_t                :4;
            uint32_t                :16;
        } ICnSI_b;
    };

    /* Reserved H’0224 - H'024C*/
    union
    {
        __IOM uint32_t ICnLMXOF;
        struct
        {
            __IOM uint32_t ROF : 8;
            __IOM uint32_t GOF : 8;
            __IOM uint32_t BOF : 8;
            uint32_t           : 8;
        } ICnLMXOF_b;
    };
    union
    {
        __IOM uint32_t ICnLMXRC1;
        struct
        {
            __IOM uint32_t RR : 13;
            uint32_t          : 19;
        } ICnLMXRC1_b;
    };
    union
    {
        __IOM uint32_t ICnLMXRC2;
        struct
        {
            __IOM uint32_t RG : 13;
            uint32_t          : 3;
            __IOM uint32_t RB : 13;
            uint32_t          : 3;
        } ICnLMXRC2_b;
    };
    union
    {
        __IOM uint32_t ICnLMXGC1;
        struct
        {
            __IOM uint32_t GR : 13;
            uint32_t          : 19;
        } ICnLMXGC1_b;
    };
    union
    {
        __IOM uint32_t ICnLMXGC2;
        struct
        {
            __IOM uint32_t GG : 13;
            uint32_t          : 3;
            __IOM uint32_t GB : 13;
            uint32_t          : 3;
        } ICnLMXGC2_b;
    };
    union
    {
        __IOM uint32_t ICnLMXBC1;
        struct
        {
            __IOM uint32_t BR : 13;
            uint32_t          : 19;
        } ICnLMXBC1_b;
    };
    union
    {
        __IOM uint32_t ICnLMXBC2;
        struct
        {
            __IOM uint32_t BG : 13;
            uint32_t          : 3;
            __IOM uint32_t BB : 13;
            uint32_t          : 3;
        } ICnLMXBC2_b;
    };
    union
    {
        __IOM uint32_t ICnSTIC1;
        struct
        {
            __IOM uint32_t STUNIT   : 2;
            uint32_t                : 14;
            __IOM uint32_t STSADPOS : 4;
            uint32_t                : 12;
        } ICnSTIC1_b;
    };
    union
    {
        __IOM uint32_t ICnSTIC2;
        struct
        {
            __IOM uint32_t STHPOS   : 9;
            uint32_t                : 23;
        } ICnSTIC2_b;
    };
    __IM uint8_t RESERVED70[8];

    /* H’0250 */
    union
    {
        __IOM uint32_t ICnPIFC;
        struct
        {
            __IOM uint32_t  PINF       : 4;
            uint32_t                   : 4;
            __IOM uint32_t  ITL        : 3;
            uint32_t                   : 1;
            __IOM uint32_t  EC         : 1;
            __IOM uint32_t  VSPOL      : 1;
            __IOM uint32_t  ENPOL      : 1;
            uint32_t                   : 1;
            uint32_t                   : 8;
            uint32_t                   : 8;
        } ICnPIFC_b;
    };

    /* H’0254 */
    union
    {
        __IOM uint32_t ICnMS;
        struct
        {
            __IM uint32_t  CA       : 1;
            __IM uint32_t  AV       : 1;
            __IM uint32_t  IA       : 1;
            uint32_t                : 5;
            uint32_t                : 8;
            uint32_t                : 8;
            uint32_t                : 8;
        } ICnMS_b;
    };

    /* H’0258 */
    union
    {
        __IOM uint32_t ICnDEC;
        struct
        {
            __IOM uint32_t  FRMDEC     : 4;
            uint32_t                   : 4;
            uint32_t                   : 8;
            uint32_t                   : 8;
            uint32_t                   : 8;
        } ICnDEC_b;
    };

    /* H’025C */
    union
    {
        __IOM uint32_t ICnLC;
        struct
        {
            __IM uint32_t LC    :12;
            uint32_t                :4;
            uint32_t                :16;
        } ICnLC_b;
    };

    /* H’0260 */
    union
    {
        __IOM uint32_t ICnWC;
        struct
        {
            __IM uint32_t WCLC    :12;
            uint32_t              :4;
            __IM uint32_t WC    :16;
        } ICnWC_b;
    };

    /* H’0264 */
    union
    {
        __IOM uint32_t ICnEWC;
        struct
        {
            __IOM uint32_t EWC    :16;
            uint32_t              :16;
        } ICnEWC_b;
    };

    /* H’0268 */
    union
    {
        __IOM uint32_t ICnINTCTRL;
        struct
        {
            __IOM uint32_t  DECINTE    : 1;
            uint32_t                   : 7;
            uint32_t                   : 8;
            uint32_t                   : 8;
            uint32_t                   : 8;
        } ICnINTCTRL_b;
    };

    /* H’026C */
    union
    {
        __IOM uint32_t ICnDMR;
        struct
        {
            __IOM uint32_t  RGBMODE       : 2;
            uint32_t                      : 2;
            __IOM uint32_t  YCMODE        : 3;
            uint32_t                      : 1;
            __IOM uint32_t  OBINSEL       : 1;
            uint32_t                      : 7;
            uint32_t                      : 8;
            __IOM uint32_t  A8BIT         : 8;
        } ICnDMR_b;
    };

    /* H’0270 */
    union
    {
        __IOM uint32_t ICnCSCC1;
        struct
        {
            __IOM uint32_t YMUL     :14;
            uint32_t                :2;
            uint32_t                :16;
        } ICnCSCC1_b;
    };

    /* H’0274 */
    union
    {
        __IOM uint32_t ICnCSCC2;
        struct
        {
            __IOM uint32_t CSUB     :12;
            uint32_t                :4;
            __IOM uint32_t YSUB     :12;
            uint32_t                :4;
        } ICnCSCC2_b;
    };

    /* H’0278 */
    union
    {
        __IOM uint32_t ICnCSCC3;
        struct
        {
            __IOM uint32_t GCRMUL   :14;
            uint32_t                :2;
            __IOM uint32_t RCRMUL   :14;
            uint32_t                :2;
        } ICnCSCC3_b;
    };

    /* H’027C */
    union
    {
        __IOM uint32_t ICnCSCC4;
        struct
        {
            __IOM uint32_t BCBMUL   :12;
            uint32_t                :4;
            __IOM uint32_t GCBMUL   :12;
            uint32_t                :4;
        } ICnCSCC4_b;
    };

    /* H’0280 */
    union
    {
        __IOM uint32_t ICnYCCR1;
        struct
        {
            __IOM uint32_t YCLRP   :13;
            uint32_t                :3;
            uint32_t                :16;
        } ICnYCCR1_b;
    };

    /* H’0284 */
    union
    {
        __IOM uint32_t ICnYCCR2;
        struct
        {
            __IOM uint32_t YCLGP   :13;
            uint32_t               :3;
            __IOM uint32_t YCLBP   :13;
            uint32_t               :3;
        } ICnYCCR2_b;
    };

    /* H’0288 */
    union
    {
        __IOM uint32_t ICnYCCR3;
        struct
        {
            __IOM uint32_t YCLAP   :12;
            uint32_t               :4;
            __IOM uint32_t YCLCEN : 1;
            uint32_t              : 7;
            __IOM uint32_t YCLSFT  :5;
            uint32_t              : 2;
            __IOM uint32_t YEXPEN : 1;
        } ICnYCCR3_b;
    };

    /* H’028C */
    union
    {
        __IOM uint32_t ICnCBCCR1;
        struct
        {
            __IOM uint32_t CBCLRP  :13;
            uint32_t               :3;
            uint32_t               :16;
        } ICnCBCCR1_b;
    };

    /* H’0290 */
    union
    {
        __IOM uint32_t ICnCBCCR2;
        struct
        {
            __IOM uint32_t CBCLGP   :13;
            uint32_t                :3;
            __IOM uint32_t CBCLBP   :13;
            uint32_t                :3;
        } ICnCBCCR2_b;
    };

    /* H’0294 */
    union
    {
        __IOM uint32_t ICnCBCCR3;
        struct
        {
            __IOM uint32_t CBCLAP   :12;
            uint32_t                :4;
            __IOM uint32_t CBCLCEN : 1;
            uint32_t               : 7;
            __IOM uint32_t CBCLSFT  :5;
            uint32_t               : 2;
            __IOM uint32_t CBEXPEN : 1;
        } ICnCBCCR3_b;
    };

    /* H’0298 */
    union
    {
        __IOM uint32_t ICnCRCCR1;
        struct
        {
            __IOM uint32_t CRCLRP   :13;
            uint32_t                :3;
            uint32_t                :16;
        } ICnCRCCR1_b;
    };

    /* H’029C */
    union
    {
        __IOM uint32_t ICnCRCCR2;
        struct
        {
            __IOM uint32_t CRCLGP   :13;
            uint32_t                :3;
            __IOM uint32_t CRCLBP   :13;
            uint32_t                :3;
        } ICnCRCCR2_b;
    };

    /* H’02A0 */
    union
    {
        __IOM uint32_t ICnCRCCR3;
        struct
        {
            __IOM uint32_t CRCLAP   :12;
            uint32_t                :4;
            __IOM uint32_t CRCLCEN : 1;
            uint32_t               : 7;
            __IOM uint32_t CRCLSFT  :5;
            uint32_t               : 2;
            __IOM uint32_t CREXPEN : 1;
        } ICnCRCCR3_b;
    };

    /* Reserved H’02A4 - H'02AF*/
    __IM uint32_t RESERVED8[3];

    /* H’02B0 */
    union
    {
        __IOM uint32_t ICnLUT;
        struct
        {
            __IOM uint32_t  LUTSEL       : 1;
            __IOM uint32_t  LUTWR        : 1;
            uint32_t                     : 6;
            uint32_t                     : 8;
            uint32_t                     : 8;
            uint32_t                     : 8;
        } ICnLUT_b;
    };

    /* H’02B4 */
    union
    {
        __IOM uint32_t ICnLUTS;
        struct
        {
            __IM uint32_t  LUTREGSEL     : 1;
            uint32_t                     : 7;
            uint32_t                     : 8;
            uint32_t                     : 8;
            uint32_t                     : 8;
        } ICnLUTS_b;
    };

    /* H’02B8 */
    union
    {
        __IOM uint32_t ICnLUTP;
        struct
        {
            __IOM uint32_t LTCRPR   :10;
            __IOM uint32_t LTCBPR   :10;
            __IOM uint32_t LTYPR    :10;
            uint32_t                :2;
        } ICnLUTP_b;
    };

    /* H’02BC */
    union
    {
        __IOM uint32_t ICnLUTD;
        struct
        {
            __IOM uint32_t  LTCRDT       : 8;
            __IOM uint32_t  LTCBDT       : 8;
            __IOM uint32_t  LTYDT        : 8;
            uint32_t                     s: 8;
        } ICnLUTD_b;
    };

    /* H’02C0 */
    union
    {
        __IOM uint32_t ICnTICTRL1;
        struct
        {
            __IOM uint32_t  TIEN       : 1;
            __IOM uint32_t  TIMODE     : 1;
            uint32_t                   : 2;
            __IOM uint32_t  TIPTNY1    : 4;
            __IOM uint32_t  TIPTNU1    : 4;
            __IOM uint32_t  TIPTNV1    : 4;
            __IOM uint32_t  TIRATE     : 5;
            uint32_t                   : 11;
        } ICnTICTRL1_b;
    };

    /* H’02C4 */
    union
    {
        __IOM uint32_t ICnTICTRL2;
        struct
        {
            __IOM uint32_t  TIPTNY2       : 8;
            __IOM uint32_t  TIPTNU2       : 8;
            __IOM uint32_t  TIPTNV2       : 8;
            uint32_t                      : 8;
        } ICnTICTRL2_b;
    };

    /* H’02C8 */
    union
    {
        __IOM uint32_t ICnTISIZE1;
        struct
        {
            __IOM uint32_t TIPPL   :12;
            uint32_t                :4;
            uint32_t                :16;
        } ICnTISIZE1_b;
    };

    /* H’02CC */
    union
    {
        __IOM uint32_t ICnTISIZE2;
        struct
        {
            __IOM uint32_t TIN   :12;
            uint32_t             :4;
            __IOM uint32_t TIM   :12;
            uint32_t             :4;
        } ICnTISIZE2_b;
    };

    /* Reserved H’02D0 - H'03FF*/
    __IM uint32_t RESERVED9[76];
} R_CRU_IM_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_CSI2_LINK_BASE     0x40830400
#define R_CSI2_PHY_BASE      0x40830800
/* Base address of Image Processing */
#define R_CRU_IM_Base            0x40830000

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */
#define R_CRU     ((R_CRU_IM_Type *) R_CRU_IM_Base)
#define R_CSI2_LINK    ((R_CSI2_LINK_Type *) R_CSI2_LINK_BASE)
#define R_CSI2_PHY     ((R_CSI2_PHY_Type *) R_CSI2_PHY_BASE)

#endif                                 /* CSI2_IODEFINE_H */
