
int shell_sort(int *arr, int size)
{
    int gap = size / 2; // Initial gap.

    while (gap > 0)
    {
        int value, outer, inner;
        for (outer = gap; outer < size; outer++)
        {
            inner = outer;
            value = arr[outer];
            while (inner > gap - 1 && arr[inner - gap] > value)
            {
                arr[inner] = arr[inner - gap];
                inner -= gap;
            }
            arr[inner] = value;
        }
        gap /= 2;
    }
}

int main(void)
{
    int array[] = {5, 4, 8, 6, 3, 10, 9, 7, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    shell_sort(array, size);
}