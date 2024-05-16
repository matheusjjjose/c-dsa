#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int mpow(int element, int base);
void initialize_array(int *array, int size);
int get_arithmetic_mean(int *array, int size);
double get_standard_deviation(int *array, int arithmetic_mean, int size);

int main() {

    srand(time(NULL));
    int size = 10;
    int *array = (int *) calloc(size, sizeof(int));
    initialize_array(array, size);

    float arithmetic_mean = get_arithmetic_mean(array, size);
    float sd = get_standard_deviation(array, arithmetic_mean, size);

    printf("Standard deviation: %.2f\n", sd);

    free(array);
    return 0;
}

void initialize_array(int *array, int size) {

    for (int i=0; i < size; i++) {
        int number = rand() % 1000;
        *(array + i) = number;
    }
}

int get_arithmetic_mean(int *array, int size) {

    int sum = 0;
    for (int i=0; i<size; i++) {
        sum += array[i];
    }

    int arithmetic_mean = sum / size;
    return arithmetic_mean;
}

double get_standard_deviation(int *array, int arithmetic_mean, int size) {

    double error_sum = 0.0;
    for (int i=0; i < size; i++) {

        int res = pow((array[i] - arithmetic_mean), 2);
        error_sum += res;
    }

    double variance = error_sum / size;
    double standard_deviation = sqrt(variance);
    return standard_deviation;
}