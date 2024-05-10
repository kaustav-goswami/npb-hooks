# npb-hooks
Annotating the region of interest for npb.

Refer to NPB 3.4.2 for the updated version of the benchmark.

For instructions on how to compiler, see `NPB3.4.2/NPB3.4.2-OMP/README`.

IMPORTANT NOTE:  This repo is not supposed to be the canonical source for the benchmarks and serves only as an example for annotating the ROI. The source code can be obtained from [NAS Parallel Benchmarks](https://www.nas.nasa.gov/publications/npb.html)

This repo adds ROI hooks for NAS Parallel Benchmark (OMP version for now). In this particular implementation, the hooks are coupled with gem5 specific instructions (m5_dumpreststats) to collect the stats for the ROI. But the hooks can be used for any other tool with minimal effort.

## Summary of the steps taken:

### For the suite:
hooks.c defines the functions called by each benchmark, and the actions to be taken at the start/end of the ROI.
There is one extra `m5_exit` placed before ROI begin and ROI end to take checkpoints if necessary. 

Adding gem5 instructions to the hooks:
In make.common we should add proper compilation options to create object files.

In make.def we should define the path to gem5 directory. Also, -cpp should be added to the fortran compiler (FF) options to enable support for C pre-processors.

### Instructions to compile

Follow these instructions to install/compile the benchmarks
```sh
git clone https://github.com/gem5/gem5.git
cd gem5/util/m5
# configure your cross compiler if needed
scons build/arm64/out/m5 -j8
cd ../..
export GEM5_PATH=`pwd`

# clone this repository
git clone https://github.com/kaustav-goswami/npb-hooks.git 
cd npb-hooks
git checkout kg/npb-3.4.2
cd NPB3.4.2/NPB3.4-OMP
make suite M5_ANNOTATION=1 -j8
```
This will compile all the benchmarks for classes S, A, B, C and D in the bin
directory.

### Known Issues

NPB 3.3.1 has issues compiling some of the benchmarks with hooks enabled.

### For each benchmark in the suite:
The source file (i.e. BENCH.f or BENCH.c) should be modified to call roi_begin and roi_end functions.
In here, we follow a the methodology used by the developers and the function calls are place right before and after the timing procedures.
We use pre-processor for conditional compilation of added function calls (HOOKS).

The make files should be modified to add the object files created (hooks.o).
Also, if hooks are enabled, proper flag should be set (-DHOOKS) in the final step of the compilation process (creating the executable).
These are both done "conditionally" under HOOKS flag (ifeq ($HOOKS, 1)).
