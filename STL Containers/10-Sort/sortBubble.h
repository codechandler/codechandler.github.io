/***********************************************************************
 * Module:
 *    Week 11, Sort Bubble
 *    Brother Helfrich, CS 235
 * Author:
 *    Nathan Bench, Jed Bilman, Jeremy Chandler, Justin Chandler
 * Summary:
 *    This program will implement the Bubble Sort
 ************************************************************************/

#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

/*****************************************************
 * SORT BUBBLE
 * Perform the bubble sort
 ****************************************************/
template <class T>
void sortBubble(T array[], int num)
{
   for (int iPivot = num - 1; iPivot > 0; iPivot--)
   {
      bool swapped = false;
      for (int iCheck = 0; iCheck <= iPivot - 1; iCheck++)
      {
         T temp;
         if (array[iCheck] > array[iCheck + 1])
         {
            // TODO: Fix swap function
            temp = array[iCheck + 1];
            array[iCheck + 1] = array[iCheck];
            array[iCheck] = temp;
            swapped = true;
         }
      }
      if (!swapped)
         return;
   }
}


#endif // SORT_BUBBLE_H
