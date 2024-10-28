#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400
#define MAX_VALUE 100

int main() {
    for (int step = 0; step <= 999; step++) {
        char filename[100];
        sprintf(filename, "step_%03d.txt", step);

        FILE *data = fopen(filename, "r");

        if (data == NULL) {
        //    printf("Ошибка открытия файла: %s\n", filename);
            continue;
        }

        char image_filename[100];
        sprintf(image_filename, "image_%03d.ppm", step);
        FILE *image = fopen(image_filename, "wb");

        fprintf(image, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

        int values[1000] = {0};
        int count = 0;
        int value;
        while (fscanf(data, "%d", &value) != EOF) {
            values[count++] = value;
        }

        fclose(data);

        int max_value = 0;
        for (int i = 0; i < count; i++) {
            if (values[i] > max_value) {
                max_value = values[i];
            }
        }

        for (int y = HEIGHT - 1; y >= 0; y--) {
            for (int x = 0; x < WIDTH; x++) {
                int value = (int) (((double) values[x * count / WIDTH] / max_value) * 255);

                fprintf(image, "%d %d %d ", value, value, value);
            }
        }

        fclose(image);
    }

    return 0;
}
