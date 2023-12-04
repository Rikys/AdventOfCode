#include <stdio.h>
#define MAXLL 100 //Lunghezza massima di una riga (MAX Line Length)

int elabora(char* line);
size_t strlen(char* line);
int find_digit(char* line, int direction);

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
    int r = 0;
    int tmp = 0;

    //'--->'
    r += find_digit(line, 0);
    
    //'<---'
    r += find_digit(line, 1);

    return r;
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



int find_digit(char* line, int direction) {
    int len = strlen(line);
    char digits[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char numbers[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    //0 = '--->', 1 = '<---'
    if (!direction) {
        //Scorriamo la stringa di input
        for (int i = 0; i < len; i++) {
            //Scorriamo tra le cifre
            for (int j = 0; j < 10; j++) {
                //Controlliamo se il carattere corrisponde a una cifra
                if (line[i] == digits[j]) return j * 10;
            }
            //Scorriamo tra i numeri
            for (int j = 0; j < 10; j++) {
                //Calcoliamo il numero di caratteri della parola
                int jlen = strlen(numbers[j]);
                int match = 0;
                //Scorriamo per controllare che la parola corrisponda lettera per lettera
                for (int k = 0; k < jlen ; k++) {
                    if (line[i + k] == numbers[j][k]) match++;
                    if (match == jlen) return j * 10;
                }
            }
        }
    }else{
        //Scorriamo la stringa di input
        for (int i = len; i >= 0; i--) {
            //Scorriamo tra le cifre
            for (int j = 0; j < 10; j++) {
                //Controlliamo se il carattere corrisponde a una cifra
                if (line[i] == digits[j]) return j;
            }
            for (int j = 0; j < 10; j++) {
                //Calcoliamo il numero di caratteri della parola
                int jlen = strlen(numbers[j]);
                int match = 0;
                //Scorriamo per controllare che la parola corrisponda lettera per lettera
                for (int k = jlen; k >= 0; k--) {
                    if (line[i - jlen + k] == numbers[j][k]) match++;
                    if (match == jlen) return j;
                }
            }
        }
    }
    return 0;
}