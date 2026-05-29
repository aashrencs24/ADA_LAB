#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
/* Function to swap two elements */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* Partition function */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/* Quick Sort function */
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[MAX];
    int n;
    clock_t start, end;
    double time_taken;
    srand(time(0));
    for(n = 10000; n <= 100000; n += 10000)
    {
        for(int i = 0; i < n; i++)
            arr[i] = rand() % 100000;

        start = clock();

        quickSort(arr, 0, n - 1);

        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%dK input time taken = %f seconds\n",
               n / 1000, time_taken);
    }

    return 0;
}