#include <gem5/m5ops.h>
#include <stdlib.h>

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
