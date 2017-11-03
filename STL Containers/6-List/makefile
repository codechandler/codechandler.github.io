###############################################################
# Program:
#     Week 07, LIST
#     Brother JonesL, CS235
# Author:
#     Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
# Summary:
#     List with fibonacci number for the implimentation.
# Time:
#     Jeremy: 6 hrs.
#     Jed: 4-5 hrs.
#     Nathan: 12 hrs.
#     Justin: 4 hrs.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: list.h week07.o fibonacci.o
	g++ -o a.out week07.o fibonacci.o
	tar -cf week07.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week07.o       : the driver program
#      fibonacci.o    : the logic for the fibonacci-generating function
#      <anything else?>
##############################################################
week07.o: list.h week07.cpp
	g++ -c week07.cpp

fibonacci.o: fibonacci.h fibonacci.cpp list.h
	g++ -c fibonacci.cpp

