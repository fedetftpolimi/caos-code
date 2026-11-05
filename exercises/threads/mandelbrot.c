#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <pthread.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000
#define NUM_THREADS 8

typedef struct {
    int start_row;
    int end_row;
    int (*result)[WIDTH];
} ThreadData;

void *compute_mandelbrot(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    for (int row = data->start_row; row < data->end_row; ++row) {
        for (int col = 0; col < WIDTH; ++col) {
            double x0 = -2.0 + (3.0 * col / WIDTH);
            double y0 = -1.5 + (3.0 * row / HEIGHT);

            double complex z = 0 + 0 * I;
            double complex c = x0 + y0 * I;

            int iter = 0;
            while (cabs(z) <= 2.0 && iter < MAX_ITER) {
                z = z * z + c;
                ++iter;
            }
            data->result[row][col] = iter;
        }
    }
    return NULL;
}

int main() {
    int result[HEIGHT][WIDTH];
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    int rows_per_thread = HEIGHT / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = (i + 1) * rows_per_thread;
        thread_data[i].result = result;

        pthread_create(&threads[i], NULL, compute_mandelbrot, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    FILE *outFile = fopen("mandelbrot.ppm", "w");
    fprintf(outFile, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int row = 0; row < HEIGHT; ++row) {
        for (int col = 0; col < WIDTH; ++col) {
            int color = (255 * result[row][col]) / MAX_ITER;
            fprintf(outFile, "%d %d %d ", color, color, color);
        }
        fprintf(outFile, "\n");
    }
    fclose(outFile);

    return 0;
}

