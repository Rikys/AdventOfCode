#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXLL 142 //Lunghezza massima di una riga (MAX Line Length)

int tryFront(char matrix[MAXLL][MAXLL], int i, int j) {

    if (j + 3 > MAXLL) return 0;

    if (matrix[i][j + 1] == 'M' && matrix[i][j + 2] == 'A' && matrix[i][j + 3] == 'S') {

        return 1;

    }

    return 0;

}

int tryBack(char matrix[MAXLL][MAXLL], int i, int j) {

    if (j - 3 < 0) return 0;

    if (matrix[i][j - 1] == 'M' && matrix[i][j - 2] == 'A' && matrix[i][j - 3] == 'S') {

        return 1;

    }

    return 0;

}

int tryUp(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i - 3 < 0) return 0;

    if (matrix[i - 1][j] == 'M' && matrix[i - 2][j] == 'A' && matrix[i - 3][j] == 'S') {

        return 1;

    }

    return 0;

}

int tryDown(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i + 3 > MAXLL) return 0;

    if (matrix[i + 1][j] == 'M' && matrix[i + 2][j] == 'A' && matrix[i + 3][j] == 'S') {

        return 1;

    }

    return 0;

}

int tryBackUp(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i - 3 < 0 || j - 3 < 0) return 0;

    if (matrix[i - 1][j - 1] == 'M' && matrix[i - 2][j - 2] == 'A' && matrix[i - 3][j - 3] == 'S') {

        return 1;

    }

    return 0;

}

int tryBackDown(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i + 3 > MAXLL || j - 3 < 0) return 0;

    if (matrix[i + 1][j - 1] == 'M' && matrix[i + 2][j - 2] == 'A' && matrix[i + 3][j - 3] == 'S') {

        return 1;

    }

    return 0;

}

int tryFrontUp(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i - 3 < 0 || j + 3 > MAXLL) return 0;

    if (matrix[i - 1][j + 1] == 'M' && matrix[i - 2][j + 2] == 'A' && matrix[i - 3][j + 3] == 'S') {

        return 1;

    }

    return 0;

}

int tryFrontDown(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i + 3 > MAXLL || j + 3 > MAXLL) return 0;

    if (matrix[i + 1][j + 1] == 'M' && matrix[i + 2][j + 2] == 'A' && matrix[i + 3][j + 3] == 'S') {

        return 1;

    }

    return 0;

}

int main() {

    FILE* input;

    input = fopen("input.txt", "r");

    //Se il file non esiste
    if (input == NULL) {
        printf("Errore nell'apertura del file.");
        return 1;
    }

    //Buffer di lettura
    char line[MAXLL];

    //Contatore XMAS
    int sum = 0;

    //Buffer matrix
    char matrix[MAXLL][MAXLL];

    //Leggi una riga e interpretala come due interi
    for (int i = 0; fgets(line, MAXLL, input) != NULL; i++) {

        for (int j = 0; j < MAXLL; j++) {

            matrix[i][j] = line[j];

        }

    }


    for (int i = 0; i < MAXLL - 2; i++) {

        for (int j = 0; j < MAXLL - 2; j++) {

            if (matrix[i][j] == 'X') {

                sum += tryFront(matrix, i, j);
                sum += tryBack(matrix, i, j);
                sum += tryUp(matrix, i, j);
                sum += tryDown(matrix, i, j);
                sum += tryBackUp(matrix, i, j);
                sum += tryBackDown(matrix, i, j);
                sum += tryFrontUp(matrix, i, j);
                sum += tryFrontDown(matrix, i, j);

            }

        }

    }

    printf("sum: %d", sum);

    fclose(input);

}