#include <stdlib.h>

// #include <math.h>

#include "rwPgm.h"


int main(int argc, char **argv){
    if(argc == 1){
        printf("Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm");
        return EXIT_NO_ERRORS;
    } else if(argc != 4){
        printf("ERROR: Bad Argument Count");
        exit(EXIT_BAD_ARG_COUNT);
    }


    // Create an empty pgmStruct for the input file, populate the struct and then check for errors.
    pgmData *inputImage = pgmInit();
    readPgm(inputImage, argv[1]);
    checkPgmIn(inputImage, argv[1]);


    // Create an empty pgmData struct for the reduced image, free the imageData since we won't need it.
    pgmData *outImage = pgmInit();
    readPgm(outImage, argv[1]);
    checkPgmIn(outImage, argv[1]);


    // Free each row.
    for(int col = 0; col < outImage->height; col ++){
        free(outImage->imageData[col]);
    }
    // Free the top level pointer.
    free(outImage->imageData);
    

    // Get the reduction factor and change it to an int.
    int rFactor = atoi(argv[2]);


    // SANITY CHECKS ON REDUCTION FACTOR
    if(rFactor <= 0){
        free(inputImage);
        miscError("ERROR: Miscellaneous (Reduce factor must be a positive integer.)");
    }


    // Reduce the width and height of the pgmData struct
    int rWidth = (inputImage->width + (rFactor - 1)) / rFactor;
    int rHeight = (inputImage->height + (rFactor - 1)) / rFactor;


    // Set the width and height of the empty struct to these new values.
    outImage->width = rWidth;
    outImage->height = rHeight;


    // Set the nImageBytes and allocate memory for the data.
    outImage->nImageBytes = outImage->width * outImage->height * sizeof(unsigned char);


    // Allocate the data pointer
    outImage->imageData = (unsigned char **) malloc(outImage->height * sizeof(unsigned char *));

    // Check for malloc failure.
    if(outImage->imageData == NULL) mallocFail();

    // Allocate memory the size of the width for each row
    for(int col = 0; col < outImage->height; col++){
        outImage->imageData[col] = (unsigned char *) malloc(outImage->width * sizeof(unsigned char));

        // Check for malloc failure.
        if(outImage->imageData[col] == NULL) mallocFail();
    }


    // Read the data from the input file using the reduction factor.
    for(int col = 0, outCol = 0; col < inputImage->height; col += rFactor, outCol++){
        for(int row = 0, outRow = 0; row < inputImage->width; row += rFactor, outRow++){
            outImage->imageData[outCol][outRow] = (unsigned char) inputImage->imageData[col][row];
        }
    }


    // Free the input image as we are done with using it.
    freePgm(inputImage);
    
    // Output the reduced image and free the output image.
    pgmOut(outImage, argv[3]);
    freePgm(outImage);

    printf("REDUCED");
    return EXIT_NO_ERRORS;
}
