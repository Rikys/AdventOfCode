#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLL 25 //Lunghezza massima di una riga (MAX Line Length)

int scan(int n[]) {

    for (int i = 1; i < 8; i++) {

        if (n[i] == -1) break;
            
        if (abs(n[i-1] - n[i]) > 3) return 0;

        if (abs(n[i-1] == n[i])) return 0;

        //Se è il primo elemento determina la direzione
        if (i == 1) {

            if (n[i-1] - n[i] > 0) {

                //Se la differenza è positiva allora la direzione è decrescente
                n[0] = -1;

            }else{

                //Se la differenza è negativa allora la direzione è crescente
                n[0] = 1;

            }

            //Salta al prossimo elemento
            continue;

        }

        //Se non è il primo elemento controlla che la direzione sia la stessa

        if (n[i-1] - n[i] > 0 && n[0] == 1) return 0;

        if (n[i-1] - n[i] < 0 && n[0] == -1) return 0;

    }

    return 1;
    
}

int dampner(int n[]) {

    int c[9];

    memcpy(c, n, sizeof(int) * 9);

    //Prova se la sequenza è già valida
    if (scan(c)) return 1; 

    for (int i = 0; i < 8; i++) {

        //Ripristiniamo l'array
        memcpy(c, n, sizeof(int) * 9);

        if (c[i] == -1) break;

        for (int j = i; j < 8; j++) {

            if (c[j] == -1) break;

            c[j] = c[j+1];

        }

        if (scan(c)) return 1;

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

    //Contatore validi
    int safe = 0;

    //Leggi una riga e interpretala come due interi
    while (fgets(line, MAXLL, input) != NULL) {

        //Buffer numeri
        int n[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        
        sscanf(line, "%d %d %d %d %d %d %d %d", n, n+1, n+2, n+3, n+4, n+5, n+6, n+7);

        safe += dampner(n);

    }

    printf("Safe: %d", safe);

    fclose(input);

}