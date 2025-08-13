#include "Sorting.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter Elements : ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    BubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }

    return 0;
}
