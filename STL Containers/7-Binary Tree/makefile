###############################################################
# Program:
#     Week 08, Binary Tree
#     Brother Jonesl, CS235
# Author:
#     Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
# Summary:
#     Implementation of the Binary Tree to problem solve Huffman exercise
# Time:
#     Coding Time: Jeremy Chandler 10 hrs.
#                  Justin Chandler 12 hrs.
#                  Nathan Bench 14 hrs.
#                  Jed Billman 8 hrs.
#
#     Discussion Time:  Jeremy Chandler 3 hrs.
#                       Justin Chandler 3 hrs.
#                       Nathan Bench 5 hrs.
#                       Jed Billman 3 hrs.
#     Most difficult part: Extraction of Huffman Codes from
#                          the tree. 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week08.o huffman.o 
	g++ -o a.out week08.o huffman.o -g
	tar -cf week08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week08.o     : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
week08.o: bnode.h huffman.h week08.cpp
	g++ -c week08.cpp -g

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -c huffman.cpp -g

