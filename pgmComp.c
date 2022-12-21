#include <stdio.h>

#include "rwPgm.h"

// Small functions for outputting different and freeing the pgmData.
int different();

int main(int argc, char **argv){
	// Check command line arguments.
	if(argc == 1){
		printf("Usage: ./pgmComp inputImage.pgm inputImage.pgm");
		return 0;
	} 

	checkArgCount(argc);

	// Make two empty pgmData structures to hold the data
	pgmData *image1 = pgmInit();
	pgmData *image2 = pgmInit();

	// Populate the structures and check for errors
	readPgm(image1, argv[1]);
	readPgm(image2, argv[2]);

	// Check for errors
	checkPgmIn(image1, argv[1]);
	checkPgmIn(image2, argv[2]);


	// Check That each data field is the same for both images.

	// MAGIC NUMBER, WIDTH AND HEIGHT, MAX GRAY
	if(*(image1->magic_Number) != *(image2->magic_Number)){
		return different(image1, image2);
	} else if (image1->width != image2->width || image1->height != image2->height){
		return different(image1, image2);
	} else if (image1->maxGray != image2->maxGray){
		return different(image1, image2);
	}

	// IMAGE DATA

	// Compare each bit of data.
	for(int col = 0; col < image1->height; col ++){
		for(int row = 0; row < image1->width; row ++){
			// Check if they're different
			if(image1->imageData[col][row] != image2->imageData[col][row]){
				return different(image1, image2);
			}
		}
	}

	// Free the images.
	freePgm(image1);
	freePgm(image2);

	printf("IDENTICAL");
	return EXIT_NO_ERRORS;
}

int different(pgmData *image1, pgmData *image2){
	freePgm(image1);
	freePgm(image2);
	printf("DIFFERENT");
	return EXIT_NO_ERRORS;
}

