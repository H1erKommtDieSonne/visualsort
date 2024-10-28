#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int *step) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);

            char filename[20];
            (*step)++;
            sprintf(filename, "step_%03d.txt", *step);
            FILE *file = fopen(filename, "w");
            for (int k = 0; k < SIZE; k++) {
                fprintf(file, "%d\n", arr[k]);
            }
            fclose(file);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    char filename[20];
    (*step)++;
    sprintf(filename, "step_%03d.txt", *step);
    FILE *file = fopen(filename, "w");
    for (int k = 0; k < SIZE; k++) {
        fprintf(file, "%d\n", arr[k]);
    }
    fclose(file);

    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *step) {
    if (low < high) {
        int pi = partition(arr, low, high, step);  

        quickSort(arr, low, pi - 1, step);  
        quickSort(arr, pi + 1, high, step);  
    }
}

int main() {
    srand(time(NULL));
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    int step = 0;
    quickSort(arr, 0, SIZE - 1, &step);

    return 0;
}

