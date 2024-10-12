#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define MAX_VALUE 100

void radixSort(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    int output[SIZE];
    int count[10] = {0};


    for (int i = 0; i < n; i++) {
      count[(arr[i] / exp) % 10]++;


      char filename[20];
      sprintf(filename, "step_%03d.txt", (int) (exp / 10) * 10 + i);
      FILE *file = fopen(filename, "w");
      for (int j = 0; j < n; j++) {
        fprintf(file, "%d\n", arr[j]);
      }
      fclose(file);
    }


    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;


      char filename[20];
      sprintf(filename, "step_%03d.txt", (int) (exp / 10) * 10 + n + i);
      FILE *file = fopen(filename, "w");
      for (int j = 0; j < n; j++) {
        fprintf(file, "%d\n", output[j]);
      }
      fclose(file);
    }

    for (int i = 0; i < n; i++) {
      arr[i] = output[i];
    }
  }
}

int main() {
  srand(time(NULL));
  int arr[SIZE];

  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % MAX_VALUE;
  }

  //printf("Исходный массив:\n");
  //for (int i = 0; i < SIZE; i++) {
  //  printf("%d ", arr[i]);
  //}
  //printf("\n");

  radixSort(arr, SIZE);

  //printf("Отсортированный массив:\n");
  //for (int i = 0; i < SIZE; i++) {
  //  printf("%d ", arr[i]);
  //}
  //printf("\n");

  return 0;
}


