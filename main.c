#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    
    int size = 10;
    int *array = (int *) calloc(size, sizeof(int));

    for (int i=0; i<size; i++) {
        array[i] = i * 10;
    }

    array = realloc(array, (2 + size) * sizeof(int));
    array[10] = 100;
    array[11] = 110;

    for (int i = 0; i < 12; i++) {
        printf("&x[%d] -> %p = [%d]\n", i, &array[i], array[i]);
    }

    free(array);
    return 0;
}