#include "ldl_dsolve.hpp"
#include <cstdint>
#include <iostream>

typedef union my_union_u
{
    double value;
    /// A byte array large enough to hold the largest of any value in the union.
    uint64_t bytes;
} my_union_t;

int main() {
    // double X

    LDL_int n = 6;

    double X[] = {61.5, 60.0, 60.0, 60.0, 60.0, 60.0};
    double D[] = {2.0, 4.0, 6.0, 8.0, 10.0, 12.0};
    double temp = X[0];

    my_union_t t2;
    my_union_t t1;

    my_union_t z2;
    my_union_t z1;



    readType Xr[n/2], Dr[n/2];
    
    for(int i = 0; i < n; i+= 2) {

        
        t1.value = X[i+1];
        t2.value = X[i];

        
        z1.value = D[i+1];
        z2.value = D[i];
        

        hreadtype t1b = t1.bytes;
        hreadtype t2b = t2.bytes;
        
        hreadtype z1b = z1.bytes;
        hreadtype z2b = z2.bytes;


        // hreadtype t1.range(63,0) = (hreadtype) X[i+1];
        // hreadtype t2.range(63,0) = (hreadtype) X[i];
        readType temp1 = t1b.concat(t2b);

        readType temp2 = z1b.concat(z2b);

        Xr[i/2] = temp1;
        Dr[i/2] = temp2;
    }
    
    readType Xout[n/2];

    my_union_t Xfinal[n];

    ldl_dsolve(n, Xr, Dr, Xout);
    
    my_union_t a, b;

    for(int i = 0;i < n; i += 2) {
        a.bytes = Xout[i/2].range(63, 0);
        b.bytes = Xout[i/2].range(127, 64);
        // std::cout << a << " ";
        // std::cout << b << " ";
        Xfinal[i].bytes = a.bytes;
        Xfinal[i+1].bytes = b.bytes;

    }

    std::cout << "Results: ";
    for (int i = 0; i < n; i++) {
        std::cout << Xfinal[i].value << " ";
    }
    std::cout << std::endl;

    

    return 0;
}

