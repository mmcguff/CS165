###############################################################
# Program:
#     Project 03, Object-Oriented Chess
#     Brother Sloan, CS165
# Author:
#     Larry Dewey
# Summary:
#     Estimated:  0 hrs
#     Actual:     0 hrs
###############################################################
FLAGS=-g
###############################################################
# Programs:
#    chess: The actual game
###############################################################
chess : chess.o move.o position.o board.o piece.o
	g++ $(FLAGS) -o chess $^
	tar -cf chess.tar *.cpp *.h makefile

moveTest : moveTest.o move.o position.o
	g++ $(FLAGS) -o moveTest $^

boardTest : boardTest.o board.o piece.o position.o
	g++ $(FLAGS) -o boardTest $^

###############################################################
# Individual files
###############################################################
chess.o : chess.cpp board.h piece.h chess.h
	g++ $(FLAGS) -c chess.cpp

moveTest.o : moveTest.o move.h position.h
	g++ $(FLAGS) -c moveTest.cpp

boardTest.o : boardTest.cpp board.cpp board.h piece.h
	g++ $(FLAGS) -c boardTest.cpp

move.o : move.cpp move.h position.h
	g++ $(FLAGS) -c move.cpp 

board.o : board.cpp board.h piece.h
	g++ $(FLAGS) -c board.cpp

position.o : position.cpp position.h
	g++ $(FLAGS) -c position.cpp

piece.o : piece.cpp piece.h
	g++ $(FLAGS) -c piece.cpp

###############################################################
# Other options...
###############################################################
clean :
	rm moveTest chess boardTest *.o *.tar *~ *.gch *#

all :  moveTest chess

