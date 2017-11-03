###############################################################
# Program:
#     Week 05, SET
#     Brother Jonesl, CS235
# Author:
#     Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
# Summary:
#     Implementation of STD Set and Go Fish game
# Time:
#     Nate: 16
#     Jed: 5
#     Jeremy: 8
#     Justin: 13
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week05.o goFish.o card.o
	g++ -o a.out week05.o goFish.o card.o
	tar -cf week05.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week05.o       : the driver program
#      goFish.o       : the logic for the goFish game
#      card.o         : a single playing card
##############################################################
week05.o: set.h goFish.h week05.cpp
	g++ -c week05.cpp

goFish.o: set.h goFish.h goFish.cpp card.h
	g++ -c goFish.cpp

card.o: card.h card.cpp
	g++ -c card.cpp 