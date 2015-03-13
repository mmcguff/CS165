###############################################################
# Program:
#     Project ##, ????
#     Brother Helfrich, CS165
# Author:
#     author one
#     author two
# Summary:
#     Enter a brief description of your program here! 
#
#     Estimated:  0.0 hrs
#     Actual:     0.0 hrs
#       Please describe briefly what was the most difficult part
###############################################################

###############################################################
# Programs:
#    pong:         The playable game
#    uiTest:       Simple driver program for the drawing interface
###############################################################
skeet : skeet.o uiInteract.o uiDraw.o point.o velocity.o bird.o bullet.o rifle.o
	g++ -o skeet skeet.o uiInteract.o uiDraw.o point.o velocity.o bird.o rifle.o bullet.o -lglut -lGL -lGLU
	tar -cf skeet.tar *.cpp *.h makefile
	skeet
###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    uiTest.o      Driver program for uiDraw and uiTest
#    pong.o        Only the greatest game ever! (and it was for 20 years)  
###############################################################
uiInteract.o : uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

bullet.o: bullet.cpp bullet.h
	g++ -c bullet.cpp

bird.o: bird.cpp bird.h
	g++ -c bird.cpp

rifle.o: rifle.cpp rifle.h
	g++ -c rifle.cpp

velocity.o : velocity.h velocity.cpp point.h
	g++ -c velocity.cpp

uiDraw.o : uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

point.o : point.cpp point.h
	g++ -c point.cpp

# all classes used in skeet 
skeet.o : skeet.cpp point.h uiDraw.h velocity.h rifle.h bird.h bird.h bullet.h uiInteract.h
	g++ -c skeet.cpp


###############################################################
# General rules
###############################################################
clean :
	rm -f skeet *.o *.tar *.cpp~ makefile~ *.compile *.h~


