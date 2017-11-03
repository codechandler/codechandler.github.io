/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    Nathan Bench, Jed Bilman, Jeremy Chandler, Justin Chandler
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort
 ****************************************************/
template <class T>
void sortSelection(T array[], int num)
{
   for (int iPivot = num - 1; iPivot > 0; iPivot--)
   {
      int iLargest = 0;
      for (int iCheck = 0; iCheck <= iPivot; iCheck++)
      {
         if (array[iCheck] > array[iLargest])
            iLargest = iCheck;
      }
      if (array[iLargest] > array[iPivot])
      {
         T temp = array[iPivot];
         array[iPivot] = array[iLargest];
         array[iLargest] = temp;
      }
   }
}


#endif // SORT_SELECTION_H
