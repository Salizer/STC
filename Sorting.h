#ifndef SORTING_H
#define SORTING_H
/** \file  Sorting.h
	\brief Contains sorting algorithms.
	\author René H. Thomsen
	\date 24/04 -11
*/
// License: GPL

// Prototypes
void insertionSort(int data[], size_t n);
size_t selectPivotIndex(int data[], size_t n); // Helper function
void partition(int data[], size_t n, size_t& pivot_index); // Helper function
void quickSort(int data[], size_t n, size_t bc);


/** \brief Sorts and array of elements.
    \pre 'data' is not NULL. 'n' is less than or equal to the size of the meory are pointed by 'data'.
    \post The array is sorted from smallest value to biggest value.(Left to right)
*/
void insertionSort(int data[], size_t n)
{
	// Case 1 element or empty array
	if(n <= 1){return;}

	// Begin insertion
	for(int i = 1; i < n; i++)
	{
        int tmpElement = data[i]; // Data to be inserted into sorted area

        // Check for where to insert, and swap the element down the row till right place is found
        for(int k = (i - 1); k >= 0; k--)
        {
            if(data[k] <= tmpElement) // Right place found
            {
                data[k + 1] = tmpElement;
                break;
            }
            else
            {   // Swapping element down the row
                data[k + 1] = data[k];
                data[k] = tmpElement;
            }
        }
	}
}

/** \brief Sorts the array smallest to biggest.
    \pre 'data' is not NULL. 'n' is less than or equal to the size of the meory are pointed by 'data'.
    \post The array is sorted smallest to biggest. (Left to right)
*/
void quickSort(int data[], size_t n)
{
    size_t n1;
    size_t n2;
    size_t pivot_index;

    if (n > 1)
    {
        if(n < 20) // Quicker way if less elements than base case(20)
        {
            insertionSort(data, n);
        }
        else
        {
            // Partition the array. After the call, pivot_index will point to the pivot
            partition(data, n, pivot_index);

            // Calculate size of left and right part of array to sort
            //
            // data: [---------------P---------]
            // n1:    |------------->
            // n2:                    |------->
            // n:     |----------------------->
            n1 = pivot_index;
            n2= n - n1 - 1;

            // Sort each part recursively
            quicksort((data), n1);
            quicksort((data + n1+1), n2);
        }
    }
}

/** \brief Partions the array.
    \pre 'data' is not NULL. 'n' is less than or equal to the size of the meory are pointed by 'data'.
    \post All elements smaller than pivot is left to it and all smaller is to the right of it.
*/
void partition(int data[], size_t n, size_t& pivot_index)
{
    // Case 1 element or less
    if(n <= 1){return;}

    // Save pivot and put in front
    int pivot = selectPivotIndex(data, n);
    pivot_index = 0;

    // Start sorting so:
    // data[0..pivot_index-1] < data[pivot_index] < data[pivot_index+1..n-1]
    size_t indexS = 1;
    size_t indexE = n - 1;

    while(indexS <= indexE)
    {
        if(data[indexS] >= pivot) // Value should in right side from pivot, so looking for 'anyone' to swap with
        {
            if(data[indexE] > pivot) // Also bigger than pivot
                indexE--;
            else // Less than pivot so 'perfect' for a swap
            {
                swap(data[indexS], data[indexE]);
                indexS++;
                indexE--;
            }
        }
        else
            indexS++; // Right place so trying next element
    }

    // Put in pivot at right place
    swap(data[0], data[indexE]);
    pivot_index = indexE;
}

/** \brief Selects a pivot index.
    \pre 'data' is not NULL. 'n' is less than or equal to the size of the meory are pointed by 'data'.
    \post Have selected and index in the range: [0; n - 1]
*/
size_t selectPivotIndex(int data[], size_t n)
{
  return 0;
}
#endif
