## Utilities for .pgm files.

This was the coursework for comp1921 - programming project. We had to code a series of utilities for .pgm files and create a makefile and a test script.
PgmEcho will just create an exact replica of the input image. pgmCompare will logically compare two .pgm files. Pgmb2a and a2b converts .pgm files between ASCII to Binary. PgmReduce will reduce the .pgm file by the given reduction factor.

## Running:

### pgmEcho:
- make pgmEcho
- ./pgmEcho <input_image.pgm> <output_image.pgm>


### pgmComp:
- make pgmComp
- ./pgmComp <image_1.pgm> <image_2.pgm>


### pgma2b:
- make pgma2b
- ./pgma2b <ascii_image.pgm> <binary_image.pgm>


### pgmb2a:
- make pgmb2a
- ./pgma2b <binary_image.pgm> <ascii_image.pgm>
	

### pgmReduce:
- make pgmReduce
- ./pgmReduce <input_image.pgm> <reduction factor> <output_image.pgm>

NOTE: The reduction factor must be a positive integer > 0

### To make all utilities:
- make all
	
### To clean:
- make clean
