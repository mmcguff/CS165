########################################################################
# Program:
#    Assignment 34, Polymorphism
#    Brother Sloan, CS165
# Author:
#    Larry Dewey
# Summary:
#    This assignment is to demonstrate polymorphism.  The goal is
#    to create an 8x8 array of pieces representing a chess board
#    and to display them on the screen.
#
#    Estimated:  0.0 hrs
#    Actual:     0.0 hrs
#      Please describe briefly what was the most difficult part
########################################################################
### Assignment 34
### the main rule
a.out: piece.o assign34.o
	c++ -o a.out piece.o assign34.o
	tar -cf assign34.tar *.h *.cpp makefile

### for the object files
piece.o: piece.cpp piece.h
	c++ -c -g piece.cpp
	
assign34.o: assign34.cpp
	c++ -c -g assign34.cpp

### cleanup
clean:
	rm a.out *.o *.tar
