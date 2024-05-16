#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int **matrix, int n_rows, int n_cols);
void allocate_matrix(int **matrix, int n_rows, int n_cols);
void initialize_matrix(int **matrix, int n_rows, int n_cols);
void destroy_matrix(int **matrix, int n_rows, int n_cols);
int** sum_matrix(int **matrix_a, int **matrix_b, int n_rows, int n_cols);

int main() {

    srand(time(NULL));
    int n_rows = 2;
    int n_cols = 2;
    int **matrix_a = (int **) malloc(n_rows * sizeof(int *));
    int **matrix_b = (int **) malloc(n_rows * sizeof(int *)); 

    initialize_matrix(matrix_a, n_rows, n_cols);
    initialize_matrix(matrix_b, n_rows, n_cols);

    printf("matrix A\n");
    print(matrix_a, n_rows, n_cols);

    printf("matrix B\n");
    print(matrix_b, n_rows, n_cols);

    int **matrix_result = sum_matrix(matrix_a, matrix_b, n_rows, n_cols);

    print(matrix_result, n_rows, n_cols);

    destroy_matrix(matrix_a, n_rows, n_cols);
    destroy_matrix(matrix_b, n_rows, n_cols);
    destroy_matrix(matrix_result, n_rows, n_cols);
    return 0;
}

void print(int **matrix, int n_rows, int n_cols) {

    for (int row = 0; row < n_rows; row++) {

        for (int col = 0; col < n_cols; col++) {

            printf("[%d]", matrix[row][col]);
        }
        printf("\n");
    }
}

void allocate_matrix(int **matrix, int n_rows, int n_cols) {

    for (int row=0; row < n_rows; row++) {
        matrix[row] = (int *) malloc(n_cols * sizeof(int));
    }

    printf("space allocated successfully\n");
}

void initialize_matrix(int **matrix, int n_rows, int n_cols) {

    allocate_matrix(matrix, n_rows, n_cols);

    for (int row=0; row < n_rows; row++) {
        for (int col=0; col<n_cols; col++) {

            int number = rand() % 5;
            matrix[row][col] = number;
        }
    }
}

int** sum_matrix(int **matrix_a, int **matrix_b, int n_rows, int n_cols) {

    int **matrix_result = (int **) malloc(n_rows * sizeof(int*));
    allocate_matrix(matrix_result, n_rows, n_cols);

    for (int row = 0; row < n_rows; row++) {
        for (int col=0; col<n_cols; col++) {
            matrix_result[row][col] = matrix_a[row][col] + matrix_b[row][col];
        }
    }

    return matrix_result;
}

void destroy_matrix(int **matrix, int n_rows, int n_cols) {

    for (int row=0; row < n_rows; row++) {
        free(matrix[row]);
    }

    free(matrix);
}