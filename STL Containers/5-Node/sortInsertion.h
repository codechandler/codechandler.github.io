/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   // build the linked list
   Node <T> * pHead = NULL;
   for (int i = 0; i < num; i++)
      insertSorted(array[i], pHead);

   // copy the data from the link list back to the array
   Node <T> * p = pHead;
   for (int i = 0; i < num; i++)
   {
      array[i] = p->data;
      // advance to next node
      p = p->pNext;

   }

   // do not forget to delete the data when finished
   freeData(pHead);
}


/**********************************************
 * FIND SORTED
 * find the place where the item needs to be
 * placed in the array.
 **********************************************/
 template <class T>
 Node <T> * findSorted(Node <T> * pHead, const T & t)
 {
     if (pHead == NULL)
       return NULL;
     if (t < pHead->data)
       return NULL;
     Node <T> * pPrevious = pHead;
     while (t > pHead->data)
     {
       if (pHead->pNext == NULL)
         return pHead;
       pPrevious = pHead;
       pHead = pHead->pNext;
     }
     pHead = pPrevious;
     return pHead;
 }
 
/**********************************************
 * INSERT SORTED
 * Insert a new node the the value in "t" into a linked
 * list denoted by pHead.  Place the new node in sorted order
 *   INPUT   : the new value to be put into the linked list
 *             a pointer to the head of the linked list
 *   OUTPUT  : the newly created item
 *   COST    : O(n)
 **********************************************/
template <class T>
Node <T> * insertSorted(const T & t, Node <T> * & pHead) throw (const char *)
{
   try
   {
      // allocate a new node
      Node <T> * pNew = new Node <T> (t);

      // find the location in the linked list immediately before
      // the new node to be inserted
      Node <T> * pFind = findSorted(pHead, t);
      
      // insert the new node to the head of the list
      if (pFind == NULL)
      {
         pNew->pNext = pHead;
         pHead = pNew;
      }
      // otherwise, insert the new node after the found one
      else
      {
         pNew->pNext = pFind->pNext;
         pFind->pNext = pNew;
      }
      
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new Node";
   }
}
#endif // INSERTION_SORT_H

