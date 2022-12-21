CC=gcc
CCFLAGS= -g -std=c99 -Wall
MODULES= validate.o pgmStruct.o rwPgm.o
MAINS= pgmEcho.o pgmComp.o pgma2b.o pgmb2a.o pgmReduce.o
TARGETS= pgmEcho pgmComp pgma2b pgmb2a pgmReduce

all:	${TARGETS}

clean:
	rm ${TARGETS} ${MAINS} ${MODULES}

pgmEcho:	pgmEcho.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmEcho pgmEcho.o ${MODULES}

pgmComp:	pgmComp.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmComp pgmComp.o ${MODULES}

pgma2b:		pgma2b.o ${MODULES}
	${CC} ${CCFLAGS} -o pgma2b pgma2b.o ${MODULES}

pgmb2a:		pgmb2a.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmb2a pgmb2a.o ${MODULES}

pgmReduce:	pgmReduce.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmReduce pgmReduce.o ${MODULES}

rwPgm:		${MODULES}
	${CC} ${CCFLAGS} -o rwPgm rwPgm.o validate.o pgmStruct.o

pgmStruct:	pgmStruct.o
	${CC} ${CCFLAGS} -o pgmStruct pgmStruct.o

validate:	validate.o rwPgm.o
	${CC} ${CCFLAGS} -o validate validate.o rwPgm.o pgmStruct.o

pgmEcho.o:	pgmEcho.c pgmStruct.c validate.c rwPgm.c	rwPgm.h pgmStruct.h validate.h
	${CC} -c ${CCFLAGS} -o pgmEcho.o 	 pgmEcho.c

pgmComp.o:	pgmComp.c pgmStruct.c validate.c rwPgm.c	rwPgm.h pgmStruct.h validate.h
	${CC} -c ${CCFLAGS} -o pgmComp.o	 pgmComp.c

pgma2b.o:	pgma2b.c pgmStruct.c validate.c rwPgm.c		rwPgm.h pgmStruct.h validate.h
	${CC} -c ${CCFLAGS} -o pgma2b.o		pgma2b.c

pgmb2a.o:	pgmb2a.c pgmStruct.c validate.c rwPgm.c		rwPgm.h pgmStruct.h validate.h
	${CC} -c ${CCFLAGS} -o pgmb2a.o		pgmb2a.c

pgmReduce.o:	pgmReduce.c pgmStruct.c validate.c rwPgm.c	rwPgm.h pgmStruct.h validate.h
	${CC} -c ${CCFLAGS} -o pgmReduce.o	pgmReduce.c

pgmStruct.o:	pgmStruct.c  	pgmStruct.h
	${CC} -c ${CCFLAGS} -o pgmStruct.o   pgmStruct.c	

validate.o:	validate.c rwPgm.c 		rwPgm.h validate.h
	${CC} -c ${CCFLAGS} -o validate.o    validate.c

rwPgm.o:	rwPgm.c pgmStruct.c validate.c		pgmStruct.h rwPgm.h validate.h
	${CC} -c ${CCFLAGS} -o rwPgm.o    rwPgm.c

