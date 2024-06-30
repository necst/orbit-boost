# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
# Tool Version Limit: 2024.05
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
# 
# ==============================================================
source -notrace "/home/xilinx/software/Vitis_HLS/2024.1/common/scripts/ipxhls.tcl"
set ip_dir "/home/users/alessandro.marina/Desktop/2024punto1_component/2024punto1_component/hls/impl/ip"
set data_file "/home/users/alessandro.marina/Desktop/2024punto1_component/2024punto1_component/hls/hls_data.json"
set ip_types "vitis sysgen"
if { [catch {::ipx::utils::package_hls_ip $ip_dir $data_file $ip_types } res] } {
  puts "Caught error:\n$::errorInfo"
  error $res
}