#include <gem5/m5ops.h>
#include <m5_mmap.h>
#include <stdlib.h>

void init_() {
    // Has to be called using addr as we are using kvm to boot the CPUs
    m5op_addr = 0x10010000;
    map_m5_mem();
}

void uninit_() {
    // Unlikely that the program will reach here
    unmap_m5_mem();
}

void m5_exit_interface_() {
    m5_exit(0);
}

void m5_work_begin_interface_()
{
    m5_work_begin(0, 0);
}

void m5_work_end_interface_()
{
    m5_work_end(0, 0);
}

// putting numastat as a system call to get the numa statistics
void numa_info_() {
    system("numastat");
}
