/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    Nathan Bench, Jed Bilman, Jeremy Chandler, Justin Chandler
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>


template <class T>
int binarySearch(T array[], T search, int iBegin, int iEnd)
{
   int iMiddle = iBegin + (iEnd - iBegin) / 2;
   
   if (iBegin == iEnd)
      return iBegin;
   if (search > array[iMiddle])
      return binarySearch(array, search, iMiddle + 1, iEnd);
   else if (array[iMiddle] > search)
      return binarySearch(array, search, iBegin, iMiddle);
   
   return iMiddle;
}

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   int iShift, iPivot, iInsert;
   T valuePivot;
   for (iPivot = 1; iPivot < num; iPivot++)
   {
      valuePivot = array[iPivot];
      iInsert = binarySearch(array, valuePivot, 0, iPivot);
      for (iShift = iPivot - 1; iShift >= iInsert; iShift--)
      {
         array[iShift + 1] = array[iShift];
      } 
      array[iInsert] = valuePivot;
   }
   
   /*for (int iPivot = 1; iPivot < num; iPivot++)
   {
      T valuePivot = array[iPivot];
      int iShift = iPivot - 1;
      for (;iShift >= 0 && array[iShift] > valuePivot; --iShift)
      {
         array[iShift + 1] = array[iShift];
      }
      array[iShift + 1] = valuePivot;
      
   }*/
}


#endif // SORT_INSERTION_H
