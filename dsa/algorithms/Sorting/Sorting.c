#include "Sorting.h"
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                if (flag == 0)
                    flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}

void InsertionSort(int arr[], int n)
{
    // in insertion sort we compare elements with it's left side of elements
    // if the left side of elements are bigger then key element
    // we will shift left elements to right side until key is shorter then left elements

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        // we increased j here because after while loop j will be more one step back from empty slot
        // if while condition is false key still remain in at sane index

        arr[j + 1] = key;
    }
}

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(&arr[min], &arr[i]);
        }
    }
}

// Quick Sort Starts Here

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);

    return j;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = Partition(arr, low, high);
        QuickSort(arr, low, j);
        QuickSort(arr, j + 1, high);
    }
}

// Quick Sort Ends Here