/* mbed Microcontroller Library
 * Copyright (c) 2017 ARM Limited
 * Copyright (c) 2021 Renesas Electronics Corporation
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Renesas has made the following changes:
 *   -- Added the include of console.h
 *   -- Change argument FILE * stream to console_t console
 */

#ifndef MBED_PRINTF_IMPLEMENTATION_H
#define MBED_PRINTF_IMPLEMENTATION_H

#include <stdio.h>
#include <stdarg.h>
#include "console.h"

int mbed_minimal_formatted_string(char *buffer, size_t length, const char *format, va_list arguments, console_t console);
#endif
