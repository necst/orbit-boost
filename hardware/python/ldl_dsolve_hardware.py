import pynq
from pynq import Overlay
import numpy as np
import struct

def hardware_division(X, D, n):
    if len(X) != n or len(D) != n:
        raise ValueError("The length of both arrays must be equal to n")
    
    padding = False
    if n % 2 == 1:  # If the length of the arrays is odd, make them even
        padding = True
        n += 1
        X.append(1.0)
        D.append(1.0)

    # Load the overlay
    alveare = Overlay("./bitstream/doublerate.bit")
    ape = alveare.ldl_dsolve_0

    # Allocate buffers
    X_hw = pynq.allocate(n, np.float64)
    D_hw = pynq.allocate(n, np.float64)
    Xout_hw = pynq.allocate(n, np.uint64)

    # Transfer data to the buffers
    X_hw[:] = X
    D_hw[:] = D

    # Communicate the buffer addresses
    ape.write(0x18, X_hw.physical_address)
    ape.write(0x24, D_hw.physical_address)
    ape.write(0x30, Xout_hw.physical_address)
    ape.write(0x10, n)

    # Start the hardware operation
    ape.write(0x00, 0x01)
    
    # Polling until operation is complete
    while ape.read(0x00) & 0x4 != 4:
        pass
    
    # Read back the result
    Xout_hw.sync_from_device()

    # Convert the result from uint64 to double
    Xfinal = []
    if padding:
        n -= 1

    for i in range(n):
        uint64_bytes = struct.pack('Q', Xout_hw[i])
        double_value = struct.unpack('d', uint64_bytes)[0]
        Xfinal.append(double_value)
    
    return Xfinal