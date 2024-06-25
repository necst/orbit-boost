#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <experimental/xrt_bo.h>

void LDL_dsolve(int n, double* X, double* D, double* Xout_sw);

// Function to generate an array of random doubles within a specified range
void generate_random_array(int n, double min_value, double max_value, double* array);

// Function to round the values in an array to a specified number of decimal places
void round_array(int n, double* array, int decimals);

// Function to measure execution time of a function
double measure_execution_time(void (*func)(int, double*, double*, double*), int n, 
                                            double* X, double* D, double* Xout_sw);


struct guido_axilite_data{
    uint8_t n;
    void *base_ptr;
    double *X;
    double *D;
    double *Xout;
};

struct guido_ip
{
    xclBufferHandle Xbuffer;
    xclBufferHandle Dbuffer;
    xclBufferHandle Xoutbuffer;
    double *Xbuffer_ptr;
    double *Dbuffer_ptr;
    double *Xoutbuffer_ptr;
    struct guido_axilite_data axilite_data;
};

 struct guido{
    xlDeviceHandle deviceHandle;
    uint32_t data_size;
    struct guido_ip *ip;
 };
