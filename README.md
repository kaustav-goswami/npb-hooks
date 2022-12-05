This repo adds m5 annotations to the NAS Parallel Benchmarks.

The annotations are added as follows,
- An `m5_exit()` call before `timer_start()`.
- An `m5_exit()` call before `timer_read()`.

In order to compile the benchmarks with m5 annotations, the
following environment variables must be set,

```sh
M5_ANNOTATION # If M5_ANNOTATION=1, the build system will compile the binaries
              # with m5 annotations.

GEM5_INCLUDE_DIR # Path to the gem5's include/ directory.
                 # Typically, the path is gem5/include.

GEM5_M5_ABI_DIR # Path to m5 utility abi folder for a specific ISA.
                # Typically,
                # For x86: gem5/util/m5/src/abi/x86/
                # For arm64: gem5/util/m5/src/abi/arm64/
                # For riscv: gm5/util/m5/src/abi/riscv
```

If you're cross compiling, you might want to set additional environment
variables as follows,

```sh
FC # Path to the gfortran compiler for compiling **guest** binaries.
CC # Path to the gcc compiler for compiling **guest** binaries.
UCC # Path to the gcc compiler for compiling utilities **guest** objects.
SYS_UCC # Path to the gcc compiler for compiling utilities **host** objects.
```
