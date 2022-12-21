
#ifndef validate
#define validate

#include <stdio.h>
#include "rwPgm.h"


// Functions to check pgm values.
void checkPgmIn(pgmData *pgmImage, char *fn);

void checkArgCount(int argc);

void checkFile(pgmData *pgmImage, char *fileName);
 
void checkMagicNum(pgmData *pgmImage, char *fn);
 
void checkComment(pgmData *pgmImage, char *fn);
 
void checkDimensions(pgmData *pgmImage, char *fn);
 
void checkMaxgray(pgmData *pgmImage, char *fn);
 
void checkData(pgmData *pgmImage, int grayVal, char *fn, int version);

void mallocFail();

void checkOutput(pgmData *inputImage, FILE *outputFile, char *outputFileName);

void miscError(char *msg);
#endif
