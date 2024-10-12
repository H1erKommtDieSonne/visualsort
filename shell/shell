#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void shellSort(int arr[], int n) {
  int gap, i, j;
  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      for (j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap) {
        swap(&arr[j], &arr[j - gap]);

        char filename[20];
        sprintf(filename, "step_%03d.txt", (int) (gap / 2) * 10 + i);
        FILE *file = fopen(filename, "w");
        for (int k = 0; k < n; k++) {
          fprintf(file, "%d\n", arr[k]);
        }
        fclose(file);
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

  shellSort(arr, SIZE);

  //printf("Отсортированный массив:\n");
  //for (int i = 0; i < SIZE; i++) {
  //  printf("%d ", arr[i]);
  //}
  //printf("\n");

  return 0;
}

