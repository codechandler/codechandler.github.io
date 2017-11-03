/***********************************************************************
 * Header:
 *    GO FISH
 * Summary:
 *    
 * Author
 *    Nathan Bench, Jed Billman, Justin Chandler, Jeremy Chandler (Leonel Messi)
 ************************************************************************/

#ifndef GO_FISH_H
#define GO_FISH_H

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "set.h"        // for SET
#include <fstream>
#include "card.h"
 /*****************************************
 * GO FISH
 *****************************************/

void goFish();
void readFile();
bool verifyMatch();
void display();



#endif // GO_FISH_H