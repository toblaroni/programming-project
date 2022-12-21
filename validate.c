#include <stdlib.h>
#include "validate.h"

void checkArgCount(int argc){
    if(argc != 3){
        printf("ERROR: Bad Argument Count");
        exit(EXIT_BAD_ARG_COUNT);
    }
}

void checkFile(pgmData *pgmImage, char *fileName){
    // Check if file pointer is NULL
    if(pgmImage->inputFile == NULL){
        printf("ERROR: Bad File Name (%s)", fileName);
        exit(EXIT_BAD_FILE_NAME); 
    } 
}

void checkMagicNum(pgmData *pgmImage, char *fileName){
    if(*pgmImage->magic_Number != MAGIC_NUMBER_ASCII && 
       *pgmImage->magic_Number != MAGIC_NUMBER_RAW){
        free(pgmImage);
        printf("ERROR: Bad Magic Number (%s)", fileName);
        exit(EXIT_BAD_MAGIC_NUMBER); 
    }
}

void checkComment(pgmData *pgmImage, char *fileName){
    // Check if the comment pointer is NULL
    if (pgmImage->commentLine == NULL){
        free(pgmImage->commentLine);
        free(pgmImage);
        printf("ERROR: Bad Comment Line (%s)", fileName);
        exit(EXIT_BAD_COMMENT_LINE);
    }
}

void checkDimensions(pgmData *pgmImage, char *fileName){
    if (pgmImage->width < MIN_IMAGE_DIMENSION  ||  pgmImage->height >= MAX_IMAGE_DIMENSION  ||  pgmImage->width >= MAX_IMAGE_DIMENSION ||  pgmImage->height < MIN_IMAGE_DIMENSION){
        free(pgmImage->commentLine);
        free(pgmImage);
        printf("ERROR: Bad Dimensions (%s)", fileName);
        exit(EXIT_BAD_DIMENSIONS); 
    }
}

void checkMaxgray(pgmData *pgmImage, char *fileName){
    if (pgmImage->maxGray > MAX_GRAY_VAL){
        free(pgmImage->commentLine);
        free(pgmImage);
        printf("ERROR: Bad Max Gray Value (%s)", fileName);
        exit(EXIT_BAD_MAX_GRAY);
    }
}

void checkData(pgmData *pgmImage, int grayVal, char *fileName, int version){
    if(version == 0 && grayVal < 0){
        freePgm(pgmImage);
        printf("ERROR: Bad Data (%s)", fileName);
        exit(EXIT_BAD_DATA);
    } else if (version == 1 && grayVal != -1){
        freePgm(pgmImage);
        printf("ERROR: Bad Data (%s)", fileName);
        exit(EXIT_BAD_DATA);
    } 
}

void mallocFail(){
    printf("ERROR: Image Malloc Failed");
    exit(EXIT_MALLOC_FAIL);
}

void checkOutput(pgmData *inputImage, FILE *outputFile, char *outputFileName){
	if(outputFile == NULL){
        freePgm(inputImage);
        printf("ERROR: Output Failed (%s)", outputFileName);
        exit(EXIT_OUTPUT_FAILED);
	}
}

void miscError(char *msg){
    printf("%s", msg);
    exit(EXIT_MISC);
}

void checkPgmIn(pgmData *pgmImage, char *fileName){

    // Sanity check on inputfile
    checkFile(pgmImage, fileName);

    // Check the magic number
    checkMagicNum(pgmImage, fileName);

    // Check comment line
    checkComment(pgmImage, fileName);

    // Check width, height
    checkDimensions(pgmImage, fileName);

    // Check maxGray
    checkMaxgray(pgmImage, fileName);
}
