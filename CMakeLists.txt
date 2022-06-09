# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `add_subdirectory("xpacks/micro-os-plus-devices-cortexa")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC micro-os-plus::devices-cortexa)`

# -----------------------------------------------------------------------------
## Preamble ##

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

project(
  micro-os-plus-devices-cortexa
  DESCRIPTION "µOS++ devices-cortexa"
)

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------
## The project library definitions ##

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#normal-libraries
# PRIVATE: build definitions, used internally
# INTERFACE: usage definitions, passed up to targets linking to it
# PUBLIC: both

add_library(micro-os-plus-devices-cortexa-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------
# Target settings.

target_include_directories(micro-os-plus-devices-cortexa-interface INTERFACE
  "include"
)

target_sources(micro-os-plus-devices-cortexa-interface INTERFACE
  "src/startup/initialize-hardware-early.c"
  "src/startup/initialize-hardware.c"
  "src/startup/initialize-interrupts-stack.cpp"
  "src/startup/terminate.cpp"
)

target_compile_definitions(micro-os-plus-devices-cortexa-interface INTERFACE
  # None.
)

target_compile_options(micro-os-plus-devices-cortexa-interface INTERFACE
  # None.
)

target_link_libraries(micro-os-plus-devices-cortexa-interface INTERFACE
  # Dependencies
  micro-os-plus::semihosting
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists(micro-os-plus-devices-cortexa-interface)
endif()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library(micro-os-plus::devices-cortexa ALIAS micro-os-plus-devices-cortexa-interface)
message(VERBOSE "> micro-os-plus::devices-cortexa -> micro-os-plus-devices-cortexa-interface")

# -----------------------------------------------------------------------------
