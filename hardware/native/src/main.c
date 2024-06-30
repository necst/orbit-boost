#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "header.h"


#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"




#define N 6

int main(int argc, char** argv) {

    uint32_t size = N;
    unsigned seed = 42;  // Seed for reproducibility

    // Open device
    xclDeviceHandle device = xclOpenDevice();
    if (device == NULL) {
        return 1;
    }

    void *base_ptr = open_device();

    // Allocate memory for arrays
    xclBufferHandle X_handle = xclAllocate(device, size * sizeof(double));
    xclBufferHandle D_handle = xclAllocate(device, size * sizeof(double));
    xclBufferHandle Xout_handle = xclAllocate(device, size * sizeof(double));


    double *X_pa = getBufferPhysicalAddress(device, X_handle);
    double *D_pa = getBufferPhysicalAddress(device, D_handle);
    double *Xout_pa = getBufferPhysicalAddress(device, Xout_handle);
    


    // Map buffers to user space
    double *X_ptr = xclMapBuffer(device, X_handle);
    double *D_ptr = xclMapBuffer(device, D_handle);
    double *Xout_ptr = xclMapBuffer(device, Xout_handle);



    // Fill buffers with data
    double X[N] = {10.5, 10.5, 10.5, 10.5, 10.5, 10.5};
    double D[N] = {2.5, 2.5, 2.5, 2.5, 2.5, 2.5};
    double Xout[N] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

    memcpy(X_ptr, X, size * sizeof(double));
    memcpy(D_ptr, D, size * sizeof(double));

    xclFlush(device, X_handle, size * sizeof(double));
    xclFlush(device, D_handle, size * sizeof(double));

    *((volatile uint32_t*) (base_ptr + XLDL_DSOLVE_CONTROL_ADDR_N_DATA)) = N;
    *((volatile uint32_t*) (base_ptr + XLDL_DSOLVE_CONTROL_ADDR_X_DATA)) = (uint32_t) ((uint64_t)X_pa & 0xffffffff);
    *((volatile uint32_t*) (base_ptr + XLDL_DSOLVE_CONTROL_ADDR_D_DATA)) = (uint32_t) ((uint64_t)D_pa & 0xffffffff);
    *((volatile uint32_t*) (base_ptr + XLDL_DSOLVE_CONTROL_ADDR_OUT_R_DATA)) = (uint32_t) ((uint64_t)Xout_pa & 0xffffffff);

    volatile uint32_t *ptr = base_ptr;

    //print physical addresses
    printf("X_pa = %p\n", X_pa);
    printf("D_pa = %p\n", D_pa);
    printf("Xout_pa = %p\n", Xout_pa);

    //xcl buffer content print
    for (int i = 0; i < N; i++) {
        printf("X_ptr[%d] = %f\n", i, X_ptr[i]);
        printf("X_ptr[%d] = %f\n", i, X_ptr[i]);
        printf("Xout_ptr[%d] = %f\n", i, X_ptr[i]);
    }
    


    uint64_t start_time = perf_counter_ns();

    *((volatile uint32_t*) (ptr + XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL)) = 0x1;

    while(!orbitboost_done_or_idle(base_ptr))
    {
        printf("Waiting for the accelerator to finish\n");
    }

    uint64_t end_time = perf_counter_ns();

    printf("Execution time: %lu ns\n", end_time - start_time);

    
    xclInvalidate(device, Xout_handle, N * sizeof(double));



        
    memcpy(Xout, Xout_ptr, N * sizeof(double));

    //print the Xout_ptr
    for (int i = 0; i < N; i++) {
        printf("Xout[%d] = %f\n", i, Xout[i]);
    }

    xclUnmapBuffer(device, X_handle, X_ptr);
    xclUnmapBuffer(device, D_handle, D_ptr);
    xclUnmapBuffer(device, Xout_handle, Xout_ptr);


    xclFree(device, X_handle);
    xclFree(device, D_handle);
    xclFree(device, Xout_handle);

    xclCloseDevice(device);

    munmap(base_ptr, 0x100000);
    
    return 0;
}
