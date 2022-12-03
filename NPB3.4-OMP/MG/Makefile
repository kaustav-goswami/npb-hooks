SHELL=/bin/sh
BENCHMARK=mg
BENCHMARKU=MG

include ../config/make.def

OBJS = mg.o mg_data.o ${COMMON}/print_results.o  \
       ${COMMON}/${RAND}.o ${COMMON}/timers.o ${COMMON}/wtime.o

ifeq (${M5_ANNOTATION}, 1)
	OBJS += ${COMMON}/m5_interface.o ${COMMON}/m5op.o
endif

include ../sys/make.common

${PROGRAM}: config ${OBJS}
	${FLINK} ${FLINKFLAGS} -o ${PROGRAM} ${OBJS} ${F_LIB}

.f90.o:
ifeq (${M5_ANNOTATION}, 1)
	${FCOMPILE} -DM5_ANNOTATION $<
else
	${FCOMPILE} $<
endif

mg.o:		mg.f90 mg_data.o
mg_data.o:      mg_data.f90 npbparams.h

clean:
	- rm -f *.o *~ *.mod
	- rm -f npbparams.h core
	- if [ -d rii_files ]; then rm -r rii_files; fi
