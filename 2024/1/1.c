#include <stdio.h>
#include <stdlib.h>
#define MAXLL 15 //Lunghezza massima di una riga (MAX Line Length)

//Funzione di confronto per qsort
int compare(const void *a, const void *b) {

    return (*(int *)a - *(int *)b);
    
}

int main() {

    FILE* input;

    input = fopen("input.txt", "r");

    //Se il file non esiste
    if (input == NULL) {
        printf("Errore nell'apertura del file.");
        return 1;
    }

    //Liste a e b
    int a[1000], b[1000];

    //Buffer di lettura
    char line[MAXLL];

    //Leggi una riga e interpretala come due interi
    for (int i = 0; i < 1000; i++) {
        
        fgets(line, MAXLL, input);

        sscanf(line, "%d %d", &a[i], &b[i]);

    }

    //Ordina le liste
    qsort(a, 1000, sizeof(int), compare);
    qsort(b, 1000, sizeof(int), compare);

    int totalDistance = 0;

    //Calcola la distanza tra ogni coppia di elementi e sommala
    for (int i = 0; i < 1000; i++) {

        totalDistance += abs( a[i] - b[i]);

    }

    printf("%d", totalDistance);

    fclose(input);

}