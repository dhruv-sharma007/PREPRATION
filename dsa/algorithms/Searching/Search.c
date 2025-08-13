#include "Search.h"

// This algorithm is for positive sorted integers
int binarySearch(int *arr, int target, int size)
{
    /* The Binary search is based on Divide and Conquer method
     * Time Complexity of Binary Search is O(log n)
     */

    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = low  + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1; // We added 1 to prevent infinite loop Conditions
        }
        else
        {
            high = mid - 1; // Here also did for preventing infinite loop
        }
    }

    // IF Found nothing we will retuen -1

    return -1;
}

// This algorithm is for positive integers
int linearSearch(int *arr, int target, int size)
{
    // Time Complexity of this algorithm is O(n)
    // SLow and simple searching algorithm
    // linearSearch can search in sorted and in non sorted both data structures

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}