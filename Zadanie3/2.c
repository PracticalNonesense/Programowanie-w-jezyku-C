#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **createRandomMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Błąd alokacji pamięci dla wierszy macierzy.\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Błąd alokacji pamięci dla kolumn wiersza %d.\n", i);
            exit(1);
        }
    }


    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    return matrix;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix); 
}

int main() {
    int rows, cols;

    printf("Podaj liczbę wierszy macierzy: ");
    scanf("%d", &rows);
    printf("Podaj liczbę kolumn macierzy: ");
    scanf("%d", &cols);

    int **matrix = createRandomMatrix(rows, cols);

    printMatrix(matrix, rows, cols);

    freeMatrix(matrix, rows);

    return 0;
}
