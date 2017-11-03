###############################################################
# Program:
#     Week 10, Map
#     Brother JonesL, CS235
# Author:
#     Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
# Summary:
#     Nathan: 12 hrs
#     Jed: 2 hrs
#     Jeremy: 8 hrs
#     Justin: 8 hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week10.o wordCount.o
	g++ -o a.out week10.o wordCount.o 
	tar -cf week10.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week10.o       : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
week10.o: bnode.h bst.h pair.h map.h week10.cpp
	g++ -c week10.cpp

wordCount.o: map.h wordCount.h wordCount.cpp bnode.h bst.h
	g++ -c wordCount.cpp 
