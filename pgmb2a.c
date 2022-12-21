#include "rwPgm.h"

int main(int argc, char **argv){
    if(argc == 1 ){
        printf("Usage: %s inputImage.pgm outputImage.pgm", argv[0]);
        return EXIT_NO_ERRORS;
    }

    checkArgCount(argc);

    char *fileNameIn = argv[1];
    char *fileNameOut = argv[2];

    // Make an empty pgmStruct and then populate the data fields
    pgmData *bIn = pgmInit();
    readPgm(bIn, fileNameIn);

    // If input file is ascii then exit.
    if(*bIn->magic_Number == MAGIC_NUMBER_ASCII){
        freePgm(bIn);
        printf("ERROR: Bad Magic Number (%s)", fileNameIn);
        exit(EXIT_BAD_MAGIC_NUMBER);
    }

    // Check the pgm file
    checkPgmIn(bIn, fileNameIn);

    // Output the file as binary
    asciiOut(bIn, fileNameOut);

    printf("CONVERTED");
    return EXIT_NO_ERRORS;
}