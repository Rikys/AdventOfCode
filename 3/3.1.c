#include <stdio.h>
#define MAXLL 142 //Lunghezza massima di una riga (MAX Line Length)

int elabora(char data[][]);
int parse_number(char data[][], int* number);
int has_adjacent(int number);

int main() {
    //Definiamo il file di input
    FILE* input;

    //Apriamo il file di input in lettura semplice
    input = fopen("input.txt", "r");

    //Controlliamo che il file sia stato aperto correttamente
    if (input == NULL) {
        printf("Errore nell'apertura del file.");
        return 1;
    }

    //Buffer di lettura
    char line[MAXLL];

    //Matrice di input
    char data[MAXLL - 1][MAXLL - 1];

    //Buffer di somma
    int possible_games_power_sum = 0;

    //Riempiamo la matrice linea per linea
    for (int i = 0; fgets(line, MAXLL, input) != NULL; i++) {
        for (int j = 0; j < MAXLL; j++) {
            data[i][j] = line[j];
        }
    }
    
    //Elaboriamo la matrice
    possible_games_power_sum += elabora(data);

    //Risultato
    printf("La somma della forza delle partite possibili è: %d\n", possible_games_power_sum);

    //Chiudiamo il file di input
    fclose(input);

    return 0;
}



int elabora(char data[][]) {
    int result = 0;
    int* number = 0;
    while (parse_number(data, &number) != NULL) {
        if (has_adjacent(number)) result += *number ;    
    }
    return result;
}