/***********************************************************************
 * Implementation:
 *    GO FISH
 * Summary:
 *    
 * Author
 *    Nathan Bench, Jed Billman, Jeremy Chandler (Leonel Messi), Justin Chandler
 **********************************************************************/


#include "goFish.h" 
#include <string>
using namespace std;

int numMatches;
int roundNumber;
string cardGuess;
Card newCard;
Set<Card>deck;

// Verifies if the card drawn is a match with a card in the hand
bool verifyMatch()
{
   SetIterator <Card> it = deck.find(newCard);
   if (it != deck.end())
	{
	   deck.erase(it);
		return true;
	}
        else
           return false;
}

// displays all output
void display()
{
	// Play game for 5 rounds
	for (roundNumber; roundNumber <= 5; roundNumber++)
	{
	cout << "round " << roundNumber << ": "; 
	cin >> cardGuess;
    const char* tmp = cardGuess.c_str();
	newCard = tmp;
		if (verifyMatch() == true)
		{
			cout << "\tYou got a match!\n";
			numMatches++;
		}
		else
			cout << "\tGo Fish!\n";
	}
		cout << "You have " << numMatches << " matches!\n";
		cout << "The remaining cards: ";
		for (SetIterator <Card> it = deck.begin(); it != deck.end();)
		{
			cout << *it;
			if (++it != deck.end())
				cout << ", "; // TODO fix formatting.
		}
			cout << endl;
}

void readFile()
{
	ifstream fin("/home/cs235/week05/hand.txt");
	if (fin.fail())
	{
		cerr << "Failed to read file\n";
		return;
	}

		while (fin >> newCard)
		{
			deck.insert(newCard);
		}
	fin.close();
}

// Main function for the game
void goFish()           // TODO change to goFish()
{
	numMatches = 0;
	roundNumber = 1;
	cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";
	readFile();
	display();
}