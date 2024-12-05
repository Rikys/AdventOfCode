#include <stdio.h>
#include <stdlib.h>

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

    //Leggi una riga e interpretala come due interi
    while ((c = fgetc(input)) != EOF) {

        if (c != 'm') continue;

        if (fgetc(input) != 'u') continue;

        if (fgetc(input) != 'l') continue;

        if (fgetc(input) != '(') continue;

        int x, y;

        if (fscanf(input, "%d", &x) != 1) continue;

        if (fgetc(input) != ',') continue;

        if (fscanf(input, "%d", &y) != 1) continue;

        if (fgetc(input) != ')') continue;

        sum += (x * y);

    }

    printf("Sum: %d", sum);

    fclose(input);

}