#include "Sorting.h"
#include <stdio.h>

void TestingSortingFunc(void (*sortingFunction)(int arr[], int i));

void main(int argc, char const *argv[])
{

    printf("\n--- BubbleSort ---\n");
    TestingSortingFunc(BubbleSort);
    printf("\n--- InsertionSort ---\n");
    TestingSortingFunc(InsertionSort);
    printf("\n--- SelectionSort ---\n");
    TestingSortingFunc(SelectionSort);
}

void TestingSortingFunc(void (*sortingFunction)(int arr[], int i))
{

    int n = 8;
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};

    printf("/n ");
    printf("Actual Array :- ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    sortingFunction(arr, n);

    printf("\n-- Result --\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return;
}
