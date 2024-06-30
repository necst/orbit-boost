// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XLDL_DSOLVE_H
#define XLDL_DSOLVE_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xldl_dsolve_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Control_BaseAddress;
} XLdl_dsolve_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XLdl_dsolve;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XLdl_dsolve_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XLdl_dsolve_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XLdl_dsolve_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XLdl_dsolve_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XLdl_dsolve_Initialize(XLdl_dsolve *InstancePtr, UINTPTR BaseAddress);
XLdl_dsolve_Config* XLdl_dsolve_LookupConfig(UINTPTR BaseAddress);
#else
int XLdl_dsolve_Initialize(XLdl_dsolve *InstancePtr, u16 DeviceId);
XLdl_dsolve_Config* XLdl_dsolve_LookupConfig(u16 DeviceId);
#endif
int XLdl_dsolve_CfgInitialize(XLdl_dsolve *InstancePtr, XLdl_dsolve_Config *ConfigPtr);
#else
int XLdl_dsolve_Initialize(XLdl_dsolve *InstancePtr, const char* InstanceName);
int XLdl_dsolve_Release(XLdl_dsolve *InstancePtr);
#endif

void XLdl_dsolve_Start(XLdl_dsolve *InstancePtr);
u32 XLdl_dsolve_IsDone(XLdl_dsolve *InstancePtr);
u32 XLdl_dsolve_IsIdle(XLdl_dsolve *InstancePtr);
u32 XLdl_dsolve_IsReady(XLdl_dsolve *InstancePtr);
void XLdl_dsolve_EnableAutoRestart(XLdl_dsolve *InstancePtr);
void XLdl_dsolve_DisableAutoRestart(XLdl_dsolve *InstancePtr);

void XLdl_dsolve_Set_n(XLdl_dsolve *InstancePtr, u32 Data);
u32 XLdl_dsolve_Get_n(XLdl_dsolve *InstancePtr);
void XLdl_dsolve_Set_X(XLdl_dsolve *InstancePtr, u64 Data);
u64 XLdl_dsolve_Get_X(XLdl_dsolve *InstancePtr);
void XLdl_dsolve_Set_D(XLdl_dsolve *InstancePtr, u64 Data);
u64 XLdl_dsolve_Get_D(XLdl_dsolve *InstancePtr);
void XLdl_dsolve_Set_out_r(XLdl_dsolve *InstancePtr, u64 Data);
u64 XLdl_dsolve_Get_out_r(XLdl_dsolve *InstancePtr);

void XLdl_dsolve_InterruptGlobalEnable(XLdl_dsolve *InstancePtr);
void XLdl_dsolve_InterruptGlobalDisable(XLdl_dsolve *InstancePtr);
void XLdl_dsolve_InterruptEnable(XLdl_dsolve *InstancePtr, u32 Mask);
void XLdl_dsolve_InterruptDisable(XLdl_dsolve *InstancePtr, u32 Mask);
void XLdl_dsolve_InterruptClear(XLdl_dsolve *InstancePtr, u32 Mask);
u32 XLdl_dsolve_InterruptGetEnabled(XLdl_dsolve *InstancePtr);
u32 XLdl_dsolve_InterruptGetStatus(XLdl_dsolve *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
