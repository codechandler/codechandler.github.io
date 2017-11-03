/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Nathan Bench, Jed Bilman, Jeremy Chandler, Justin Chandler
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "huffman.h"       // for HUFFMAN() prototype
#include "bnode.h"
#include <vector>        // for vector
#include "list.h"	   // for List
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const std::string & fileName)
{
	// initialize variables
	vector < Huffman* > input;     // read the file into input
	vector<string> output;

	List <Huffman*> hList;                    // keep a list of Huffman objects to combine them (pointers?)
	Huffman * hHead;			     // the head of the Huffman tree
	vector <string> variables;


	string inputToken;
	double inputFrequency;
	Pair <float, string> huffmanSet;
	// Read the pairs into the vector

	ifstream fin(fileName.c_str());
	if (fin.fail())
		cerr << "Unable to open file\n";
	else
		while (fin >> inputToken)
		{
			// add name to pair
			huffmanSet.second = inputToken;
			// add value to pair
			fin >> inputFrequency;
			huffmanSet.first = inputFrequency;
			// add pair to list
			Huffman * pNew = new Huffman(inputToken, inputFrequency);
			input.push_back(pNew);
			variables.push_back(inputToken);
		}
	fin.close();
	// Read the pairs into hList OR create hList by searching for smallest in the vector
	// WHILE (!hList.size() > 1)
	while (input.size() > 1)
	{
		// find 2 smallest frequencies
		int smallest = 0;
		int secondSmallest = 0;
		for (int i = 1; i < input.size(); i++)
		{
			// preserve order if equal
			if (input[i]->getWeight() == input[smallest]->getWeight())
				if (smallest < i)
				{
					secondSmallest = i;
				}
				else
				{
					secondSmallest = smallest;
					smallest = i;
				}
			//if less than smallest
			else if (input[i]->getWeight() <= input[smallest]->getWeight())
			{
				//smallest becomes second smallest
				secondSmallest = smallest;
				//new smallest
				smallest = i;
			}
			else if (input[i]->getWeight() <= input[secondSmallest]->getWeight())
				secondSmallest = i;
			else if (smallest == secondSmallest)
				secondSmallest = i;
		}

		// combine into hTree hHead and add that to the list
		input[smallest]->add(input[secondSmallest]);
		input[secondSmallest] = input[input.size() - 1];
		//change last to this position and delete the end
		input.pop_back();
	}
   // remove the 2 hTrees that were combined from the list (Or maybe the 1 tree, since add is void)
   // get Huffman codes from tree
	bool duplicate = false;
	input[0]->find(" = ", output); //find the frequency for the token
	sort(output.begin(), output.end());
	sort(input.begin(), input.end());
    for (vector<string>::iterator variablesIt = variables.begin(); variablesIt != variables.end(); ++variablesIt)
	{
		for (vector<string>::iterator it = output.begin(); it != output.end(); ++it)
		{
			if ((*variablesIt)[0] == (*it)[0])
			{
				cout << (*it) << endl;
				(*variablesIt) = " ";
			}
		}
	}
	// Cout vector

   // FOR 0 to vector.size()
	// call extract
	// output Huffman values in the order from the file
	
   return;
}

void Huffman::find(string code, vector<string> &output)
{
	findRecursive(tree, code, output);
}

void Huffman::findRecursive(BinaryNode <Pair <string, float> > * tree, string code, vector<string> &output)
{
	if (tree == NULL)
		return;
	if (tree->pLeft == NULL && tree->pRight == NULL)
	{
		output.push_back(tree->data.first + code);
	}
	else
	{
		findRecursive(tree->pLeft, code + "0", output);
	}
	findRecursive(tree->pRight, code + "1", output);
}
#endif //HUFFMAN_H
