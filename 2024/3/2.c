#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tryMul(char c, FILE* input) {

    if (c != 'm') return 0;

    if (fgetc(input) != 'u') {
        fseek(input, -1, SEEK_CUR);
        return 0;
    }

    if (fgetc(input) != 'l') {
        fseek(input, -2, SEEK_CUR);
        return 0;
    }

    if (fgetc(input) != '(') {
        fseek(input, -3, SEEK_CUR);
        return 0;
    }

    int x, y;

    if (fscanf(input, "%d", &x) != 1) {
        fseek(input, -4, SEEK_CUR);
        return 0;
    }

    if (fgetc(input) != ',') {
        fseek(input, -5, SEEK_CUR);
        return 0;
    }

    if (fscanf(input, "%d", &y) != 1) {
        fseek(input, -6, SEEK_CUR);
        return 0;
    }

    if (fgetc(input) != ')') {
        fseek(input, -7, SEEK_CUR);
        return 0;
    }

    return (x * y);


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
    char c;

    //Contatore validi
    int sum = 0;

    //Stato do/don't
    bool state = true;

    //Leggi una riga e interpretala come due interi
    while ((c = fgetc(input)) != EOF) {

        if (state) {

            sum += tryMul(c, input);
            
        }

        if (c != 'd') continue;

        if (fgetc(input) != 'o') continue;

        if (fgetc(input) != '(') fseek(input, -1, SEEK_CUR);

        if (fgetc(input) != ')') {
            fseek(input, -1, SEEK_CUR);
        }else{
            state = true;
            continue;
        }

        if (fgetc(input) != 'n') {
            fseek(input, -1, SEEK_CUR);
            continue;
        }

        if (fgetc(input) != '\'') {
            fseek(input, -2, SEEK_CUR);
            continue;
        }

        if (fgetc(input) != 't') {
            fseek(input, -3, SEEK_CUR);
            continue;
        }

        state = false;

    }

    printf("Sum: %d", sum);

    fclose(input);

}