#include "rwPgm.h"

// CODE FOR READING PGM DATA

// Image data is read in separate functions for ascii and binary.
void readPgm(pgmData *pgmInput, char *pgmIn){

    // Open the input file
    pgmInput->inputFile = fopen(pgmIn, "r"); 
    
    // SANITY CHECK ON INPUTFILE
    checkFile(pgmInput, pgmIn);


    // Read in the magic number
    pgmInput->magic_number[0] = getc(pgmInput->inputFile);
    pgmInput->magic_number[1] = getc(pgmInput->inputFile);
    pgmInput->magic_Number = (unsigned short *) pgmInput->magic_number;

    // Sanity checks on magic number
    checkMagicNum(pgmInput, pgmIn);


    // Scan whitespace if it's there
    fscanf(pgmInput->inputFile, " ");


    // Read in a comment if it's there
    char nextChar = fgetc(pgmInput->inputFile);
    if (nextChar == '#'){
        ungetc(nextChar, pgmInput->inputFile);

        // Allocate memory to store the comment line.
        pgmInput->commentLine = (char *) malloc(MAX_COMMENT_LINE);

        // Check for malloc failure
        if(pgmInput->commentLine == NULL) mallocFail();

        int commentIndex = 0;
        while(1){

            char nextChar = fgetc(pgmInput->inputFile);

            // If the comment is longer than max length exit the program.
            if(commentIndex == MAX_COMMENT_LENGTH && nextChar != '\n'){
                free(pgmInput->commentLine);
                free(pgmInput);
                printf("ERROR: Bad Comment Line (%s)", pgmIn);
                exit(EXIT_BAD_COMMENT_LINE);
            }             

            // Store the comment char by char
            *(pgmInput->commentLine + commentIndex) = nextChar;

            // Break if a new line character is reached.
            if(nextChar == '\n'){
                break;
            }

            // Increment the index.
            commentIndex ++;
        }

        // perform sanity checks on the comment line
        checkComment(pgmInput, pgmIn);

    } else {
        // There's no comment
        // Release the character.
        ungetc(nextChar, pgmInput->inputFile);

    	// Set the comment line to empty
	    pgmInput->commentLine = (char *) malloc(sizeof(char));

        // Check for malloc failure.
        if(pgmInput->commentLine == NULL) mallocFail();

	    *(pgmInput->commentLine) = ' ';
    }

    // Read in width, height and maxGray
    fscanf(pgmInput->inputFile, " %u %u %u ", &(pgmInput->width), &(pgmInput->height), &(pgmInput->maxGray));

    //Sanity checks on dimensions and maxgray
    checkDimensions(pgmInput, pgmIn);
    checkMaxgray(pgmInput, pgmIn);


    // Allocate the data pointer
    pgmInput->nImageBytes = pgmInput->width * pgmInput->height * sizeof(unsigned char);
    pgmInput->imageData = (unsigned char **) malloc(pgmInput->height * sizeof(unsigned char *));

    // Check for malloc failure.
    if(pgmInput->imageData == NULL) mallocFail();

    // Allocate memory the size of the width for each row
    for(int col = 0; col < pgmInput->height; col++){
        pgmInput->imageData[col] = (unsigned char *) malloc(pgmInput->width * sizeof(unsigned char));

        // Check for malloc failure
        if(pgmInput->imageData[col] == NULL) mallocFail();
    }


    // Read in binary or ASCII data depending on the magic_Number...
    if(*pgmInput->magic_Number == MAGIC_NUMBER_ASCII){
        readAsciiData(pgmInput, pgmIn);
    } else {
        readBinaryData(pgmInput, pgmIn);
    }
}


void readAsciiData(pgmData *pgmInput, char *pgmIn){
    int grayValue;
    
    for(int col = 0; col < pgmInput->height; col ++){
        for(int row = 0; row < pgmInput->width; row ++){
            grayValue = -1;

            fscanf(pgmInput->inputFile, " %u", &(grayValue));

             // Sanity check
             checkData(pgmInput, grayValue, pgmIn, 0);

            // Store the value
            pgmInput->imageData[col][row] = (unsigned char) grayValue;
        }
    }

    // Scan an extra value, if it scans a value then there's too much data.
    grayValue = -1;
    fscanf(pgmInput->inputFile, " %u", &(grayValue));
    checkData(pgmInput, grayValue, pgmIn, 1);

    // Close the input file as we have stored all the data.
    fclose(pgmInput->inputFile);
}


void readBinaryData(pgmData *pgmInput, char *pgmIn){

    int totalBytesRead = 0;

    // Read in the data byte by byte.
    for(int col = 0; col < pgmInput->height; col ++){
        for(int row = 0; row < pgmInput->width; row ++){
            int bRead = 0;
            bRead = fread(&(pgmInput->imageData[col][row]), sizeof(unsigned char), 1, pgmInput->inputFile);

            totalBytesRead += bRead;
        }
    }

    // If there's too little data output error.
    if(totalBytesRead != pgmInput->nImageBytes || getc(pgmInput->inputFile) != EOF){
        freePgm(pgmInput);
        printf("ERROR: Bad Data (%s)", pgmIn);
        exit(EXIT_BAD_DATA);
    }

    // Close the input file
    fclose(pgmInput->inputFile);
}



// CODE FOR WRITING PGM FILES.

void pgmOut(pgmData *inputImage, char* outputFileName){
    if(*inputImage->magic_Number == MAGIC_NUMBER_ASCII){
        asciiOut(inputImage, outputFileName);
    } else {
        binaryOut(inputImage, outputFileName);
    }
}

void asciiOut(pgmData *inputImage, char *outputFileName){

    //Open an output file.
    FILE *outputImage = fopen(outputFileName, "w");

    // Sanity checks on output file
    checkOutput(inputImage, outputImage, outputFileName);


    // Ouput the magic number, width, height and max gray.
    fprintf(outputImage, "P2\n%d %d\n%d\n", inputImage->width, inputImage->height, inputImage->maxGray);


    // Create a pointer to move over the data values
    for(int col = 0; col < inputImage->height; col ++){
        for(int row = 0; row < inputImage->width; row ++){
            int index = col * inputImage->width + row + 1;
            int nextCol = index % inputImage->width;

            fprintf(outputImage, "%d%c", inputImage->imageData[col][row], (nextCol ? ' ' : '\n'));
        }
    }

    // Close the output image.
    fclose(outputImage);
}


void binaryOut(pgmData *inputImage, char *outputFileName){

    //Open an output file.
    FILE *outputImage = fopen(outputFileName, "w");

    // Sanity checks on output file
    checkOutput(inputImage, outputImage, outputFileName);


    // Ouput the magic number, width, height and max gray.
    fprintf(outputImage, "P5\n%d %d\n%d\n", inputImage->width, inputImage->height, inputImage->maxGray);


    // Write the data to the output file

    for(int col = 0; col < inputImage->height; col ++){
        for(int row = 0; row < inputImage->width; row ++){
            int wCount = -1;
            wCount = fwrite(&(inputImage->imageData[col][row]), 1, 1, outputImage);

            // Sanity check on write.
            if(wCount != 1){
                freePgm(inputImage);
                printf("ERROR: Output Failed (%s)", outputFileName);
                fclose(outputImage);
                exit(EXIT_OUTPUT_FAILED);
            }
        }
    }

    fclose(outputImage);
}
