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

1. Project Overview:
    The example project demonstrates the OpenAMP's remoteproc protocol. 
    The project initialies the OpenAMP and communicate Linux user program via inter-core communication.
    After the project starts execution, it waits for OpenAMP initialization on the Linux side and echoes back
    the received message from Linux by inter-core communication.

NOTE:
   1. Please start this project on CM33 core in advance before starting Linux.
   2. After Linux boots, run rmsg_sample_client on the Linux console.
   3. Please check the log on the Linux program side for the progress of inter-core communication.

2. How to build

  (1) Setting up sample code
    Copy the directories of [rzv2l_cm33_rpmsg_demo] to the e2studio workspace directory
    in the host PC (eg: "C:\e2studio_Workspace").

  (3) Activating integrated development environment
    Activate the integrated development environment e2studio.

  (4) Building application program ([rzv2l_cm33_rpmsg_demo] project)
    After importing [rzv2l_cm33_rpmsg_demo] project by the e2studio menu, build the project 
    and generate the binary files named as following in Debug or Release folder.

        rzv2l_cm33_rpmsg_demo_non_secure_code.bin
        rzv2l_cm33_rpmsg_demo_non_secure_vector.bin
        rzv2l_cm33_rpmsg_demo_secure_code.bin
        rzv2l_cm33_rpmsg_demo_secure_vector.bin
