// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.4
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xhog.h"

extern XHog_Config XHog_ConfigTable[];

XHog_Config *XHog_LookupConfig(u16 DeviceId) {
	XHog_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XHOG_NUM_INSTANCES; Index++) {
		if (XHog_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XHog_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XHog_Initialize(XHog *InstancePtr, u16 DeviceId) {
	XHog_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XHog_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XHog_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif
