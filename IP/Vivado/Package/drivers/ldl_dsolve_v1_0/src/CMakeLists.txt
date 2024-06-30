# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
# Tool Version Limit: 2024.05
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
# 
# ==============================================================
cmake_minimum_required(VERSION 3.15)
project(ldl_dsolve)
find_package(common)
collector_create (PROJECT_LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}")
collect (PROJECT_LIB_SOURCES xldl_dsolve.c)
collect (PROJECT_LIB_SOURCES xldl_dsolve_sinit.c)
collect (PROJECT_LIB_SOURCES xldl_dsolve_linux.c)
collect (PROJECT_LIB_SOURCES xldl_dsolve_g.c)
collector_list (_sources PROJECT_LIB_SOURCES)
collector_create (PROJECT_LIB_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}")
collect (PROJECT_LIB_HEADERS xldl_dsolve.h)
collect (PROJECT_LIB_HEADERS xldl_dsolve_hw.h)
collector_list (_headers PROJECT_LIB_HEADERS)
file(COPY ${_headers} DESTINATION ${CMAKE_BINARY_DIR}/include)
include_directories(${CMAKE_BINARY_DIR}/include)
add_library(ldl_dsolve STATIC ${_sources})
set_target_properties(ldl_dsolve PROPERTIES LINKER_LANGUAGE C)

