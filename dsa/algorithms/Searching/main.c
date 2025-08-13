#include "Search.h"
#include <stdio.h>

void binarySearchImplementation();
void linearSearchImplementation();

int main(int argc, char const *argv[])
{
    // Testing Binary Search
    binarySearchImplementation(); 
    
    // Testing Linear Search
    // linearSearchImplementation();
    return 0;
}

// To test multiple algorithms we created seprate implementaion methods

void binarySearchImplementation()
{
    // Here we declared array of length 100
    int array[100];

    // Added 100 values in array in sorted way
    for (int i = 1; i <= 100; i++)
    {
        array[i] = i;
    }

    // If value found in list then it will return index of value else -1
    int result = binarySearch(array, 7, 100);
    if (result == -1)
    {
        printf("Not found");
    }
    else
    {
        printf("Element found at index %d", result);
    }
}

void linearSearchImplementation()
{
    // Here we declared array of length 100
    int array[100];

    // Added 100 values in array in sorted way
    for (int i = 1; i <= 100; i++)
    {
        array[i] = i;
    }

    // If value found in list then it will return index of value else -1
    int result = linearSearch(array, 7, 100);
    if (result == -1)
    {
        printf("Not found");
    }
    else
    {
        printf("Element found at index %d", result);
    }
}