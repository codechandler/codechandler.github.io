###############################################################
# Program:
#     Week 06, NODE
#     Brother Jonesl, CS235
# Author:
#     Justin Chandler, Jeremy Chandler, Nathan Bench, Jed Billman
# Summary:
#     Implementation of the Node class and sort insertion
# Time:
#     Justin: 10 hours
#     Jed: 5 hours
#     Jeremy: 8 hours
#     Nathan: 16 hours
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h week06.o 
	g++ -o a.out week06.o  -g
	tar -cf week06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week06.o      : the driver program
#      <anything else?>
##############################################################
week06.o: node.h week06.cpp sortInsertion.h
	g++ -c week06.cpp -g
