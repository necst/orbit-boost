// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xldl_dsolve.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XLdl_dsolve_CfgInitialize(XLdl_dsolve *InstancePtr, XLdl_dsolve_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XLdl_dsolve_Start(XLdl_dsolve *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL) & 0x80;
    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XLdl_dsolve_IsDone(XLdl_dsolve *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XLdl_dsolve_IsIdle(XLdl_dsolve *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XLdl_dsolve_IsReady(XLdl_dsolve *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XLdl_dsolve_EnableAutoRestart(XLdl_dsolve *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XLdl_dsolve_DisableAutoRestart(XLdl_dsolve *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL, 0);
}

void XLdl_dsolve_Set_n(XLdl_dsolve *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_N_DATA, Data);
}

u32 XLdl_dsolve_Get_n(XLdl_dsolve *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_N_DATA);
    return Data;
}

void XLdl_dsolve_Set_X(XLdl_dsolve *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_X_DATA, (u32)(Data));
    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_X_DATA + 4, (u32)(Data >> 32));
}

u64 XLdl_dsolve_Get_X(XLdl_dsolve *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_X_DATA);
    Data += (u64)XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_X_DATA + 4) << 32;
    return Data;
}

void XLdl_dsolve_Set_D(XLdl_dsolve *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_D_DATA, (u32)(Data));
    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_D_DATA + 4, (u32)(Data >> 32));
}

u64 XLdl_dsolve_Get_D(XLdl_dsolve *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_D_DATA);
    Data += (u64)XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_D_DATA + 4) << 32;
    return Data;
}

void XLdl_dsolve_Set_out_r(XLdl_dsolve *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_OUT_R_DATA, (u32)(Data));
    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_OUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XLdl_dsolve_Get_out_r(XLdl_dsolve *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_OUT_R_DATA);
    Data += (u64)XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_OUT_R_DATA + 4) << 32;
    return Data;
}

void XLdl_dsolve_InterruptGlobalEnable(XLdl_dsolve *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_GIE, 1);
}

void XLdl_dsolve_InterruptGlobalDisable(XLdl_dsolve *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_GIE, 0);
}

void XLdl_dsolve_InterruptEnable(XLdl_dsolve *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_IER);
    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_IER, Register | Mask);
}

void XLdl_dsolve_InterruptDisable(XLdl_dsolve *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_IER);
    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_IER, Register & (~Mask));
}

void XLdl_dsolve_InterruptClear(XLdl_dsolve *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLdl_dsolve_WriteReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_ISR, Mask);
}

u32 XLdl_dsolve_InterruptGetEnabled(XLdl_dsolve *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_IER);
}

u32 XLdl_dsolve_InterruptGetStatus(XLdl_dsolve *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XLdl_dsolve_ReadReg(InstancePtr->Control_BaseAddress, XLDL_DSOLVE_CONTROL_ADDR_ISR);
}

