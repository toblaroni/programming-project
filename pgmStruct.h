// HOLDS THE DATA FOR THE PGM FILES

#ifndef pgmStruct
#define pgmStruct

#include <stdio.h>


typedef struct pgmData {
// Store the magic number
    unsigned char magic_number[2];
    unsigned short *magic_Number;

// Store 1 comment
    char *commentLine;

// Store the width and Height
    unsigned int width, height;

// Maximum gray value
    unsigned int maxGray;

// Pointer raw image data
    unsigned char **imageData;
    unsigned long nImageBytes;

// Create a file pointer to read in the data
    FILE *inputFile;

	
} pgmData;

// Function for creating an empty pgm Image struct
pgmData *pgmInit();

void freePgm(pgmData *image);

#endif
