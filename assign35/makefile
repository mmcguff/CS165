########################################################################
# Program:
#    Assignment 35, Pure virtual functions
#    Brother Sloan, CS165
# Author:
#    Larry Dewey
# Summary:
#    We are to take Assignment 3.5 one step further and make the
#    base class an abstract class. This means that we are to make
#    a new derrived class called Space and Piece will be abstract.
#
#    Estimated:  0.0 hrs
#    Actual:     0.0 hrs
#      Please describe briefly what was the most difficult part
########################################################################/
### Assignment 35
### the main rule
a.out: piece.o assign35.o
        c++ -o a.out $^
	tar -cf assign35.tar *.h *.cpp makefile

### for the object files
piece.o: piece.cpp piece.h
	c++ -c -g piece.cpp
	
assign35.o: assign35.cpp
	c++ -c -g assign35.cpp

### cleanup
clean:
	rm a.out *.o *.tar
