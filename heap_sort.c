/**
 *  heap_sort:      The time complexity of heap sort is O(log n).
 *  init_heap:      The time complexity of building heap tree is O(n).
 *  max_heapify:    Has time complexity of O(log n) but we end up
 *                  calling it n - 1 times.              
*/
#include <stdio.h>
#define MAX_SIZE 15

void init_heap(int array[], int cur_size);
void swap(int *x, int *y);
void max_heapify(int array[], int index, int cur_size);
void heap_sort(int array[], int cur_size);
//void insert(int array[], int data, int *cur_size);
void print_heap(int array[], int cur_size);

int main(void)
{
    int array[MAX_SIZE] = {8, 1, 5, 3, 7, 2};
    init_heap(array, 6);
    heap_sort(array, 6);
    print_heap(array, 6);
    return 0;
}

void init_heap(int array[], int cur_size)
{
    for (int i = cur_size / 2; i >= 0; i--)
    {
        max_heapify(array, i, cur_size);
    }
}

void max_heapify(int array[], int index, int cur_size)
{
    int left_child = 2 * index + 1;

    int right_child = 2 * index + 2;

    int largest = index;

    if (left_child < cur_size && array[left_child] > array[largest])
    {
        largest = left_child;
    }

    if (right_child < cur_size && array[right_child] > array[largest])
    {
        largest = right_child;
    }

    if (largest != index)
    {
        swap(&array[largest], &array[index]);
        max_heapify(array, largest, cur_size);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heap_sort(int array[], int cur_size)
{
    for (int i = cur_size - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        max_heapify(array, 0, i);
    }
    /*while (cur_size > 1)
    {
        swap(&array[0], &array[cur_size - 1]);
        cur_size--;

        max_heapify(array, 0, cur_size);
    }*/
}

void print_heap(int array[], int cur_size) 
{
    for (int i = 0; i < cur_size; i++) 
    {
        printf("%d\n", array[i]);
    }
    printf("\n");
}