###############################################################
# Program:
#     Week 09, Binary Search Tree
#     Brother JonesL, CS235
# Author:
#     Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
# Summary:
#     Implementation of the Binary Search Tree with a Binary Sort
# Time:
#     Nathan Bench: 9 hours
#     Jed Billman: 1 hour
#     Jeremy Chandler: 3 hours
#     Justin Chandler: 3 hours
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week09.o
	g++ -o a.out week09.o -g
	tar -cf week09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week09.o     : the driver program
##############################################################
week09.o: bnode.h bst.h stack.h week09.cpp sortBinary.h
	g++ -c week09.cpp -g

