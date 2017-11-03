/***********************************************************************
* Header:
*    WORD COUNT
* Summary:
*    This will contain just the prototype for the wordCount()
*    function
* Author
*    <your names here>
************************************************************************/

#ifndef WORD_COUNT_H
#define WORD_COUNT_H
#include <fstream>
#include <iostream>
#include "map.h"
#include <string>
#include "pair.h"
using namespace std;
/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount();
string promptUser();
void readFile(Map <string, double> & counts,
        string fileName, 
	const string & search);
void display(string input, Map<string, double>& counts);



#endif // WORD_COUNT_H

