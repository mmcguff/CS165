### Assignment 28, The Gauntlet III
### the main rule
a.out: dateTest.o date.o operators.o
	c++ -o a.out dateTest.o date.o operators.o
	tar -cf assign28.tar *.h *.cpp makefile

### for the object files
dateTest.o: dateTest.cpp date.h
	c++ -c -g dateTest.cpp

date.o: date.cpp date.h
	c++ -c -g date.cpp
	
operators.o: operators.cpp date.h
	c++ -c -g operators.cpp

### cleanup
clean:
	rm a.out *.o *.tar
