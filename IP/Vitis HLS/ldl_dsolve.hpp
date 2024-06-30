#include <hls_stream.h>
#include <ap_int.h>
#include <cstdint>
#ifndef LDL_DSOLVE_HPP
#define LDL_DSOLVE_HPP
typedef int LDL_int;
typedef ap_uint<128> readType;
typedef ap_uint<64> hreadtype;
#define MAXIDEP 6


void ldl_dsolve(LDL_int n, readType* X, readType* D, readType* out); 


#endif // LDL_DSOLVE_H
