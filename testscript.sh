#!/bin/sh
# TESTS FOR PGMECHO.

function tEchoOut(){
	echo Testing files are same...
}

program=pgmEcho

echo Beginning tests for $program
echo

# pgmEcho compiles.
echo $program compiles correctly.
make $program
echo

# Testing valid binary and ascii files.
echo Testing with valid pgm files.

# Testing valid file.
echo Echoes correctly for valid ascii pgm file.
./$program images/ascii/slice0a.pgm images/ascii/output.pgm
echo
echo

# Testing files are logically the same.
tEchoOut
cmp images/ascii/slice0a.pgm images/ascii/output.pgm
echo

# Testing bigger file.
echo Echoes correctly for larger ascii pgm file.
./$program images/ascii/venus.pgm images/ascii/output.pgm
echo
echo

# Testing files are logically the same.
tEchoOut
cmp images/ascii/venus.pgm images/ascii/output.pgm
echo

# Remove temporary files.
echo Removing output files.
rm images/ascii/output.pgm
echo

# Testing binary pgm file.
echo Echoes correctly for binary pgm file.
./$program images/binary/slice0a.pgm images/binary/output.pgm
echo
echo

# Testing files are logically the same.
tEchoOut
cmp images/binary/slice0a.pgm images/binary/output.pgm
echo

# Testing larger binary pgm file.
echo Echoes correctly for larger binary pgm file.
./$program images/binary/mona.pgm images/binary/output.pgm
echo
echo

# Testing files are logically the same
tEchoOut
cmp images/binary/baboon.pgm images/binary/output.pgm
echo

# Remove temporary files.
echo
echo Removing temporary files...
rm images/binary/output.pgm
# Run tests with bad pgm files.
echo
echo Running tests for $program error catching...
echo
echo

echo Testing No arguments...
./$program
echo
echo

echo Testing Bad Argument Count...
./$program images/ascii/slice0a.pgm images/ascii/slice0a.pgm images/ascii/slice0a.pgm
echo
echo

echo Testing Bad File name...
./$program images/ascii/asdf.pgm images/ascii/output.pgm
echo
echo

echo Testing Bad Magic Number...
./$program images/badAscii/badMagicNum.pgm images/badAscii/output.pgm
echo
echo

echo Testing Bad Comment Line...
./$program images/badAscii/largeComment.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (SMALL)..."
./$program images/badAscii/badDimensionsSmall.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (BIG)..."
./$program images/badAscii/badDimensionsBig.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Max Gray (BIG)..."
./$program images/badAscii/badMaxGrayBig.pgm images/badAscii/output.pgment images correctly for valid ascii pgm file.
IDENTICAL

echo
echo

echo "Testing Bad Max Gray (SMALL)..."
./$program images/badAscii/badMaxGraySmall.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (negative data)..."
./$program images/badAscii/badDataNeg.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (Data too big)..."
./$program images/badAscii/badDataLarge.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (No Data)..."
./$program images/badAscii/noData.pgm images/badAscii/output.pgm
echo
echo

echo
echo Finished Testing pgmEcho.
echo
echo Deleting executable...
rm pgmEcho *.o
echo
echo











program=pgmComp

# PGM COMP TESTS
echo Beginning tests for $program
echo

# pgmEcho compiles.
echo $program compiles correctly.
make $program
echo

# Testing valid binary and ascii files.
echo Testing with valid pgm files.

# Testing valid file.
echo Compares identical images correctly for valid ascii pgm file.
./$program images/ascii/slice0a.pgm images/ascii/slice0a.pgm
echo
echo

echo Compares different images correctly for valid ascii pgm file.
./$program images/ascii/slice0a.pgm images/ascii/f1.pgm
echo
echo

# Testing bigger file.
echo Compares identical images correctly for larger ascii pgm file.
./$program images/ascii/venus.pgm images/ascii/venus.pgm
echo
echo

# Testing binary pgm file.
echo Compares identical images correctly for binary pgm file.
./$program images/binary/slice0a.pgm images/binary/slice0a.pgm
echo
echo

echo Compares different images correctly for binary pgm file.
./$program images/binary/slice0a.pgm images/binary/baboon.pgm
echo
echo

# Testing larger binary pgm file.
echo Compares identical images correctly for larger binary pgm file.
./$program images/binary/mona.pgm images/binary/mona.pgm
echo
echo

echo Compares different images correctly for larger binary pgm file.
./$program images/binary/mona.pgm images/binary/baboon.pgm
echo
echo

# Remove temporary files.
echo
echo Removing temporary files...
rm images/binary/output.pgm

# Run tests with bad pgm files.
echo
echo Running tests for $program error catching...
echo
echo

echo Testing No arguments...
./$program
echo
echo

echo Testing Bad Argument Count...
./$program images/ascii/slice0a.pgm images/ascii/slice0a.pgm images/ascii/slice0a.pgm
echo
echo

echo Testing Bad File name...
./$program images/ascii/asdf.pgm images/ascii/output.pgm
echo
echo

echo Testing Bad Magic Number...
./$program images/badAscii/badMagicNum.pgm images/badAscii/output.pgm
echo
echo

echo Testing Bad Comment Line...
./$program images/badAscii/largeComment.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (SMALL)..."
./$program images/badAscii/badDimensionsSmall.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (BIG)..."
./$program images/badAscii/badDimensionsBig.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Max Gray (BIG)..."
./$program images/badAscii/badMaxGrayBig.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Max Gray (SMALL)..."
./$program images/badAscii/badMaxGraySmall.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (negative data)..."
./$program images/badAscii/badDataNeg.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (Data too big)..."
./$program images/badAscii/badDataLarge.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (No Data)..."
./$program images/badAscii/noData.pgm images/badAscii/output.pgm
echo
echo

echo
echo Finished Testing $program
echo








program=pgma2b

# PGM COMP TESTS
echo Beginning tests for $program
echo

# pgmEcho compiles.
echo $program compiles correctly.
make $program
echo

# Testing valid binary and ascii files.
echo Testing with valid pgm files.

# Testing valid file.
echo Converts images correctly for valid ascii pgm file.
./$program images/ascii/slice0a.pgm images/output.pgm
echo
echo

# Testing bigger file.
echo Converts correctly for larger ascii pgm file.
./$program images/ascii/venus.pgm images/output.pgm
echo
echo

# Run tests with bad pgm files.
echo
echo Running tests for $program error catching...
echo
echo

echo Testing No arguments...
./$program
echo
echo

echo Testing Bad Argument Count...
./$program images/ascii/slice0a.pgm images/ascii/slice0a.pgm images/ascii/slice0a.pgm
echo
echo

echo Testing Bad File name...
./$program images/ascii/asdf.pgm images/ascii/output.pgm
echo
echo

echo Testing Bad Magic Number...
./$program images/badAscii/badMagicNum.pgm images/badAscii/output.pgm
echo
echo

echo Testing Bad Comment Line...
./$program images/badAscii/largeComment.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (SMALL)..."
./$program images/badAscii/badDimensionsSmall.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (BIG)..."
./$program images/badAscii/badDimensionsBig.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Max Gray (BIG)..."
./$program images/badAscii/badMaxGrayBig.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Max Gray (SMALL)..."
./$program images/badAscii/badMaxGraySmall.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (negative data)..."
./$program images/badAscii/badDataNeg.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (Data too big)..."
./$program images/badAscii/badDataLarge.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (No Data)..."
./$program images/badAscii/noData.pgm images/badAscii/output.pgm
echo
echo





program=pgmb2a

# PGM COMP TESTS
echo Beginning tests for $program
echo

# pgmEcho compiles.
echo $program compiles correctly.
make $program
echo

# Testing valid binary and ascii files.
echo Testing with valid pgm files.

# Testing valid file.
echo Converts images correctly for valid binary pgm file.
./$program images/binary/slice0a.pgm images/outputa.pgm
echo
echo

# Testing bigger file.
echo Converts correctly for larger binary pgm file.
./$program images/binary/baboon.pgm images/outputa.pgm
echo
echo

# Testing files are converted identically
echo pgmb2a and pgma2b convert identical images.
./pgmb2a images/output.pgm images/ascii/venus2.pgm
echo
./pgmComp images/ascii/venus.pgm images/ascii/venus2.pgm
echo

./pgma2b images/outputa.pgm images/binary/baboon2.pgm
echo
./pgmComp images/binary/baboon.pgm images/binary/baboon2.pgm
echo

echo remove the duplicate files.
rm images/ascii/venus2.pgm images/binary/baboon2.pgm images/output.pgm images/outputa.pgm

# Run tests with bad pgm files.
echo
echo Running tests for $program error catching...
echo
echo

echo Testing No arguments...
./$program
echo
echo

echo Testing Bad Argument Count...
./$program images/ascii/slice0a.pgm images/ascii/slice0a.pgm images/ascii/slice0a.pgm
echo
echo

echo Testing Bad File name...
./$program images/ascii/asdf.pgm images/ascii/output.pgm
echo
echo

echo Testing Bad Magic Number...
./$program images/badAscii/badMagicNum.pgm images/badAscii/output.pgm
echo
echo

echo Testing Bad Comment Line...
./$program images/badAscii/largeComment.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (SMALL)..."
./$program images/badAscii/badDimensionsSmall.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (BIG)..."
./$program images/badAscii/badDimensionsBig.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Max Gray (BIG)..."
./$program images/badAscii/badMaxGrayBig.pgm images/badAscii/output.pgm
echoasdf
echoasdf

echoasdf
./$program images/badAscii/badMaxGraySmall.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (negative data)..."
./$program images/badAscii/badDataNeg.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (Data too big)..."
./$program images/badAscii/badDataLarge.pgm images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (No Data)..."
./$program images/badAscii/noData.pgm images/badAscii/output.pgm
echo
echo

echo
echo Finished Testing $program
echo
echo Deleting executable...
rm pgmComp pgma2b pgmb2a *.o
echo
echo













program=pgmReduce

echo Beginning tests for $program
echo

# pgmEcho compiles.
echo $program compiles correctly.
make $program
echo

# Testing valid binary and ascii files.
echo Testing with valid pgm files.

# Testing valid file.
echo Reduces correctly for valid ascii pgm file.
./$program images/ascii/slice0a.pgm 2 images/output.pgm
echo
echo

# Testing bigger file.
echo Reduces correctly for larger ascii pgm file.
./$program images/ascii/venus.pgm 7 images/output.pgm
echo
echo

# Testing bigger file.
echo Reduces correctly for larger ascii pgm file with large reduce factor.
./$program images/ascii/venus.pgm 77 images/output.pgm
echo
echo

# Remove temporary files.
echo Removing output files.
rm images/output.pgm
echo

# Testing binary pgm file.
echo Reduces correctly for binary pgm file.
./$program images/binary/slice0a.pgm 2 images/output.pgm
echo
echo

# Testing larger binary pgm file.
echo Reduces correctly for larger binary pgm file.
./$program images/binary/mona.pgm 7 images/output.pgm
echo
echo


# Testing larger binary pgm file.
echo Reduces correctly for larger binary pgm file with large reduce factor.
./$program images/binary/mona.pgm 89 images/output.pgm
echo
echo

# Remove temporary files.
echo
echo Removing temporary files...
rm images/output.pgm
# Run tests with bad pgm files.
echo
echo Running tests for $program error catching...
echo
echo

echo Testing No arguments...
./$program
echo
echo

echo Testing Bad Argument Count...
./$program images/ascii/slice0a.pgm images/ascii/slice0a.pgm
echo
echo

echo Testing Bad File name...
./$program images/ascii/asdf.pgm 7 images/ascii/output.pgm
echo
echo

echo Testing Bad Magic Number...
./$program images/badAscii/badMagicNum.pgm 2 images/badAscii/output.pgm
echo
echo

echo Testing Bad Comment Line...
./$program images/badAscii/largeComment.pgm 88 images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (SMALL)..."
./$program images/badAscii/badDimensionsSmall.pgm 44 images/badAscii/output.pgm
echo
echo

echo "Testing Bad Dimensions (BIG)..."
./$program images/badAscii/badDimensionsBig.pgm 27 images/badAscii/output.pgm
echo
echo

echo "Testing Bad Max Gray (BIG)..."
./$program images/badAscii/badMaxGrayBig.pgm  77 images/badAscii/output.pgm
echo
echo

echo "Testing Bad Max Gray (SMALL)..."
./$program images/badAscii/badMaxGraySmall.pgm 12 images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (negative data)..."
./$program images/badAscii/badDataNeg.pgm 1 images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (Data too big)..."
./$program images/badAscii/badDataLarge.pgm 12 images/badAscii/output.pgm
echo
echo

echo "Testing Bad Image Data (No Data)..."
./$program images/badAscii/noData.pgm 44 images/badAscii/output.pgm
echo
echo

echo Testing negative reduction factor
./$program images/ascii/f1.pgm -44 images/output.pgm
echo
echo

echo Testing non-numeric reduction factor
./$program images/ascii/f1.pgm asdf images/output.pgm
echo
echo

echo Testing zero reduction factor
./$program images/ascii/f1.pgm 0 images/output.pgm
echo
echo

echo Testing massive reduction factor.
./$program images/ascii/f1.pgm 9999999999999999999999999999 images/output.pgm
echo
echo

echo Testing non-integer reduction factor.
./$program images/ascii/f1.pgm 0.5 images/output.pgm
echo
echo

echo
echo Finished Testing $program.
echo
echo Deleting executable...
rm $program *.o
echo
echo

echo TESTS FINISHED!



