/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

#if defined(__aarch64__) || defined(__ARM_EABI__)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/startup/hooks.h>
#include <micro-os-plus/device.h>

// ----------------------------------------------------------------------------

/**
 * @details
 * This is the default early hardware initialisation routine.
 *
 * It is called right at the beginning of `_start()`, to switch clocks
 * to higher frequencies and have the rest of the initialisations run faster.
 *
 * The application can redefine it
 * for more complex cases that requires inits before DATA and BSS init.
 *
 * It is mandatory on platforms like Kinetis, which start with the
 * watch dog enabled and require an early sequence to disable it.
 *
 * Also useful on platform with external RAM, that need to be
 * initialised before filling the BSS section.
 */
void __attribute__ ((weak))
micro_os_plus_startup_initialize_hardware_early (void)
{
  // TODO
}

// ----------------------------------------------------------------------------

#endif // defined(__aarch64__) || defined(__ARM_EABI__)

// ----------------------------------------------------------------------------
