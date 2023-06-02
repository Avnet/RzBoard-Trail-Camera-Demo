/***********************************************************************************************************************
 * Copyright [2020-2021] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
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
 * File Name    : canfd_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for canfd.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef CANFD_IODEFINE_H
#define CANFD_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t RSCFDnCFDC0NCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0NCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0NCFG_byte;
        struct
        {
            __IOM uint32_t NBRP:10;
            uint32_t :1;
            __IOM uint32_t NSJW:5;
            __IOM uint32_t NTSEG1:7;
            uint32_t :1;
            __IOM uint32_t NTSEG2:5;
            uint32_t :3;
        } RSCFDnCFDC0NCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0CTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0CTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0CTR_byte;
        struct
        {
            __IOM uint8_t CHMDC:2;
            __IOM uint8_t CSLPR:1;
            __IOM uint8_t RTBO:1;
            uint8_t :4;
            __IOM uint8_t BEIE:1;
            __IOM uint8_t EWIE:1;
            __IOM uint8_t EPIE:1;
            __IOM uint8_t BOEIE:1;
            __IOM uint8_t BORIE:1;
            __IOM uint8_t OLIE:1;
            __IOM uint8_t BLIE:1;
            __IOM uint8_t ALIE:1;
            __IOM uint8_t TAIE:1;
            __IOM uint8_t EOCOIE:1;
            __IOM uint8_t SOCOIE:1;
            __IOM uint8_t TDCVFIE:1;
            uint8_t :1;
            __IOM uint8_t BOM:2;
            __IOM uint8_t ERRD:1;
            __IOM uint8_t CTME:1;
            __IOM uint8_t CTMS:2;
            uint8_t :3;
            __IOM uint8_t CRCT:1;
            __IOM uint8_t ROM:1;
        } RSCFDnCFDC0CTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0STS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0STS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0STS_byte;
        struct
        {
            __IM uint8_t CRSTSTS:1;
            __IM uint8_t CHLTSTS:1;
            __IM uint8_t CSLPSTS:1;
            __IM uint8_t EPSTS:1;
            __IM uint8_t BOSTS:1;
            __IM uint8_t TRMSTS:1;
            __IM uint8_t RECSTS:1;
            __IM uint8_t COMSTS:1;
            __IOM uint8_t ESIF:1;
            uint8_t :7;
            __IM uint8_t REC:8;
            __IM uint8_t TEC:8;
        } RSCFDnCFDC0STS_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0ERFL;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0ERFL_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0ERFL_byte;
        struct
        {
            __IOM uint32_t BEF:1;
            __IOM uint32_t EWF:1;
            __IOM uint32_t EPF:1;
            __IOM uint32_t BOEF:1;
            __IOM uint32_t BORF:1;
            __IOM uint32_t OVLF:1;
            __IOM uint32_t BLF:1;
            __IOM uint32_t ALF:1;
            __IOM uint32_t SERR:1;
            __IOM uint32_t FERR:1;
            __IOM uint32_t AERR:1;
            __IOM uint32_t CERR:1;
            __IOM uint32_t B1ERR:1;
            __IOM uint32_t B0ERR:1;
            __IOM uint32_t ADERR:1;
            uint32_t :1;
            __IM uint32_t CRCREG:15;
            uint32_t :1;
        } RSCFDnCFDC0ERFL_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1NCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1NCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1NCFG_byte;
        struct
        {
            __IOM uint32_t NBRP:10;
            uint32_t :1;
            __IOM uint32_t NSJW:5;
            __IOM uint32_t NTSEG1:7;
            uint32_t :1;
            __IOM uint32_t NTSEG2:5;
            uint32_t :3;
        } RSCFDnCFDC1NCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1CTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1CTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1CTR_byte;
        struct
        {
            __IOM uint8_t CHMDC:2;
            __IOM uint8_t CSLPR:1;
            __IOM uint8_t RTBO:1;
            uint8_t :4;
            __IOM uint8_t BEIE:1;
            __IOM uint8_t EWIE:1;
            __IOM uint8_t EPIE:1;
            __IOM uint8_t BOEIE:1;
            __IOM uint8_t BORIE:1;
            __IOM uint8_t OLIE:1;
            __IOM uint8_t BLIE:1;
            __IOM uint8_t ALIE:1;
            __IOM uint8_t TAIE:1;
            __IOM uint8_t EOCOIE:1;
            __IOM uint8_t SOCOIE:1;
            __IOM uint8_t TDCVFIE:1;
            uint8_t :1;
            __IOM uint8_t BOM:2;
            __IOM uint8_t ERRD:1;
            __IOM uint8_t CTME:1;
            __IOM uint8_t CTMS:2;
            uint8_t :3;
            __IOM uint8_t CRCT:1;
            __IOM uint8_t ROM:1;
        } RSCFDnCFDC1CTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1STS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1STS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1STS_byte;
        struct
        {
            __IM uint8_t CRSTSTS:1;
            __IM uint8_t CHLTSTS:1;
            __IM uint8_t CSLPSTS:1;
            __IM uint8_t EPSTS:1;
            __IM uint8_t BOSTS:1;
            __IM uint8_t TRMSTS:1;
            __IM uint8_t RECSTS:1;
            __IM uint8_t COMSTS:1;
            __IOM uint8_t ESIF:1;
            uint8_t :7;
            __IM uint8_t REC:8;
            __IM uint8_t TEC:8;
        } RSCFDnCFDC1STS_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1ERFL;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1ERFL_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1ERFL_byte;
        struct
        {
            __IOM uint32_t BEF:1;
            __IOM uint32_t EWF:1;
            __IOM uint32_t EPF:1;
            __IOM uint32_t BOEF:1;
            __IOM uint32_t BORF:1;
            __IOM uint32_t OVLF:1;
            __IOM uint32_t BLF:1;
            __IOM uint32_t ALF:1;
            __IOM uint32_t SERR:1;
            __IOM uint32_t FERR:1;
            __IOM uint32_t AERR:1;
            __IOM uint32_t CERR:1;
            __IOM uint32_t B1ERR:1;
            __IOM uint32_t B0ERR:1;
            __IOM uint32_t ADERR:1;
            uint32_t :1;
            __IM uint32_t CRCREG:15;
            uint32_t :1;
        } RSCFDnCFDC1ERFL_b;
    };
    __IM uint8_t        RESERVED[100];
    union
    {
        __IOM uint32_t RSCFDnCFDGCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGCFG_byte;
        struct
        {
            __IOM uint32_t TPRI:1;
            __IOM uint32_t DCE:1;
            __IOM uint32_t DRE:1;
            __IOM uint32_t MME:1;
            __IOM uint32_t DCS:1;
            __IOM uint32_t CMPOC:1;
            uint32_t :2;
            __IOM uint32_t TSP:4;
            __IOM uint32_t TSSS:1;
            __IOM uint32_t TSBTCS:3;
            __IOM uint32_t ITRCP:16;
        } RSCFDnCFDGCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGCTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGCTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGCTR_byte;
        struct
        {
            __IOM uint8_t GMDC:2;
            __IOM uint8_t GSLPR:1;
            uint8_t :5;
            __IOM uint8_t DEIE:1;
            __IOM uint8_t MEIE:1;
            __IOM uint8_t THLEIE:1;
            __IOM uint8_t CMPOFIE:1;
            uint8_t :4;
            __IOM uint8_t TSRST:1;
            uint8_t :7;
            uint8_t :8;
        } RSCFDnCFDGCTR_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDGSTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDGSTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDGSTS_byte;
        struct
        {
            __IM uint8_t GRSTSTS:1;
            __IM uint8_t GHLTSTS:1;
            __IM uint8_t GSLPSTS:1;
            __IM uint8_t GRAMINIT:1;
            uint8_t :4;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDGSTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDGERFL;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDGERFL_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDGERFL_byte;
        struct
        {
            __IM uint8_t DEF:1;
            __IM uint8_t MES:1;
            __IM uint8_t THLES:1;
            __IM uint8_t CMPOF:1;
            uint8_t :4;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDGERFL_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDGTSC;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDGTSC_hword;
        struct
        {
            __IM uint32_t TS:16;
            uint32_t :16;
        } RSCFDnCFDGTSC_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLECTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLECTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLECTR_byte;
        struct
        {
            __IOM uint8_t AFLPN:5;
            uint8_t :3;
            __IOM uint8_t AFLDAE:1;
            uint8_t :7;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDGAFLECTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLCFG0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLCFG0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLCFG0_byte;
        struct
        {
            uint8_t :8;
            uint8_t :8;
            __IOM uint8_t RNC1:8;
            __IOM uint8_t RNC0:8;
        } RSCFDnCFDGAFLCFG0_b;
    };
    __IM uint8_t        RESERVED1[4];
    union
    {
        __IOM uint32_t RSCFDnCFDRMNB;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRMNB_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRMNB_byte;
        struct
        {
            __IOM uint8_t NRXMB:8;
            __IOM uint8_t RMPLS:2;
            uint8_t :6;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDRMNB_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRMNDy;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRMNDy_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRMNDy_byte;
        struct
        {
            __IOM uint32_t RMNSq:32;
        } RSCFDnCFDRMNDy_b;
    };
    __IM uint8_t        RESERVED2[12];
    union
    {
        __IOM uint32_t RSCFDnCFDRFCCx;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFCCx_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFCCx_byte;
        struct
        {
            __IOM uint8_t RFE:1;
            __IOM uint8_t RFIE:1;
            uint8_t :6;
            __IOM uint8_t RFDC:3;
            uint8_t :1;
            __IOM uint8_t RFIM:1;
            __IOM uint8_t RFIGCV:3;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDRFCCx_b;
    };
    __IM uint8_t        RESERVED3[28];
    union
    {
        __IOM uint32_t RSCFDnCFDRFSTSx;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFSTSx_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFSTSx_byte;
        struct
        {
            __IM uint8_t RFEMP:1;
            __IM uint8_t RFFLL:1;
            __IOM uint8_t RFMLT:1;
            __IOM uint8_t RFIF:1;
            uint8_t :4;
            __IM uint8_t RFMC:8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDRFSTSx_b;
    };
    __IM uint8_t        RESERVED4[28];
    union
    {
        __IOM uint32_t RSCFDnCFDRFPCTRx;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFPCTRx_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFPCTRx_byte;
        struct
        {
            __OM uint8_t RFPC:8;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDRFPCTRx_b;
    };
    __IM uint8_t        RESERVED5[28];
    union
    {
        __IOM uint32_t RSCFDnCFDCFCCk;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFCCk_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFCCk_byte;
        struct
        {
            __IOM uint8_t CFE:1;
            __IOM uint8_t CFRXIE:1;
            __IOM uint8_t CFTXIE:1;
            uint8_t :5;
            __IOM uint8_t CFDC:3;
            uint8_t :1;
            __IOM uint8_t CFIM:1;
            __IOM uint8_t CFIGCV:3;
            __IOM uint8_t CFM:2;
            __IOM uint8_t CFITSS:1;
            __IOM uint8_t CFITR:1;
            __IOM uint8_t CFTML:4;
            __IOM uint8_t CFITT:8;
        } RSCFDnCFDCFCCk_b;
    };
    __IM uint8_t        RESERVED6[92];
    union
    {
        __IOM uint32_t RSCFDnCFDCFSTSk;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFSTSk_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFSTSk_byte;
        struct
        {
            __IM uint8_t CFEMP:1;
            __IM uint8_t CFFLL:1;
            __IOM uint8_t CFMLT:1;
            __IOM uint8_t CFRXIF:1;
            __IOM uint8_t CFTXIF:1;
            uint8_t :3;
            __IM uint8_t CFMC:8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDCFSTSk_b;
    };
    __IM uint8_t        RESERVED7[92];
    union
    {
        __IOM uint32_t RSCFDnCFDCFPCTRk;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPCTRk_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPCTRk_byte;
        struct
        {
            __OM uint8_t CFPC:8;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDCFPCTRk_b;
    };
    __IM uint8_t        RESERVED8[92];
    union
    {
        __IM uint32_t RSCFDnCFDFESTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDFESTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDFESTS_byte;
        struct
        {
            __IM uint8_t RF0EMP:1;
            __IM uint8_t RF1EMP:1;
            __IM uint8_t RF2EMP:1;
            __IM uint8_t RF3EMP:1;
            __IM uint8_t RF4EMP:1;
            __IM uint8_t RF5EMP:1;
            __IM uint8_t RF6EMP:1;
            __IM uint8_t RF7EMP:1;
            __IM uint8_t CF0EMP:1;
            __IM uint8_t CF1EMP:1;
            __IM uint8_t CF2EMP:1;
            __IM uint8_t CF3EMP:1;
            __IM uint8_t CF4EMP:1;
            __IM uint8_t CF5EMP:1;
            uint8_t :2;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDFESTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDFFSTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDFFSTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDFFSTS_byte;
        struct
        {
            __IM uint8_t RF0FLL:1;
            __IM uint8_t RF1FLL:1;
            __IM uint8_t RF2FLL:1;
            __IM uint8_t RF3FLL:1;
            __IM uint8_t RF4FLL:1;
            __IM uint8_t RF5FLL:1;
            __IM uint8_t RF6FLL:1;
            __IM uint8_t RF7FLL:1;
            __IM uint8_t CF0FLL:1;
            __IM uint8_t CF1FLL:1;
            __IM uint8_t CF2FLL:1;
            __IM uint8_t CF3FLL:1;
            __IM uint8_t CF4FLL:1;
            __IM uint8_t CF5FLL:1;
            uint8_t :2;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDFFSTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDFMSTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDFMSTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDFMSTS_byte;
        struct
        {
            __IM uint8_t RF0MLT:1;
            __IM uint8_t RF1MLT:1;
            __IM uint8_t RF2MLT:1;
            __IM uint8_t RF3MLT:1;
            __IM uint8_t RF4MLT:1;
            __IM uint8_t RF5MLT:1;
            __IM uint8_t RF6MLT:1;
            __IM uint8_t RF7MLT:1;
            __IM uint8_t CF0MLT:1;
            __IM uint8_t CF1MLT:1;
            __IM uint8_t CF2MLT:1;
            __IM uint8_t CF3MLT:1;
            __IM uint8_t CF4MLT:1;
            __IM uint8_t CF5MLT:1;
            uint8_t :2;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDFMSTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFISTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFISTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFISTS_byte;
        struct
        {
            __IM uint8_t RF0IF:1;
            __IM uint8_t RF1IF:1;
            __IM uint8_t RF2IF:1;
            __IM uint8_t RF3IF:1;
            __IM uint8_t RF4IF:1;
            __IM uint8_t RF5IF:1;
            __IM uint8_t RF6IF:1;
            __IM uint8_t RF7IF:1;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDRFISTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDCFRISTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDCFRISTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDCFRISTS_byte;
        struct
        {
            __IM uint8_t CF0RXIF:1;
            __IM uint8_t CF1RXIF:1;
            __IM uint8_t CF2RXIF:1;
            __IM uint8_t CF3RXIF:1;
            __IM uint8_t CF4RXIF:1;
            __IM uint8_t CF5RXIF:1;
            uint8_t :2;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDCFRISTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDCFTISTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDCFTISTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDCFTISTS_byte;
        struct
        {
            __IM uint8_t CF0TXIF:1;
            __IM uint8_t CF1TXIF:1;
            __IM uint8_t CF2TXIF:1;
            __IM uint8_t CF3TXIF:1;
            __IM uint8_t CF4TXIF:1;
            __IM uint8_t CF5TXIF:1;
            uint8_t :2;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDCFTISTS_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMCp;
        struct
        {
            __IOM uint8_t TMTR:1;
            __IOM uint8_t TMTAR:1;
            __IOM uint8_t TMOM:1;
            uint8_t :5;
        } RSCFDnCFDTMCp_b;
    };
    __IM uint8_t        RESERVED9[127];
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTSp;
        struct
        {
            __IM uint8_t TMTSTS:1;
            __IOM uint8_t TMTRF:2;
            __IM uint8_t TMTRM:1;
            __IM uint8_t TMTARM:1;
            uint8_t :3;
        } RSCFDnCFDTMSTSp_b;
    };
    __IM uint8_t        RESERVED10[127];
    union
    {
        __IM uint32_t RSCFDnCFDTMTRSTSy;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTMTRSTSy_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTMTRSTSy_byte;
        struct
        {
            __IM uint32_t TMTRSTSp:32;
        } RSCFDnCFDTMTRSTSy_b;
    };
    __IM uint8_t        RESERVED11[12];
    union
    {
        __IM uint32_t RSCFDnCFDTMTARSTSy;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTMTARSTSy_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTMTARSTSy_byte;
        struct
        {
            __IM uint32_t TMTARSTSp:32;
        } RSCFDnCFDTMTARSTSy_b;
    };
    __IM uint8_t        RESERVED12[12];
    union
    {
        __IM uint32_t RSCFDnCFDTMTCSTSy;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTMTCSTSy_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTMTCSTSy_byte;
        struct
        {
            __IM uint32_t TMTCSTSp:32;
        } RSCFDnCFDTMTCSTSy_b;
    };
    __IM uint8_t        RESERVED13[12];
    union
    {
        __IM uint32_t RSCFDnCFDTMTASTSy;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTMTASTSy_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTMTASTSy_byte;
        struct
        {
            __IM uint32_t TMTASTSp:32;
        } RSCFDnCFDTMTASTSy_b;
    };
    __IM uint8_t        RESERVED14[12];
    union
    {
        __IOM uint32_t RSCFDnCFDTMIECy;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMIECy_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMIECy_byte;
        struct
        {
            __IOM uint32_t TMIEp:32;
        } RSCFDnCFDTMIECy_b;
    };
    __IM uint8_t        RESERVED15[12];
    union
    {
        __IOM uint32_t RSCFDnCFDTXQCC0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQCC0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQCC0_byte;
        struct
        {
            __IOM uint8_t TXQE:1;
            uint8_t :7;
            __IOM uint8_t TXQDC:4;
            __IOM uint8_t TXQIE:1;
            __IOM uint8_t TXQIM:1;
            uint8_t :2;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTXQCC0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTXQCC1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQCC1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQCC1_byte;
        struct
        {
            __IOM uint8_t TXQE:1;
            uint8_t :7;
            __IOM uint8_t TXQDC:4;
            __IOM uint8_t TXQIE:1;
            __IOM uint8_t TXQIM:1;
            uint8_t :2;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTXQCC1_b;
    };
    __IM uint8_t        RESERVED16[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTXQSTS0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQSTS0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQSTS0_byte;
        struct
        {
            __IM uint8_t TXQEMP:1;
            __IM uint8_t TXQFLL:1;
            __IOM uint8_t TXQIF:1;
            uint8_t :5;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTXQSTS0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTXQSTS1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQSTS1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQSTS1_byte;
        struct
        {
            __IM uint8_t TXQEMP:1;
            __IM uint8_t TXQFLL:1;
            __IOM uint8_t TXQIF:1;
            uint8_t :5;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTXQSTS1_b;
    };
    __IM uint8_t        RESERVED17[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTXQPCTR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQPCTR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQPCTR0_byte;
        struct
        {
            __OM uint8_t TXQPC:8;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTXQPCTR0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTXQPCTR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQPCTR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQPCTR1_byte;
        struct
        {
            __OM uint8_t TXQPC:8;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTXQPCTR1_b;
    };
    __IM uint8_t        RESERVED18[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTHLCC0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLCC0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLCC0_byte;
        struct
        {
            __IOM uint8_t THLE:1;
            uint8_t :7;
            __IOM uint8_t THLIE:1;
            __IOM uint8_t THLIM:1;
            __IOM uint8_t THLDTE:1;
            uint8_t :5;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTHLCC0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTHLCC1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLCC1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLCC1_byte;
        struct
        {
            __IOM uint8_t THLE:1;
            uint8_t :7;
            __IOM uint8_t THLIE:1;
            __IOM uint8_t THLIM:1;
            __IOM uint8_t THLDTE:1;
            uint8_t :5;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTHLCC1_b;
    };
    __IM uint8_t        RESERVED19[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTHLSTS0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLSTS0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLSTS0_byte;
        struct
        {
            __IM uint8_t THLEMP:1;
            __IM uint8_t THLFLL:1;
            __IOM uint8_t THLELT:1;
            __IOM uint8_t THLIF:1;
            uint8_t :4;
            __IOM uint8_t THLMC:5;
            uint8_t :3;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTHLSTS0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTHLSTS1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLSTS1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLSTS1_byte;
        struct
        {
            __IM uint8_t THLEMP:1;
            __IM uint8_t THLFLL:1;
            __IOM uint8_t THLELT:1;
            __IOM uint8_t THLIF:1;
            uint8_t :4;
            __IOM uint8_t THLMC:5;
            uint8_t :3;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTHLSTS1_b;
    };
    __IM uint8_t        RESERVED20[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTHLPCTR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLPCTR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLPCTR0_byte;
        struct
        {
            __OM uint8_t THLPC:8;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTHLPCTR0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTHLPCTR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLPCTR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLPCTR1_byte;
        struct
        {
            __OM uint8_t THLPC:8;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTHLPCTR1_b;
    };
    __IM uint8_t        RESERVED21[24];
    union
    {
        __IM uint32_t RSCFDnCFDGTINTSTS0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDGTINTSTS0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDGTINTSTS0_byte;
        struct
        {
            __IM uint8_t TSIF0:1;
            __IM uint8_t TAIF0:1;
            __IM uint8_t TQIF0:1;
            __IM uint8_t CFTIF0:1;
            __IM uint8_t THIF0:1;
            uint8_t :3;
            __IM uint8_t TSIF1:1;
            __IM uint8_t TAIF1:1;
            __IM uint8_t TQIF1:1;
            __IM uint8_t CFTIF1:1;
            __IM uint8_t THIF1:1;
            uint8_t :3;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDGTINTSTS0_b;
    };
    __IM uint8_t        RESERVED22[4];
    union
    {
        __IOM uint32_t RSCFDnCFDGTSTCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGTSTCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGTSTCFG_byte;
        struct
        {
            __IOM uint8_t C0ICBCE:1;
            __IOM uint8_t C1ICBCE:1;
            uint8_t :6;
            uint8_t :8;
            __IOM uint8_t RTMPS:7;
            uint8_t :1;
            uint8_t :8;
        } RSCFDnCFDGTSTCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGTSTCTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGTSTCTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGTSTCTR_byte;
        struct
        {
            __IOM uint8_t ICBCTME:1;
            uint8_t :1;
            __IOM uint8_t RTME:1;
            uint8_t :5;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDGTSTCTR_b;
    };
    __IM uint8_t        RESERVED23[4];
    union
    {
        __IOM uint32_t RSCFDnCFDGFDCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGFDCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGFDCFG_byte;
        struct
        {
            __IOM uint8_t RPED:1;
            uint8_t :7;
            __IOM uint8_t TSCCFG:2;
            uint8_t :6;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDGFDCFG_b;
    };
    __IM uint8_t        RESERVED24[4];
    union
    {
        __IOM uint32_t RSCFDnCFDGLOCKK;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGLOCKK_hword;
        struct
        {
            __OM uint32_t LOCK:16;
            uint32_t :16;
        } RSCFDnCFDGLOCKK_b;
    };
    __IM uint8_t        RESERVED25[16];
    union
    {
        __IOM uint32_t RSCFDnCFDCDTCT;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCDTCT_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCDTCT_byte;
        struct
        {
            __IOM uint8_t RFDMAE0:1;
            __IOM uint8_t RFDMAE1:1;
            __IOM uint8_t RFDMAE2:1;
            __IOM uint8_t RFDMAE3:1;
            __IOM uint8_t RFDMAE4:1;
            __IOM uint8_t RFDMAE5:1;
            __IOM uint8_t RFDMAE6:1;
            __IOM uint8_t RFDMAE7:1;
            __IOM uint8_t CFDMAE0:1;
            __IOM uint8_t CFDMAE1:1;
            uint8_t :6;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDCDTCT_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCDTSTS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCDTSTS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCDTSTS_byte;
        struct
        {
            __IOM uint8_t RFDMASTS0:1;
            __IOM uint8_t RFDMASTS1:1;
            __IOM uint8_t RFDMASTS2:1;
            __IOM uint8_t RFDMASTS3:1;
            __IOM uint8_t RFDMASTS4:1;
            __IOM uint8_t RFDMASTS5:1;
            __IOM uint8_t RFDMASTS6:1;
            __IOM uint8_t RFDMASTS7:1;
            __IOM uint8_t CFDMASTS0:1;
            __IOM uint8_t CFDMASTS1:1;
            uint8_t :6;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDCDTSTS_b;
    };
    __IM uint8_t        RESERVED26[100];
    union
    {
        __IOM uint32_t RSCFDnCFDGRMCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGRMCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGRMCFG_byte;
        struct
        {
            __IOM uint8_t RCMC:1;
            uint8_t :7;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDGRMCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0DCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0DCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0DCFG_byte;
        struct
        {
            __IOM uint8_t DBRP:8;
            uint8_t :8;
            __IOM uint8_t DTSEG1:4;
            __IOM uint8_t DTSEG2:3;
            uint8_t :1;
            __IOM uint8_t DSJW:3;
            uint8_t :5;
        } RSCFDnCFDC0DCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0FDCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0FDCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0FDCFG_byte;
        struct
        {
            __IOM uint8_t EOCCFG:3;
            uint8_t :5;
            __IOM uint8_t TDCOC:1;
            __IOM uint8_t TDCE:1;
            __IOM uint8_t ESIC:1;
            uint8_t :5;
            __IOM uint8_t TDCO:7;
            uint8_t :1;
            __IOM uint8_t GWEN:1;
            __IOM uint8_t GWFDF:1;
            __IOM uint8_t GWBRS:1;
            __IOM uint8_t TMME:1;
            __IOM uint8_t FDOE:1;
            __IOM uint8_t REFE:1;
            uint8_t :2;
        } RSCFDnCFDC0FDCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0FDCTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0FDCTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0FDCTR_byte;
        struct
        {
            __IOM uint8_t EOCCLR:1;
            __IOM uint8_t SOCCLR:1;
            uint8_t :6;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDC0FDCTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0FDSTS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0FDSTS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0FDSTS_byte;
        struct
        {
            __IM uint8_t TDCR:7;
            __IOM uint8_t TDCVF:1;
            __IOM uint8_t EOCO:1;
            __IOM uint8_t SOCO:1;
            uint8_t :6;
            __IM uint8_t EOC:8;
            __IM uint8_t SOC:8;
        } RSCFDnCFDC0FDSTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDC0FDCRC;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDC0FDCRC_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDC0FDCRC_byte;
        struct
        {
            __IM uint32_t CRCREG:21;
            uint32_t :3;
            __IM uint32_t SCNT:4;
            uint32_t :4;
        } RSCFDnCFDC0FDCRC_b;
    };
    __IM uint8_t        RESERVED27[12];
    union
    {
        __IOM uint32_t RSCFDnCFDC1DCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1DCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1DCFG_byte;
        struct
        {
            __IOM uint8_t DBRP:8;
            uint8_t :8;
            __IOM uint8_t DTSEG1:4;
            __IOM uint8_t DTSEG2:3;
            uint8_t :1;
            __IOM uint8_t DSJW:3;
            uint8_t :5;
        } RSCFDnCFDC1DCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1FDCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1FDCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1FDCFG_byte;
        struct
        {
            __IOM uint8_t EOCCFG:3;
            uint8_t :5;
            __IOM uint8_t TDCOC:1;
            __IOM uint8_t TDCE:1;
            __IOM uint8_t ESIC:1;
            uint8_t :5;
            __IOM uint8_t TDCO:7;
            uint8_t :1;
            __IOM uint8_t GWEN:1;
            __IOM uint8_t GWFDF:1;
            __IOM uint8_t GWBRS:1;
            __IOM uint8_t TMME:1;
            __IOM uint8_t FDOE:1;
            __IOM uint8_t REFE:1;
            uint8_t :2;
        } RSCFDnCFDC1FDCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1FDCTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1FDCTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1FDCTR_byte;
        struct
        {
            __IOM uint8_t EOCCLR:1;
            __IOM uint8_t SOCCLR:1;
            uint8_t :6;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDC1FDCTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1FDSTS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1FDSTS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1FDSTS_byte;
        struct
        {
            __IM uint8_t TDCR:7;
            __IOM uint8_t TDCVF:1;
            __IOM uint8_t EOCO:1;
            __IOM uint8_t SOCO:1;
            uint8_t :6;
            __IM uint8_t EOC:8;
            __IM uint8_t SOC:8;
        } RSCFDnCFDC1FDSTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDC1FDCRC;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDC1FDCRC_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDC1FDCRC_byte;
        struct
        {
            __IM uint32_t CRCREG:21;
            uint32_t :3;
            __IM uint32_t SCNT:4;
            uint32_t :4;
        } RSCFDnCFDC1FDCRC_b;
    };
    __IM uint8_t        RESERVED28[2764];
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLIDj;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLIDj_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLIDj_byte;
        struct
        {
            __IOM uint32_t GAFLID:29;
            __IOM uint32_t GAFLLB:1;
            __IOM uint32_t GAFLRTR:1;
            __IOM uint32_t GAFLIDE:1;
        } RSCFDnCFDGAFLIDj_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLMj;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLMj_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLMj_byte;
        struct
        {
            __IOM uint32_t GAFLIDM:29;
            uint32_t :1;
            __IOM uint32_t GAFLRTRM:1;
            __IOM uint32_t GAFLIDEM:1;
        } RSCFDnCFDGAFLMj_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_j;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_j_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_j_byte;
        struct
        {
            uint32_t :8;
            __IOM uint32_t GAFLRMDP:7;
            __IOM uint32_t GAFLRMV:1;
            __IOM uint32_t GAFLPTR:12;
            __IOM uint32_t GAFLDLC:4;
        } RSCFDnCFDGAFLP0_j_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_j;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_j_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_j_byte;
        struct
        {
            __IOM uint32_t GAFLFDP:14;
            uint32_t :18;
        } RSCFDnCFDGAFLP1_j_b;
    };
    __IM uint8_t        RESERVED29[4080];
    union
    {
        __IM uint32_t RSCFDnCFDRMIDq;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMIDq_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMIDq_byte;
        struct
        {
            __IM uint32_t RMID:29;
            uint32_t :1;
            __IM uint32_t RMRTR:1;
            __IM uint32_t RMIDE:1;
        } RSCFDnCFDRMIDq_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTRq;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTRq_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTRq_byte;
        struct
        {
            __IM uint32_t RMTS:16;
            __IM uint32_t RMPTR:12;
            __IM uint32_t RMDLC:4;
        } RSCFDnCFDRMPTRq_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTSq;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTSq_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTSq_byte;
        struct
        {
            __IM uint8_t RMESI:1;
            __IM uint8_t RMBRS:1;
            __IM uint8_t RMFDF:1;
            uint8_t :5;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDRMFDSTSq_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDFb_q;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDFb_q_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDFb_q_byte;
        struct
        {
            __IM uint32_t RMDB4:32;
        } RSCFDnCFDRMDFb_q_b;
    };
    __IM uint8_t        RESERVED30[4080];
    union
    {
        __IM uint32_t RSCFDnCFDRFIDx;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFIDx_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFIDx_byte;
        struct
        {
            __IM uint32_t RFID:29;
            uint32_t :1;
            __IM uint32_t RFRTR:1;
            __IM uint32_t RFIDE:1;
        } RSCFDnCFDRFIDx_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFPTRx;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFPTRx_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFPTRx_byte;
        struct
        {
            __IM uint32_t RFTS:16;
            __IM uint32_t RFPTR:12;
            __IM uint32_t RFDLC:4;
        } RSCFDnCFDRFPTRx_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFFDSTSx;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFFDSTSx_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFFDSTSx_byte;
        struct
        {
            __IM uint8_t RFESI:1;
            __IM uint8_t RFBRS:1;
            __IM uint8_t RFFDF:1;
            uint8_t :5;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDRFFDSTSx_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDFd_x;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDFd_x_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDFd_x_byte;
        struct
        {
            __IM uint32_t RFDB4:32;
        } RSCFDnCFDRFDFd_x_b;
    };
    __IM uint8_t        RESERVED31[1008];
    union
    {
        __IOM uint32_t RSCFDnCFDCFIDk;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFIDk_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFIDk_byte;
        struct
        {
            __IOM uint32_t CFID:29;
            __IOM uint32_t HLEN:1;
            __IOM uint32_t CFRTR:1;
            __IOM uint32_t CFIDE:1;
        } RSCFDnCFDCFIDk_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPTRk;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPTRk_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPTRk_byte;
        struct
        {
            __IOM uint32_t CFTS:16;
            __IOM uint32_t CFPTR:12;
            __IOM uint32_t CFDLC:4;
        } RSCFDnCFDCFPTRk_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFFDCSTSk;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFFDCSTSk_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFFDCSTSk_byte;
        struct
        {
            __IOM uint8_t CFESI:1;
            __IOM uint8_t CFBRS:1;
            __IOM uint8_t CFFDF:1;
            uint8_t :5;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDCFFDCSTSk_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDFd_k;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDFd_k_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDFd_k_byte;
        struct
        {
            __IOM uint32_t CFDB4:32;
        } RSCFDnCFDCFDFd_k_b;
    };
    __IM uint8_t        RESERVED32[3056];
    union
    {
        __IOM uint32_t RSCFDnCFDTMIDp;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMIDp_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMIDp_byte;
        struct
        {
            __IOM uint32_t TMID:29;
            __IOM uint32_t THLEN:1;
            __IOM uint32_t TMRTR:1;
            __IOM uint32_t TMIDE:1;
        } RSCFDnCFDTMIDp_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTRp;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTRp_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTRp_byte;
        struct
        {
            uint8_t :8;
            uint8_t :8;
            __IOM uint8_t TMPTR:8;
            uint8_t :4;
            __IOM uint8_t TMDLC:4;
        } RSCFDnCFDTMPTRp_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTRp;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTRp_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTRp_byte;
        struct
        {
            __IOM uint8_t TMESI:1;
            __IOM uint8_t TMBRS:1;
            __IOM uint8_t TMFDF:1;
            uint8_t :5;
            uint8_t :8;
            uint8_t :8;
            uint8_t :8;
        } RSCFDnCFDTMFDCTRp_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDFb_p;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDFb_p_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDFb_p_byte;
        struct
        {
            __IOM uint32_t TMDB4:32;
        } RSCFDnCFDTMDFb_p_b;
    };
    __IM uint8_t        RESERVED33[8176];
    union
    {
        __IM uint32_t RSCFDnCFDTHLACC0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTHLACC0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTHLACC0_byte;
        struct
        {
            __IM uint32_t BT:3;
            __IM uint32_t BN:4;
            uint32_t :1;
            __IM uint32_t TID:8;
            __IM uint32_t TMTS:16;
        } RSCFDnCFDTHLACC0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDTHLACC1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTHLACC1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTHLACC1_byte;
        struct
        {
            __IM uint32_t BT:3;
            __IM uint32_t BN:4;
            uint32_t :1;
            __IM uint32_t TID:8;
            __IM uint32_t TMTS:16;
        } RSCFDnCFDTHLACC1_b;
    };
    __IM uint8_t        RESERVED34[1016];
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACCr;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACCr_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACCr_byte;
        struct
        {
            __IOM uint32_t RDTA:32;
        } RSCFDnCFDRPGACCr_b;
    };
} R_CANFD_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_CANFD_BASE     0x40050000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_CANFD     ((R_CANFD_Type     *) R_CANFD_BASE)

#endif
