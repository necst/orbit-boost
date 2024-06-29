#include "header.h"
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
#include <time.h>
#include <stdint.h>
#include <sys/sysinfo.h>


uint64_t perf_counter_ns()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (uint64_t)ts.tv_sec * 1000000000 + (uint64_t)ts.tv_nsec;
}

uint32_t orbitboost_done_or_idle(void *base_ptr)
{
    uint32_t state = 0x6;
    
    volatile uint32_t *ptr = base_ptr;

    state &= *((volatile uint32_t*)(ptr + XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL)) & 0x6;
    return state;
}


xclDeviceHandle xclOpenDevice()
{
    xclDeviceHandle device_handle;
    device_handle = xclOpen(0, NULL, 0);

    if (!device_handle) {
        printf("ERROR: Failed to open device\n");
        return NULL;
    }

    return device_handle;
}

void xclCloseDevice(xclDeviceHandle device)
{
    xclClose(device);
}

xclBufferHandle xclAllocate(xclDeviceHandle device, uint32_t size)
{
    xclBufferHandle buffer;
    buffer = xclAllocBO(device, size, XCL_BO_DEVICE_RAM, 0);

    return buffer;
}

void xclFree(xclDeviceHandle device, xclBufferHandle buffer)
{
    if (buffer)
        xclFreeBO(device, buffer);
}



char *xclMapBuffer(xclDeviceHandle device, xclBufferHandle buffer)
{
    char *buffer_ptr;
    buffer_ptr = xclMapBO(device, buffer, true);

    if (buffer_ptr == NULL) {
        printf("ERROR: Failed to map BO buffer\n");
        exit(1);
    }

    return buffer_ptr;
}

void xclUnmapBuffer(xclDeviceHandle device, xclBufferHandle buffer, char *buffer_ptr)
{
    xclUnmapBO(device, buffer, buffer_ptr);
}

void xclFlush(xclDeviceHandle device, xclBufferHandle dest, uint32_t size)
{
    if (xclSyncBO(device, dest, XCL_BO_SYNC_BO_TO_DEVICE, size, 0)) {
        printf("ERROR: Failed to flush BO buffer\n");
        exit(1);
    }
}

void xclInvalidate(xclDeviceHandle device, xclBufferHandle src, uint32_t size)
{
    if (xclSyncBO(device, src, XCL_BO_SYNC_BO_FROM_DEVICE, size, 0)) {
        printf("ERROR: Failed to invalidate BO buffer\n");
        exit(1);
    }
}

void generate_random_array(size_t n, double min_value, double max_value, unsigned seed, double* array) {
    srand(seed);
    for (size_t i = 0; i < n; ++i) {
        double scale = rand() / (double) RAND_MAX; // Generate a random number between 0 and 1
        array[i] = min_value + scale * (max_value - min_value); // Scale to the desired range
    }
}

void ensure_bitstream_loaded2() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char *argv[] = {
            "/usr/bin/env",
            "LD_LIBRARY_PATH=/usr/lib",
            "/usr/local/share/pynq-venv/bin/python3",
            "-c",
            "from pynq import Overlay, Clocks; Overlay('./bitstream/doublerate.bit'); Clocks.fclk0_mhz = 300;",
            NULL
        };
        execvp(argv[0], argv);
        _exit(EXIT_FAILURE); // If execvp fails
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Failed to load bitstream\n");
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Failed to fork process for loading bitstream\n");
        exit(EXIT_FAILURE);
    }
}

static void ensure_bitstream_loaded()
{
    char argv1[] = "/usr/local/share/pynq-venv/bin/python3";
    char argv2[] = "-c";
    char argv3[] = "from pynq import Overlay, Clocks; Overlay('./bitstream/doublerate.bit'); Clocks.fclk0_mhz = 200;";
    char *argv[] = {argv1, argv2, argv3, NULL};
    close(0);
    close(1);
    execvp(argv[0], argv);
}


void* open_device()
{
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        printf("Error opening /dev/mem\n");
        exit(1);
    }

    void *base_ptr = mmap(NULL, 0x100000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GUIDO_BASE_ADDR);
    if (base_ptr == MAP_FAILED) {
        printf("Error mapping memory\n");
        exit(1);
    }

#if DEBUG
    printf("Mapped memory at %p\n", base_ptr);
#endif 

    close(fd);

    return base_ptr;
}

void *getBufferPhysicalAddress(xclDeviceHandle device, xclBufferHandle buffer)
{
    struct xclBOProperties props;
    xclGetBOProperties(device, buffer, &props);

    if (props.paddr >= 0x80000000) {
        printf("ERROR: Memory allocation did not success\n");
        exit(1);
    }

    return (void *)props.paddr;
}
