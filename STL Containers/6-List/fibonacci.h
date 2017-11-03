/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
 ************************************************************************/

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "list.h"

// the interactive fibonacci program
void fibonacci();

/***********************************************
* Whole Number
* A class that holds a List of numbers of 3 digits
***********************************************/
class WholeNumber
{
   public:
      // constructors
      WholeNumber() {}
      WholeNumber(const WholeNumber & rhs);
      WholeNumber(const int & value) throw (const char *);
      
      // operators
      WholeNumber & operator = (const WholeNumber & rhs);
      WholeNumber & operator += (const WholeNumber & rhs);
	  WholeNumber & operator -= (const WholeNumber & rhs);
	  friend WholeNumber operator - (const WholeNumber & lhs, const WholeNumber & rhs);
      
      friend std::ostream & operator << (std::ostream & out, const WholeNumber & rhs);
      
   private:
      List <int> data;
};

#endif // FIBONACCI_H

