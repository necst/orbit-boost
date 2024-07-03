#ifndef HEADER_H_GUARD
#define HEADER_H_GUARD

#include <stdint.h>

#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"

#define GUIDO_BASE_ADDR 0xA0000000
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

uint64_t perf_counter_ns();

uint32_t orbitboost_done_or_idle(void *base_ptr);

xclDeviceHandle xclOpenDevice();

void xclCloseDevice(xclDeviceHandle device);

xclBufferHandle xclAllocate(xclDeviceHandle device, uint32_t size);

void xclFree(xclDeviceHandle device, xclBufferHandle buffer);

char *xclMapBuffer(xclDeviceHandle device, xclBufferHandle buffer);

void xclUnmapBuffer(xclDeviceHandle device, xclBufferHandle buffer, char *buffer_ptr);

void xclFlush(xclDeviceHandle device, xclBufferHandle dest, uint32_t size);

void xclInvalidate(xclDeviceHandle device, xclBufferHandle src, uint32_t size);

void generate_random_array(size_t n, double min_value, double max_value, unsigned seed, double* array);

void ensure_bitstream_loaded2() ;

static void ensure_bitstream_loaded();

void* open_device();

void *getBufferPhysicalAddress(xclDeviceHandle device, xclBufferHandle buffer);
#endif // HEADER_H_GUARD