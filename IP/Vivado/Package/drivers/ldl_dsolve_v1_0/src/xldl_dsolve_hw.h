// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        bit 9  - interrupt (Read)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (Read/TOW)
//        bit 1 - ap_ready (Read/TOW)
//        others - reserved
// 0x10 : Data signal of n
//        bit 31~0 - n[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of X
//        bit 31~0 - X[31:0] (Read/Write)
// 0x1c : Data signal of X
//        bit 31~0 - X[63:32] (Read/Write)
// 0x20 : reserved
// 0x24 : Data signal of D
//        bit 31~0 - D[31:0] (Read/Write)
// 0x28 : Data signal of D
//        bit 31~0 - D[63:32] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of out_r
//        bit 31~0 - out_r[31:0] (Read/Write)
// 0x34 : Data signal of out_r
//        bit 31~0 - out_r[63:32] (Read/Write)
// 0x38 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL    0x00
#define XLDL_DSOLVE_CONTROL_ADDR_GIE        0x04
#define XLDL_DSOLVE_CONTROL_ADDR_IER        0x08
#define XLDL_DSOLVE_CONTROL_ADDR_ISR        0x0c
#define XLDL_DSOLVE_CONTROL_ADDR_N_DATA     0x10
#define XLDL_DSOLVE_CONTROL_BITS_N_DATA     32
#define XLDL_DSOLVE_CONTROL_ADDR_X_DATA     0x18
#define XLDL_DSOLVE_CONTROL_BITS_X_DATA     64
#define XLDL_DSOLVE_CONTROL_ADDR_D_DATA     0x24
#define XLDL_DSOLVE_CONTROL_BITS_D_DATA     64
#define XLDL_DSOLVE_CONTROL_ADDR_OUT_R_DATA 0x30
#define XLDL_DSOLVE_CONTROL_BITS_OUT_R_DATA 64

