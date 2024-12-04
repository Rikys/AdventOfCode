#include <stdio.h>
#include <stdlib.h>
#define MAXLL 25 //Lunghezza massima di una riga (MAX Line Length)

int scan(int n[]) {

    for (int i = 1; i < 8; i++) {

        if (n[i] == -1) break;

        printf("%d %d   ", n[i-1], n[i]);
            
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

    printf("safe");

    return 1;
    
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

        safe += scan(n);

        printf("\n");

    }

    printf("Safe: %d", safe);

    fclose(input);

}