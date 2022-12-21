#include <stdio.h>
#include <stdlib.h>

#include "rwPgm.h"

// argv[0]: executable name
// argv[1]: input file name
// argv[2]: output file name

int main(int argc, char **argv){
    if(argc == 1){
        printf("Usage: %s inputImage.pgm outputImage.pgm", argv[0]);
	    return 0;
    } 

    checkArgCount(argc);

    char *imageIn = argv[1];
    char *imageOut = argv[2];

    // Create an empty pgm structure.
    pgmData *inputImage = pgmInit();

    // Read in the data from the file.
    readPgm(inputImage, imageIn);

    // Check for errors in the data fields
    checkPgmIn(inputImage, imageIn);

    // Output the image
    pgmOut(inputImage, imageOut);

    freePgm(inputImage);

    printf("ECHOED");
    return EXIT_NO_ERRORS;
}
