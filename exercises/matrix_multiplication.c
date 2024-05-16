#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void allocate_memory(int **matrix, int n_rows, int n_cols);
void initialize_matrix(int **matrix, int n_rows, int n_cols);
void free_memory(int **matrix, int n_rows, int n_cols);
void print(int **matrix, int n_rows, int n_cols);
int** multiply_matrix(int **matrix_a, 
int ma_rows, 
int ma_cols, 
int **matrix_b,
int mb_rows,
int mb_cols);

int main() {

    int na_rows = 2;
    int na_cols = 2;
    int nb_rows = 2;
    int nb_cols = 2;
    int **mtx_a = (int **) calloc(na_rows, sizeof(int *));
    int **mtx_b = (int **) calloc(nb_rows, sizeof(int *));

    initialize_matrix(mtx_a, na_rows, na_cols);
    initialize_matrix(mtx_b, nb_rows, nb_cols);

    printf("Matrix A\n");
    print(mtx_a, na_rows, na_cols);

    printf("Matrix B\n");
    print(mtx_b, nb_rows, nb_cols);

    printf("Matrix R\n");
    int **matrix_result = multiply_matrix(
        mtx_a, 
        na_rows, 
        na_cols, 
        mtx_b, 
        nb_rows, 
        nb_cols
    );

    print(matrix_result, na_rows, nb_cols);

    free_memory(mtx_a, na_rows, na_cols);
    free_memory(mtx_b, nb_rows, nb_cols);
    return 0;
}

void allocate_memory(int **matrix, int n_rows, int n_cols) {

    for (int row = 0; row < n_rows; row++) {

        matrix[row] = (int *) calloc(n_cols, sizeof(int));
    }
}

void initialize_matrix(int **matrix, int n_rows, int n_cols) {

    allocate_memory(matrix, n_rows, n_cols);

    for (int row=0; row < n_rows; row++) {

        for (int col=0; col < n_cols; col++) {

            int number = rand() % 10;
            matrix[row][col] = number;
        }
    }
}

int** multiply_matrix(int **matrix_a, 
                      int ma_rows,
                      int ma_cols,
                      int **matrix_b,
                      int mb_rows, 
                      int mb_cols) {
    int **matrix_result = (int **) calloc(ma_rows, sizeof(int *));
    allocate_memory(matrix_result, ma_rows, mb_cols);

    for (int x = 0; x < ma_rows; x++)
    {
        for (int y = 0; y < mb_cols; y++) {

            int sum = 0;
            for (int z =0; z < ma_cols; z++) {
                int res = matrix_a[x][z] * matrix_b[z][y];
                sum += res;
            }
            matrix_result[x][y] = sum;
        }
    }
    

    return matrix_result;
}

void free_memory(int **matrix, int n_rows, int n_cols) {

    for (int row=0; row < n_rows; row++) {
        free(matrix[row]);
    }
    free(matrix);
}


void print(int **matrix, int n_rows, int n_cols) {

    for (int row=0; row < n_rows; row++) {

        for (int col=0; col<n_cols; col++) {

            printf("[%d] ", matrix[row][col]);
        }
        printf("\n");
    }
}