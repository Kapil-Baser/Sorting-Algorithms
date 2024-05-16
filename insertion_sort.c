#include <stdio.h>
#define N 10

void insertion_sort(int arr[], int size);

int main(void)
{
    int array[N] = {6, 10, 4, 7, 2, 8, 3, 9, 5, 1};

    insertion_sort(array, N);
    return 0;
}

/**
 * @brief Applies insertion sort on given array to sort it's elements in
 * increasing order.
 * 
 * @param arr array to sort.
 * @param size size of array.
*/
void insertion_sort(int arr[], int size)
{
    /**
     * Insertion sort begin at index 1 since a single index before that is
     * already sorted.
     * Outer loop will run until we are at the last element of our array.
    */
    for (size_t i = 1; i < size; i++)
    {
        /**
         * A temp variable to keep the value to insert at the correct index.
        */
        int temp = arr[i];
        int j = i - 1;
        /**
         * Inner loop will compare each element with temp and shift the
         * elements to the right if they are bigger.
         * Loop runs backwards until we go past element 0 or an element
         * which is already less than temp, that must mean that anything
         * before that element is already in proper order and we can stop
         * the loop here.
        */
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            //arr[j] = temp;
            j--;
        }
        /**
         * Insert the element at the proper index.
         * [j + 1] is there since we are running loop in reverse,
         * so if the right position of element is at 0, then [j] will
         * stop at -1, we increment it again to come back to 0 index.
        */
        arr[j + 1] = temp;
    }
}
