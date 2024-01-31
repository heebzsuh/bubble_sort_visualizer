#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define DELAY_MS

void printArray(int arr[10], int arr_size, int sel1, int sel2)
{ // sel1 ans sel2 are index values of left and right elt to be swapped
    for (int i = 0; i < arr_size; i++)
    {
        if (i == sel1 || i == sel2)
        {
            printf("\x1b[35m%d \x1b[0m ", arr[i]); // jungly code to print text in purple
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\r");
    fflush(stdout);
}

void delay(int ms)
{
    int ns = ms * 1000;
    for (int i = 0; i < ns; i++)
        ;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[10], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        { // loop iterates till size-i-1, as first sort will push biggest elt to last
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
            printArray(arr, size, j, j + 1); // passing index of elts to be swapped
            delay(DELAY_MS);
        }
    }
}

int main()
{
    srand(time(NULL)); // takes curr time on laptop

    int arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 100; // random integer generator btwn 1 and 100
    }
    printf("Original array=");
    printArray(arr, ARRAY_SIZE, -1, -1);
    printf("\n");

    printf("Sorting steps=\n");
    bubbleSort(arr, ARRAY_SIZE);

    printf("Sorted array=");
    printArray(arr, ARRAY_SIZE, -1, -1);
    printf("\n");

    return 0;
}