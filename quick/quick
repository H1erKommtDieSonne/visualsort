#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high, int step) {
  int pivot = arr[high];
  int i = (low - 1);


  char filename[20];
  sprintf(filename, "step_%03d.txt", step);
  FILE *file = fopen(filename, "w");
  for (int j = 0; j < SIZE; j++) {
    fprintf(file, "%d\n", arr[j]);
  }
  fclose(file);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);


      sprintf(filename, "step_%03d.txt", step + 1);
      file = fopen(filename, "w");
      for (int k = 0; k < SIZE; k++) {
        fprintf(file, "%d\n", arr[k]);
      }
      fclose(file);
      step++;
    }
  }
  swap(&arr[i + 1], &arr[high]);

  sprintf(filename, "step_%03d.txt", step + 1);
  file = fopen(filename, "w");
  for (int j = 0; j < SIZE; j++) {
    fprintf(file, "%d\n", arr[j]);
  }
  fclose(file);
  step++;

  return (i + 1);
}

void quickSort(int arr[], int low, int high, int step) {
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

  //printf("Исходный массив:\n");
  //for (int i = 0; i < SIZE; i++) {
  //  printf("%d ", arr[i]);
  //}
  //printf("\n");

  quickSort(arr, 0, SIZE - 1, 1);

  //printf("Отсортированный массив:\n");
  //for (int i = 0; i < SIZE; i++) {
  //  printf("%d ", arr[i]);
  //}
  //printf("\n");

  return 0;
}

