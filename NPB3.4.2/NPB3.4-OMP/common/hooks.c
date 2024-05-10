#include <stdio.h>
#include <m5_mmap.h>
#include <gem5/m5ops.h>


// void init() __attribute__((constructor));

void init_() {

	//__attribute__ makes this function get called before main()
	// need to mmap /dev/mem
    m5op_addr = 0x10010000;
	map_m5_mem();
}

void uninit_() {
    printf(" --------------------- UNMAP M5 -------------------- \n");
    system("numastat");
    unmap_m5_mem();
}

void m5_exit_interface_() {
    printf(" --------------------- M5 EXIT --------------------- \n");
    // this function calls m5_exit
    m5_exit_addr(0);
}

void m5_work_begin_interface_(){

	printf(" -------------------- ROI BEGIN -------------------- \n");
	m5_work_begin_addr(0,0);
	}

void m5_work_end_interface_(){
       	printf(" -------------------- ROI END -------------------- \n");
	m5_work_end_addr(0,0);
	}
