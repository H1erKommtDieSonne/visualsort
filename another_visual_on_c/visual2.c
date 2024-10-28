#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 600
#define HEIGHT 400
#define MAX_VALUE 100
#define BAR_WIDTH 10 

int main() {
    for (int step = 0; step <= 999; step++) {
        char filename[100];
        sprintf(filename, "step_%03d.txt", step);

        FILE *data = fopen(filename, "r");

        //if (data == NULL) {
        //    printf("Ошибка открытия файла: %s\n", filename);
        //    continue; 
        //}

        char image_filename[100];
        sprintf(image_filename, "histogram_%03d.ppm", step);
        FILE *image = fopen(image_filename, "wb");

        fprintf(image, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

        int values[1000] = {0};
        int count = 0;
        int value;
        while (fscanf(data, "%d", &value) != EOF) {
            values[count++] = value;
        }

        fclose(data);

        int histogram[MAX_VALUE + 1] = {0};
        for (int i = 0; i < count; i++) {
            histogram[values[i]]++;
        }

        for (int y = HEIGHT - 1; y >= 0; y--) {
            for (int x = 0; x < WIDTH; x++) {
                int value = 255;
                if (x / BAR_WIDTH < MAX_VALUE && y < HEIGHT - (histogram[x / BAR_WIDTH] * HEIGHT / MAX_VALUE)) {
                    value = 0;
                }

                fprintf(image, "%d %d %d ", value, value, value);
            }
        }

        fclose(image);
    }

    return 0;
}
