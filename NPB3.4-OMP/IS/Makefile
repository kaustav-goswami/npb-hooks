SHELL=/bin/sh
BENCHMARK=is
BENCHMARKU=IS

include ../config/make.def

include ../sys/make.common

OBJS = is.o \
       ${COMMON}/c_print_results.o \
       ${COMMON}/c_timers.o \
       ${COMMON}/c_wtime.o

ifeq (${M5_ANNOTATION}, 1)
	OBJS += ${COMMON}/m5_interface.o ${COMMON}/m5op.o
endif

${PROGRAM}: config ${OBJS}
	${CLINK} ${CLINKFLAGS} -o ${PROGRAM} ${OBJS} ${C_LIB}

.c.o:
ifeq (${M5_ANNOTATION}, 1)
	${CCOMPILE} -DM5_ANNOTATION $<
else
	${CCOMPILE} $<
endif

is.o:             is.c  npbparams.h


clean:
	- rm -f *.o *~ mputil*
	- rm -f npbparams.h core
	- if [ -d rii_files ]; then rm -r rii_files; fi
