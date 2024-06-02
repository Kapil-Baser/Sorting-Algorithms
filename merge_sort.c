#include <stdio.h>

void merge_sort(int arr[], int size);
void merge_split(int arr[], int left_idx, int right_idx);
void merge(int arr[], int left_idx, int middle_idx, int right_idx);
int main(void)
{
    int array[] = {5, 4, 8, 1, 3, 2};
    int size = sizeof(array) / sizeof(array[0]);
    merge_sort(array, size);
    return 0;
}

void merge_sort(int arr[], int size)
{
    merge_split(arr, 0, size - 1);
}

void merge_split(int arr[], int left_idx, int right_idx)
{
    if (left_idx < right_idx)
    {
        int middle_idx = left_idx + (right_idx - 1) / 2;

        merge_split(arr, left_idx, middle_idx);
        merge_split(arr, middle_idx + 1, right_idx);

        merge(arr, left_idx, middle_idx, right_idx);
    }

}

void merge(int arr[], int left_idx, int middle_idx, int right_idx)
{

    int left_length = middle_idx - left_idx + 1;

    int right_length = right_idx - middle_idx;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (int i = 0; i < left_length; i++)
    {
        temp_left[i] = arr[left_idx + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        temp_right[i] = arr[middle_idx + 1 + i];
    }

    for (i = 0, j = 0, k = left_idx; k <= right_idx; k++)
    {
        if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            arr[k] = temp_left[i];
            i++;
        }
        else
        {
            arr[k] = temp_right[j];
            j++;
        }
    }
}
