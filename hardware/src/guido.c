#include "guido.h"

#define XLDL_DSOLVE_CONTROL_ADDR
#define XLDL_DSOLVE_CONTROL_ADDR_AP_CTRL 0x00
#define XLDL_DSOLVE_CONTROL_ADDR_GIE 0x04
#define XLDL_DSOLVE_CONTROL_ADDR_IER 0x08
#define XLDL_DSOLVE_CONTROL_ADDR_ISR 0x0c
#define XLDL_DSOLVE_CONTROL_ADDR_X_DATA 0x10
#define XLDL_DSOLVE_CONTROL_BITS_X_DATA 64
#define XLDL_DSOLVE_CONTROL_ADDR_D_DATA 0x1c
#define XLDL_DSOLVE_CONTROL_BITS_D_DATA 64
#define XLDL_DSOLVE_CONTROL_ADDR_OUT_R_DATA 0x28
#define XLDL_DSOLVE_CONTROL_BITS_OUT_R_DATA 64


// Function to perform element-wise division
void LDL_dsolve(int n, double* X, double* D, double* Xout_sw) {
    for (int i = 0; i < n; i++) {
        Xout_sw[i] = X[i] / D[i];
    }
}

// Function to generate an array of random doubles within a specified range
void generate_random_array(int n, double min_value, double max_value, double* array) {
    for (int i = 0; i < n; i++) {
        array[i] = min_value + ((double)rand() / RAND_MAX) * (max_value - min_value);
    }
}

// Function to round the values in an array to a specified number of decimal places
void round_array(int n, double* array, int decimals) {
    double factor = pow(10, decimals);
    for (int i = 0; i < n; i++) {
        array[i] = round(array[i] * factor) / factor;
    }
}

// Function to measure execution time of a function
double measure_execution_time(void (*func)(int, double*, double*, double*), int n, double* X, double* D, double* Xout_sw) {
    clock_t start_time = clock();
    func(n, X, D, Xout_sw);
    clock_t end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

/*
int main() {
    int n = 10000;
    double min_value = 0.1, max_value = 500.0;

    // Allocate memory for arrays
    double* X = (double*)malloc(n * sizeof(double));
    double* D = (double*)malloc(n * sizeof(double));
    double* Xout_sw = (double*)malloc(n * sizeof(double));

    // Seed the random number generator
    srand(time(0));

    // Generate and round random arrays
    generate_random_array(n, min_value, max_value, X);
    round_array(n, X, 7);

    generate_random_array(n, min_value, max_value, D);
    round_array(n, D, 7);

    // Measure execution time
    double exec_time = measure_execution_time(LDL_dsolve, n, X, D, Xout_sw);
    printf("Execution time: %f seconds\n", exec_time);

    // Free allocated memory
    free(X);
    free(D);
    free(Xout_sw);

    return 0;
}
*/

struct guido *guido_init(xlDeviceHandle deviceHandle, uint32_t data_size){
    struct guido *guido = (struct guido *)malloc(sizeof(struct guido));
    guido->deviceHandle = deviceHandle;
    guido->data_size = data_size;
    guido->ip = (struct guido_ip *)malloc(sizeof(struct guido_ip));
    guido->ip->Xbuffer_ptr = (double *)malloc(data_size * sizeof(double));
    guido->ip->Dbuffer_ptr = (double *)malloc(data_size * sizeof(double));
    guido->ip->Xoutbuffer_ptr = (double *)malloc(data_size * sizeof(double));
    return guido;
}

static void ensure_bitsrteam_loaded() {
    // sas??????
}

void load_bitstream(struct guido *guido, const char *bitstream){
    // sas??????
}

void allocate_buffer(struct guido *guido){
    guido->ip->Xbuffer = xclAllocate(guido->deviceHandle, guido->data_size * sizeof(double));
    guido->ip->Dbuffer = xclAllocate(guido->deviceHandle, guido->data_size * sizeof(double));
    guido->ip->Xoutbuffer = xclAllocate(guido->deviceHandle, guido->data_size * sizeof(double));
    guido->ip->axilite_data.X = getBufferPhysicalAddress(guido->deviceHandle, guido->ip->Xbuffer);
    guido->ip->axilite_data.D = getBufferPhysicalAddress(guido->deviceHandle, guido->ip->Dbuffer);
    guido->ip->axilite_data.Xout = getBufferPhysicalAddress(guido->deviceHandle, guido->ip->Xoutbuffer);
    guido->ip->Xbuffer_ptr = (double *)xclMapBuffer(guido->deviceHandle, guido->ip->Xbuffer);
    guido->ip->Dbuffer_ptr = (double *)xclMapBuffer(guido->deviceHandle, guido->ip->Dbuffer);
    guido->ip->Xoutbuffer_ptr = (double *)xclMapBuffer(guido->deviceHandle, guido->ip->Xoutbuffer);
}

void set_n(struct guido *guido, uint8_t n){
    guido->ip->axilite_data.n = n;
}

void write_X(struct guido *guido, double *X){
    for (int i = 0; i < guido->data_size; i++) {
        guido->ip->Xbuffer_ptr[i] = X[i];
    }
}

void write_D(struct guido *guido, double *D){
    for (int i = 0; i < guido->data_size; i++) {
        guido->ip->Dbuffer_ptr[i] = D[i];
    }
}

void read_output(struct guido *guido, double *Xout){
    for (int i = 0; i < guido->data_size; i++) {
        Xout[i] = guido->ip->Xoutbuffer_ptr[i];
    }
}

void free_guido_instance(struct guido *guido){
    xclFree(guido->ip->Xbuffer);
    xclFree(guido->ip->Dbuffer);
    xclFree(guido->ip->Xoutbuffer);
    free(guido->ip->Xbuffer_ptr);
    free(guido->ip->Dbuffer_ptr);
    free(guido->ip->Xoutbuffer_ptr);
    free(guido->ip);
    free(guido);

    // aggiungere xcl close device e funzione open device
}

void sas(){
    printf("sas\n");
}

void guido_write_to_axilite(struct guido *guido, struct guido_axilite_data *axilite_data){
    void *base_ptr = guido->ip->axilite_data.base_ptr;
    // scrivere su registri axilite
    sas();
}

void guido_write_args_to_ip(struct guido *guido){
    guido_write_to_axilite(guido, &guido->ip->axilite_data);
    // scrivere su registri ip
    sas();
}






