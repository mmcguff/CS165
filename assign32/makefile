### Assignment 32
### the main rule
assign32: assign32.o
	c++ -o assign32 assign32.o
	tar -cf assign32.tar *.h *.cpp makefile

### for the object files
assign32.o: assign32.cpp assign32.h
	c++ -c -g assign32.cpp

### cleanup
clean:
	rm assign32 *.o *.tar 
