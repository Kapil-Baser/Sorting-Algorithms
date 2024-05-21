/**
 * Bubble sort:  The runtime complexity of bubble sort is O(n^2) = quadratic time
 *                  So as the data grows in size, the more and more ineffecient bubble
 *                  sort is going to be. It is okay with smaller data sets.
*/
#include <stdio.h>

/**
 * @brief Bubble sort to sort array in acending order.
 * 
 * @arr the array that needs to be sorted
 * @size the size of array.
*/
void bubble_sort(int arr[], int size)
{
    /**
     * We start by having swap counter to -1 to initialize out outer while loop.
    */
    int swaps = -1;

    while (swaps != 0)
    {
        int i = 0;
        swaps = 0; // We update the swap counter to 0 here so we can count the number of swaps this alorithm makes.
        while (i < size - 1)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                swaps++;
            }
            i++;  
        }
    }
}
int main(void)
{
    int array[] = {5, 2, 81, 441, 3, 6};
    int size = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, size);

    return 0;
}