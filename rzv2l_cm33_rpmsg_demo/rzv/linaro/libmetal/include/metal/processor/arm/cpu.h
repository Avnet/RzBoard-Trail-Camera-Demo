/*
 * Copyright (c) 2015, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	cpu.h
 * @brief	CPU specific primatives
 */

#ifndef __METAL_ARM_CPU__H__
#define __METAL_ARM_CPU__H__

#include "FreeRTOS.h"
#include "task.h"

#define metal_cpu_yield() taskYIELD()

#endif /* __METAL_ARM_CPU__H__ */
