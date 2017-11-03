###############################################################
# Program:
#     Week 11, Sorts
#     Brother JonesL, CS235
# Author:
#     Nathan Bench, Jed Bilman, Jeremy Chandler, Justin Chandler
# Summary:
#     Implementation of a plethorae of sorting algorithms
# Time:
#     Nathan: 12 hrs
#     Jed: 4 hrs
#     Jeremy: 10 hrs
#     Justin: 11 hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week11.o
	g++ -o a.out week11.o -g
	tar -cf week11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week11.o     : the driver program
##############################################################
week11.o: bnode.h bst.h stack.h week11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h
	g++ -c week11.cpp -g

