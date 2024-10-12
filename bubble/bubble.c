#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int n) {
  int step = 1;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);


        char filename[20];
        sprintf(filename, "step_%03d.txt", step);
        FILE *file = fopen(filename, "w");
        for (int k = 0; k < n; k++) {
          fprintf(file, "%d\n", arr[k]);
        }
        fclose(file);
        step++;
      }
    }
  }
}

int main() {
  srand(time(NULL));
  int arr[SIZE];


  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100;
  }


  //printf("Исходный массив:\n");
  //for (int i = 0; i < SIZE; i++) {
  //  printf("%d ", arr[i]);
  //}
  //printf("\n");


  bubbleSort(arr, SIZE);

  //printf("Отсортированный массив:\n");
  //for (int i = 0; i < SIZE; i++) {
  //  printf("%d ", arr[i]);
  //}
  //printf("\n");

  return 0;
}
