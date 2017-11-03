/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    This will contain the definition and implementation of the Node class
 * Author
 *    Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
 ************************************************************************/
 
/***********************************************
 * TODO
 * WRITE function definitions
 * REPLACE comment descriptions
 **********************************************/
 
#ifndef NODE_H
#define NODE_H

#include <iostream>

/***********************************************
 * Node
 * A node to be used in a linked list
 **********************************************/
template <class T>
class Node
{
   public:
      // constructors
      Node(): pNext(NULL) {}
      Node(const T & t): data(t) {}
      
      // members
      Node <T> * pNext;
      T data;
};

/***********************************************
* COPY
* Copy a linked­list. Takes a pointer to a Node as a parameter and returns a newly
* created linked­list containing a copy of all the nodes below the list represented by the
* parameter. This should be a non­member function.
***********************************************/
template <class T>
Node <T> * copy(const Node <T> * pSource) throw (const char *)
{
   // trivial case
   if (NULL == pSource)
      return NULL;
   
   try
   {
      // allocate a new head
      Node <T> * pDestination = new Node <T> (pSource->data);
      Node <T> * pCurrent = pDestination;

      // loop through the rest of the source linked list
      while (pSource->pNext)
      {
         pSource = pSource->pNext;
         pCurrent->pNext = new Node <T> (pSource->data);
         pCurrent = pCurrent->pNext;
      }

      return pDestination;
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: Failed to allocate memory for list\n";
   }
}

/***********************************************
* INSERT
* Insert a new Node into the current linked­list. The first parameter is the value to
* be placed in the new Node. The second parameter is the Node preceding the new Node in the
* list. An optional third parameter is set to true if the new item is to be at the head of the
* list. Please return a pointer to the newly created Node. This should be a non­member function.
***********************************************/
template <class T>
Node <T> * insert(const T & t, Node <T> * &pCurrent, bool isHead = false)
{  
   try
   {
      Node <T> * pNew = new Node <T>(t);
      
      // IF NULL
      if (pCurrent == NULL)
      {
         pCurrent = pNew;
         return pNew;
      }
      
      // IF isHead
      if (pCurrent != NULL && isHead)
      {
         pNew->pNext = pCurrent;
         pCurrent = pNew;
         return pNew;
      }
      
      // IF !isHead
      if (pCurrent != NULL && !isHead)
      {    
         pNew->pNext = pCurrent->pNext;
         pCurrent->pNext = pNew;
         return pNew;
      }
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: bad_alloc";
   }

}

/***********************************************
* FIND
* Find the Node corresponding to a given passed value from a given linked­list. The
* first parameter is a pointer to the front of the list, the second is the value to be found. The
* return value is a pointer to the found node if one exists. This should be a non­member
* function.
***********************************************/
template <class T>
Node <T> * find(Node <T> * pHead, const T & t)
{
   
}

/***********************************************
* DISPLAY
* Display the list for debugging
***********************************************/
template <class T>
void display(Node <T> * pHead)
{      
   std::cout << "\tentry\tvalue\taddress\n"
             << "--------------------------\n";
             
   if (pHead == NULL)
      return;
             
   int count = 0;
   for (Node <T> * p = pHead; p; p = p->pNext)
   {
      std::cout << "\t"
                << count
                << "\t"
                << p->data
                << "\t"
                << &p
                << std::endl;
      count++;
   }
}


/***********************************************
* EXTRACTION OPERATOR <<
* Display the contents of a given linked­list.
***********************************************/
template <class T>
std::ostream & operator << (std::ostream & out, Node <T> * pNode)
{
   for (Node <T> * p = pNode; p; p = p->pNext)
   {
      out << p->data << (p->pNext == NULL ? "" : ", ");
      //std::cout << "current data: " << p->data << std::endl;
   }
   
   return out;
}

/***********************************************
* FREE DATA
* Release all the memory contained in a given linked­list. The one parameter is a
* pointer to the head of the list. This should be a non­member function.
***********************************************/
template <class T>
void freeData(Node <T> * &pHead)
{
   if (pHead == NULL)
      return;
   
   Node <T> * pNext;
   for (Node <T> * p = pHead; p; p = pNext)
   {
      std::cout << "Fcurrent data: " << p->data << std::endl;
      if (p == NULL)
         return;
      pNext = p->pNext;
      delete p;
      std::cout << "pNext data: " << p->pNext << std::endl;
   }
   pHead = NULL;
}


#endif // NODE_H