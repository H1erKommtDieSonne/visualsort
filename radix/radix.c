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

    int step = 0;
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[SIZE] = {0}; // Инициализируем нулями
        int count[10] = {0};

        // Подсчет количества элементов
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
            
            // Запись промежуточного состояния
            char filename[20];
            sprintf(filename, "step_%03d.txt", step++);
            FILE *file = fopen(filename, "w");
            for (int j = 0; j < n; j++) {
                fprintf(file, "%d\n", arr[j]);
            }
            fclose(file);
        }

        // Модифицируем count для получения актуальных позиций
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Построение выходного массива
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
            
            // Запись промежуточного состояния
            char filename[20];
            sprintf(filename, "step_%03d.txt", step++);
            FILE *file = fopen(filename, "w");
            for (int j = 0; j < n; j++) {
                fprintf(file, "%d\n", output[j]);
            }
            fclose(file);
        }

        // Копируем output обратно в arr
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

int main() {
    srand(time(NULL));
    int arr[SIZE];

    // Заполняем массив случайными числами
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    radixSort(arr, SIZE);

    return 0;
}
