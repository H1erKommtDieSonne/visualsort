#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void shakerSort(int arr[], int n) {
  int left = 0;
  int right = n - 1;
  int step = 1; 

  while (left < right) {

    for (int i = left; i < right; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);


        char filename[20];
        sprintf(filename, "step_%03d.txt", step);
        FILE *file = fopen(filename, "w");
        for (int j = 0; j < n; j++) {
          fprintf(file, "%d\n", arr[j]);
        }
        fclose(file);
        step++;
      }
    }
    right--;


    for (int i = right; i > left; i--) {
      if (arr[i] < arr[i - 1]) {
        swap(&arr[i], &arr[i - 1]);

        char filename[20];
        sprintf(filename, "step_%03d.txt", step);
        FILE *file = fopen(filename, "w");
        for (int j = 0; j < n; j++) {
          fprintf(file, "%d\n", arr[j]);
        }
        fclose(file);
        step++;
      }
    }
    left++;
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


  shakerSort(arr, SIZE);

  //printf("Отсортированный массив:\n");
  //for (int i = 0; i < SIZE; i++) {
  //  printf("%d ", arr[i]);
  //}
  //printf("\n");

  return 0;
}

