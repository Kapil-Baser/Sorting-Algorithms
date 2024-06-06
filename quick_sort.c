#include <stdio.h>
/**
 * Quick sort:  moves smaller elements to left of a pivot and recursively divide the array in 2 partitions.
 * 
 * Runtime complexity:  Best case O(n log(n))
 *                      Average case O(n log(n))
 *                      Worst case O(n^2)
 * 
 * Space complexity:    O(log(n)) 
 */

void swap(int *x, int *y);

void quick_sort(int arr[], int start_idx, int end_idx);

int partition(int arr[], int start_idx, int end_idx);

int main(void)
{
    int array[] = {8, 2, 4, 7, 1, 3, 9, 6, 5};
    int size = sizeof(array) / sizeof(array[0]);
    quick_sort(array, 0, size - 1);
    return 0;
}

/**
 * @brief swaps the two elements
 * 
 * @x pointer to first element
 * @y pointer to second element
 */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * @brief recursive sorting algorithm
 * 
 * @arr array to perform the sorting operation
 * @start_idx starting index of array
 * @end_idx last index of array
 */
void quick_sort(int arr[], int start_idx, int end_idx)
{
    // base case
    if (end_idx <= start_idx)
    {
        return;
    }
    int pivot = partition(arr, start_idx, end_idx);
    // recursive case
    quick_sort(arr, start_idx, pivot - 1);
    quick_sort(arr, pivot + 1, end_idx);
}

/**
 * @brief a helper function for quick sort to partition the given array
 *        and return a pivot index.
 * 
 * @arr array to perform the partition on
 * @start_idx starting index of array
 * @end_idx last index of array
 * 
 * @return pivot index of array
 */
int partition(int arr[], int start_idx, int end_idx)
{
    int pivot = arr[end_idx];
    int i = start_idx - 1;

    for (int j = start_idx; j <= end_idx - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end_idx]);
    return i;
}
