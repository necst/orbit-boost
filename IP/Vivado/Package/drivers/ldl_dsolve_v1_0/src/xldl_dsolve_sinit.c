// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xldl_dsolve.h"

extern XLdl_dsolve_Config XLdl_dsolve_ConfigTable[];

#ifdef SDT
XLdl_dsolve_Config *XLdl_dsolve_LookupConfig(UINTPTR BaseAddress) {
	XLdl_dsolve_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XLdl_dsolve_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XLdl_dsolve_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XLdl_dsolve_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XLdl_dsolve_Initialize(XLdl_dsolve *InstancePtr, UINTPTR BaseAddress) {
	XLdl_dsolve_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XLdl_dsolve_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XLdl_dsolve_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XLdl_dsolve_Config *XLdl_dsolve_LookupConfig(u16 DeviceId) {
	XLdl_dsolve_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XLDL_DSOLVE_NUM_INSTANCES; Index++) {
		if (XLdl_dsolve_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XLdl_dsolve_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XLdl_dsolve_Initialize(XLdl_dsolve *InstancePtr, u16 DeviceId) {
	XLdl_dsolve_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XLdl_dsolve_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XLdl_dsolve_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

