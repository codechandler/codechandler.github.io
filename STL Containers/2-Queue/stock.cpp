/***********************************************************************
* Implementation:
*    STOCK
* Summary:
*    This will contain the implementation for stocksBuySell() as well
*    as any other function or class implementation you need
* Author
*    <your names here>
**********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <sstream>
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "dollars.h"   // used to handle currency
#include "queue.h"     // for QUEUE
using namespace std;

Queue <int> qShares;
Queue <Dollars> qDollars;
Queue <string> qSellHistory;

void buyStock(int sharesToBeBought, Dollars buyPrice)
{
	qShares.push(sharesToBeBought);
	qDollars.push(buyPrice);
}

Dollars sellStock(int sharesToBeSold, Dollars sellPrice, Dollars &proceeds)
{
	int soldShares = 0;
	string s1 = "Sold ";
	string s2 = " shares at ";
	string s3 = " for a profit of ";
	string s4 = " for a loss of ";
	// While we haven't sold enough shares
	while (soldShares < sharesToBeSold)
	{
		// while adding one transaction still won't be enough keep 
		// adding transactions
		while ((soldShares + qShares.front()) <= sharesToBeSold)
		{
			stringstream ss;
			string s5;
			// add shares of one transaction
			soldShares += qShares.front();
			ss << s1 << qShares.front() << s2 << sellPrice << s3 << ((sellPrice - qDollars.front()) * qShares.front());
			s5 = ss.str();
			qSellHistory.push(s5);
			// figure out the proceeds 
			proceeds += (sellPrice - qDollars.front()) * qShares.front();
			sharesToBeSold -= qShares.front();
			// remove that transaction
			qShares.pop();
			qDollars.pop();
			if (qShares.empty())
				return proceeds;
			// update the count of the shares we still need to sell
		}
		if (sharesToBeSold == 0)
		{
			return proceeds;
		}
		stringstream ss;
		string s5;
		// adding one is more than enough so add part of a transaction
		ss << s1 << sharesToBeSold << s2 << sellPrice << s3 << ((sellPrice - qDollars.front()) * sharesToBeSold);
		s5 = ss.str();
		qSellHistory.push(s5);
		// get rid of some of the shares in the front transaction of the queue
		qShares.front() -= (sharesToBeSold);
		soldShares += sharesToBeSold;
		// proceeds = buying price * the rest of the shares we need to sell
		proceeds += (sellPrice - qDollars.front()) * (sharesToBeSold);
	}
		// We sold all the shares we needed to sell, update the record
		sharesToBeSold = 0;
		return proceeds;
}

void display(Dollars proceeds)
{

	Queue <Dollars> qTempDollars(qDollars);
	Queue <int> qTempShares(qShares);
	Queue <string> qTempSellHistory(qSellHistory);
	if (!qShares.empty())
		cout << "Currently held:\n";
	while (!qTempShares.empty())
	{
		cout << "\tBought " << qTempShares.front() << " shares at " << qTempDollars.front() << endl;
		qTempShares.pop();
		qTempDollars.pop();
	}
	if (!qSellHistory.empty())
		cout << "Sell History:\n";
	// while the queue is not empty
	while(!qTempSellHistory.empty())
	{
		cout << "\t" << qTempSellHistory.front() << endl;
		qTempSellHistory.pop();
	}
	cout << "Proceeds: " << proceeds << endl;
}

/************************************************
* STOCKS BUY SELL
* The interactive function allowing the user to
* buy and sell stocks
***********************************************/
void stocksBuySell()
{
	// instructions
	cout << "This program will allow you to buy and sell stocks. "
		<< "The actions are:\n";
	cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
	cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
	cout << "  display         - Display your current stock portfolio\n";
	cout << "  quit            - Display a final report and quit the program\n";

	Dollars proceeds;
	string userInput;
	int shares = 0;
	string command; // ex. buy, sell, display
	Dollars price;
	bool start = false;
	while (userInput != "quit")
	{
		if (start == true)
			cout << "> ";
		start = true;
		getline(cin, userInput);
		istringstream ss(userInput);
		ss >> command;
		if (command == "display")
		{
			display(proceeds);
		}
		if (command == "buy")
		{
			ss >> shares >> price;
			buyStock(shares, price);
		}
		else if (command == "sell")
		{
			ss >> shares >> price;
			proceeds = sellStock(shares, price, proceeds);
		}
	}
}

