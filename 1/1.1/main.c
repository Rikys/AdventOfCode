#include <stdio.h>
#define MAXLL 100 //Lunghezza massima di una riga (MAX Line Length)

int elabora(char* line);
int is_digit(char c);
size_t strlen(char* line);
int convert_digit(char c);

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

    //Buffer di somma
    int calibration_sum = 0;

    //Elaboriamo tutto il file linea per linea
    while (fgets(line, MAXLL, input) != NULL) {
        calibration_sum += elabora(line);
    }
    
    //Risultato
    printf("La somma dei numeri di calibrazione è: %d\n", calibration_sum);

    //Chiudiamo il file di input
    fclose(input);

    return 0;
}



int elabora(char* line) {
    int len = strlen(line);
    int r = 0;

    //Scorriamo da sinistra a destra fino a trovare una cifra '--->'
    for (int i = 0; i < len; i++) {
        if (is_digit(line[i])) {
            //Moltiplichiamo per 10 per spostare la cifra a sinistra (!)
            r += convert_digit(line[i]) * 10;
            break;
        }
    }
    //Scorriamo al contrario '<---'
    for (int i = len; i >= 0; i--) {
        //printf("i: %i c: %c   ", i, line[i]);
        if (is_digit(line[i])) {
            r += convert_digit(line[i]);
            break;
        }
    }

    return r;
}



int is_digit(char c) {
    //Array con tutte le cifre
    char numeri[10] = {'0','1','2','3','4','5','6','7','8','9'};

    //Scorriamo l'array
    for (int i = 0; i < 10; i++) {
        if (c == numeri[i]) {
            return 1;
        }
    }
    return 0;
}



size_t strlen(char* line) {
    //Size_t è un tipo di dato che rappresenta la dimensione di un oggetto
    size_t len = 0;
    //Scorriamo la stringa fino a trovare \0 contando quanti caratteri ci sono
    while (line[len] != '\0') {
        len++;
    }
    return len;
}



int convert_digit(char c) {
    //Array con tutte le cifre
    char numeri[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int r = 0;
    //Scorriamo l'array fino a trovare la cifra corrispondente
    while (c != numeri[r]) {
        r++;
    }
    return r;
}