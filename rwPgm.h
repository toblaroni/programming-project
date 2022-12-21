#ifndef rwPgm
#define rwPgm

#include <stdio.h> 
#include <stdlib.h>

#include "pgmStruct.h"
#include "validate.h"

// Define all the macros in this header since it's included everywhere.

#define MAX_COMMENT_LINE 128
#define MAX_GRAY_VAL 255
#define MIN_IMAGE_DIMENSION 1
#define MAX_IMAGE_DIMENSION 65536
#define MAX_COMMENT_LENGTH 128
#define MAGIC_NUMBER_RAW 0x3550
#define MAGIC_NUMBER_ASCII 0x3250

// Error codes.
#define EXIT_NO_ERRORS 0
#define EXIT_BAD_ARG_COUNT 1 
#define EXIT_BAD_FILE_NAME 2
#define EXIT_BAD_MAGIC_NUMBER 3
#define EXIT_BAD_COMMENT_LINE 4
#define EXIT_BAD_DIMENSIONS 5
#define EXIT_BAD_MAX_GRAY 6
#define EXIT_MALLOC_FAIL 7
#define EXIT_BAD_DATA 8
#define EXIT_OUTPUT_FAILED 9
#define EXIT_BAD_LAYOUT 10
#define EXIT_MISC 100

void readPgm(pgmData *pgmInput, char *pgmIn);

void readAsciiData(pgmData *pgmInput, char *pgmIn);

void readBinaryData(pgmData *pgmInput, char *pgmIn);

void pgmOut(pgmData *pgmInput, char *outputFileName);

void asciiOut(pgmData *inputImage, char *outputFileName);

void binaryOut(pgmData *inputImage, char *outputFileName);

#endif