/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2020 Liviu Ionescu.
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

#if defined(MICRO_OS_PLUS_INCLUDE_STARTUP)

#include <micro-os-plus/device.h>
#include <micro-os-plus/startup/hooks.h>

/**
 * @details
 * This function resets the MCU core.
 * Redefine it in your application if you need to do more,
 * like powering down devices, saving state, etc.
 */
void __attribute__ ((noreturn, weak))
micro_os_plus_terminate (int code __attribute__ ((unused)))
{
  // TODO
  while (1)
    ;
  /* NOTREACHED */
}

#endif // defined(MICRO_OS_PLUS_INCLUDE_STARTUP)

// ----------------------------------------------------------------------------

#endif // defined(__aarch64__) || defined(__ARM_EABI__)

// ----------------------------------------------------------------------------
