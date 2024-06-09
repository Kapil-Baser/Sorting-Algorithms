#include <stdio.h>
#include <string.h>
//
// Function prototypes. 
//
int max(int arr[], int len);
void counting_sort(int arr[], int len);
void print_array(int arr[], int len);

int main(void)
{
    int array[] = {8, 1, 3, 5, 1, 8, 6};
    int len = sizeof(array) / sizeof(array[0]);
    printf("Unsorted array: ");
    print_array(array, len);
    counting_sort(array, len);
    printf("\nSorted array: ");
    print_array(array, len);
    return 0;
}

/// @brief      Gets the largest element in a given array.
/// @param arr  Array where largest element needs to be found.
/// @param len  Length of array.
/// @return     Largest element of array.
int max(int arr[], int len)
{
    int max = arr[0];

    for (int i = 1; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

/// @brief      Sorts an array in increasing order using counting sort.
/// @param arr  Array that needs to be sorted.
/// @param len  Length of array.
void counting_sort(int arr[], int len)
{
    // first we find our key value, which will be the size of our frequincies array.
    int key = max(arr, len);
    int freq[key + 1];
    memset(freq, 0, sizeof(freq));
    // Calculating the frequencies of elements.
    for (int i = 0; i < len; i++)
    {
        freq[arr[i]]++;
    }
    // Updating the frequency array
    for (int j = 1; j <= key + 1; j++)
    {
        freq[j] += freq[j - 1];
    }
    
    // now we sort the array and start from last index of array, to maintain the stability of array.
    int sorted[len];
    memset(sorted, 0, sizeof(sorted));
    for (int k = len - 1; k >= 0; k--)
    {
        sorted[freq[arr[k]] - 1] = arr[k];
        freq[arr[k]]--;
    }
    
    // Copy this sorted array to our original array.
    for (int i = 0; i < len; i++)
    {
        arr[i] = sorted[i];
    }
}

/// @brief      Prints the given array.
/// @param arr  Array that needs to be printed.
/// @param len  Length of array.
void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}
