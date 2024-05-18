/**
 * Selection sort:  The runtime complexity of selection sort is O(n^2) = quadratic time
 *                  So as the data grows in size, the more and more ineffecient selection
 *                  sort is going to be. It is okay with smaller data sets.
*/
#include <stdio.h>

void selection_sort(int arr[], int size);

int main(void)
{
    int array[] = {5, 2, 88, 6, 1, 9, 3, 21};
    int size = sizeof(array) / sizeof(array[0]);
    selection_sort(array, size);
    return 0;
}

/**
 * @brief selection sort to sort array in increasing order.
 * 
 * @arr array to be sorted.
 * @size size of array.
*/
void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // We start by keeping track of index of our minimal value so far.
        int temp;
        int min_idx = i;
        int flag = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j; // we keep track of new index where lowest value is.
                flag = 1;
            }
        }
        /**
         * I am keeping this flag here in case there was no new minimal value found.
         * I will skip the swapping in that case, it would work even if I don't keep
         * this flag but it saves me some steps in each iteration.
        */
        if (flag)
        {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
       
    }
}