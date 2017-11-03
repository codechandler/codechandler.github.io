/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    Nathan Bench, Jed Bilman, Jeremy Chandler, Justin Chandler
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/
 

#ifndef SORT_MERGE_H
#define SORT_MERGE_H


template <class T>
void merge(T array[], int l, int m, int r)
{
	int i, j, k; //indexes for first, second, and merged arrays
	int n1 = m - l + 1;
	int n2 = r - m;

	// temp arrays
	T * L;
	T * R;
	L = new T[n1];
	R = new T[n2];

	// copy data
	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (j = 0; j < n2; j++)
		R[j] = array[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	// copy the left over L[] elements
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	// copy the left over R[] elements
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}

template <class T>
void sort(T array[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		sort(array, l, m); // sort first half
		sort(array, m + 1, r); //sort second half

		merge(array, l, m, r);
	}
}
/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
void sortMerge(T array[], int num)
{
	sort(array, 0, num - 1);
}



#endif // SORT_MERGE_H

