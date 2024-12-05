#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXLL 142 //Lunghezza massima di una riga (MAX Line Length)

int tryBackUp(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i - 1 < 0 || j  + 1 > MAXLL) return 0;

    if (matrix[i - 1][j - 1] == 'M' && matrix[i + 1][j + 1] == 'S') {

        return 1;

    }

    return 0;

}

int tryBackDown(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i + 1 > MAXLL || j + 1 > MAXLL) return 0;

    if (matrix[i + 1][j - 1] == 'M' && matrix[i - 1][j + 1] == 'S') {

        return 1;

    }

    return 0;

}

int tryFrontUp(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i - 1 < 0 || j - 1 < 0) return 0;

    if (matrix[i - 1][j + 1] == 'M' && matrix[i + 1][j - 1] == 'S') {

        return 1;

    }

    return 0;

}

int tryFrontDown(char matrix[MAXLL][MAXLL], int i, int j) {

    if (i + 1 > MAXLL || j - 1 < 0) return 0;

    if (matrix[i + 1][j + 1] == 'M' && matrix[i - 1][j - 1] == 'S') {

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

    //Contatore MAS
    int sum = 0;

    //Buffer matrix
    char matrix[MAXLL][MAXLL];

    //Leggi una riga e interpretala come due interi
    for (int i = 0; fgets(line, MAXLL, input) != NULL; i++) {

        for (int j = 0; j < MAXLL; j++) {

            matrix[i][j] = line[j];

        }

    }


    for (int i = 1; i < MAXLL - 2; i++) {

        for (int j = 1; j < MAXLL - 2; j++) {

            if (matrix[i][j] == 'A') {

                int subSum = 0;

                subSum += tryBackUp(matrix, i, j);
                subSum += tryBackDown(matrix, i, j);
                subSum += tryFrontUp(matrix, i, j);
                subSum += tryFrontDown(matrix, i, j);

                if (subSum == 2) sum++;

            }

        }

    }

    printf("sum: %d", sum);

    fclose(input);

}