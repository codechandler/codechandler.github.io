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

#include "node.h"
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
         pCurrent->pNext = NULL;
         return pNew;
      }
      
      // IF isHead
      if (pCurrent != NULL && isHead)
      {
         pNew->pNext = pCurrent;
         pCurrent = pNew;
         return pCurrent;
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
 for (Node<T> * p = pHead; p; p=p->pNext)
 {
   if (p->data == t)
    return p;
 }  
 return NULL;
}

/***********************************************
* EXTRACTION OPERATOR <<
* Display the contents of a given linked­list.
***********************************************/
template <class T>
std::ostream & operator << (std::ostream & out, Node <T> * pHead)
{
   for (Node <T> * p = pHead; p; p = p->pNext)
   {
      out << p->data;
    if (p->pNext != NULL)
     out << ", ";
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
/*   if (pHead == NULL)
    return;
   for (Node <T> * p = pHead; p; p = p->pNext)
   {
      std::cerr << "Pointer data: " << p->data << " p->pNext data: " << p->pNext->data << std::endl;
      delete p;
      std::cerr << "deleting p\n";
   }
    pHead = NULL;
    */
    while (pHead != NULL)
   {
     Node <T> * p = pHead;
     pHead = pHead->pNext;
     delete p;
   }
 
}


#endif // NODE_H
