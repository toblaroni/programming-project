#include "pgmStruct.h"
#include "validate.h"
#include <stdio.h>
#include <stdlib.h>


// RETURNS AN EMPTY PGM STRUCT
pgmData *pgmInit(){

    // Initialise all data to 0 and all pointers to NULL
    pgmData *pgmImage = (pgmData *) malloc(sizeof(pgmData));

    // Check for malloc failure.
    if(pgmImage == NULL){
        mallocFail();
    }

    pgmImage->magic_number[0] = 0;
    pgmImage->magic_number[1] = 0;
    pgmImage->magic_Number = NULL;

    pgmImage->commentLine = NULL;

    pgmImage->width = 0;
    pgmImage->height = 0;

    pgmImage->maxGray = 0;

    pgmImage->imageData = NULL;
    pgmImage->nImageBytes = 0;

    pgmImage->inputFile = NULL;

    return pgmImage;
}


void freePgm(pgmData *image){

    // Free up the image data
    free(image->commentLine);

    // Free up the imageData rows.
    for(int col = 0; col < image->height; col ++){
        free(image->imageData[col]);
    }

    // Free the top level pointer.
    free(image->imageData);
    free(image);

}