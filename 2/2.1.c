#include <stdio.h>
#define MAXLL 200 //Lunghezza massima di una riga (MAX Line Length)

struct game{
    int red;
    int green;
    int blue;
    int game_id;
};

int elabora(char* line);
struct game parse_game(char* line);
int parse_digit(char c, int* reasult);
int parse_color(char c, int* result);
size_t strlen(char* line);
size_t intlen(int n);

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
    int possible_games_id_sum = 0;

    //Elaboriamo tutto il file linea per linea
    while (fgets(line, MAXLL, input) != NULL) {
        possible_games_id_sum += elabora(line);
    }
    
    //Risultato
    printf("La somma degli id delle partite possibili è: %d\n", possible_games_id_sum);

    //Chiudiamo il file di input
    fclose(input);

    return 0;
}



int elabora(char* line) {
    struct game d = {12, 13, 14};
    struct game g = parse_game(line);
    if (d.red < g.red || d.green < g.green || d.blue < g.blue) return 0;
    return g.game_id;
}



struct game parse_game(char* line) {
    
    struct game g = {0, 0, 0, 0};

    int stage = 0;
    int game_id_digit = 0;
    int color_value = 0;
    int color_value_digit = 0;

    //Salta 'Game '
    line += 5;

    //Scorrimento della linea
    for (int i = 0; i < strlen(line); i++) {

        //Parse del game_id
        if (stage == 0) {

            //Parse di tutte le cifre di game_id
            while (parse_digit(line[i], &game_id_digit)) {
                g.game_id = g.game_id * 10 + game_id_digit;
                i++;
            }
            
            //Salta ' '
            i += 1;
            
            stage++;

        //Parse del valore e del colore
        }else if (stage == 1) {

            //Parse di tutte le cifre di g.color
            while (parse_digit(line[i], &color_value_digit)) {
                color_value = color_value * 10 + color_value_digit;
                i++;
            }

            //Parse color (solo prima lettera, sufficiente)
            int color = 0;
            if (parse_color(line[i], &color)) {
                switch (color) {
                case 0: //red
                    if (g.red < color_value) g.red = color_value;
                    color_value = 0;
                    i += 3;
                    break;
                
                case 1: //green
                    if (g.green < color_value) g.green = color_value;
                    color_value = 0;
                    i += 5;
                    break;

                case 2: //blue
                    if (g.blue < color_value) g.blue = color_value;
                    color_value = 0;
                    i += 4;
                    break;
                
                default:
                    printf("Errore nel parsing del colore.\n");
                    break;
                }
            }
        }
        
    }
    return g;
    
}



int parse_digit(char c, int* result) {
    //Array con tutte le cifre
    char numeri[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int digits[10] = {0,1,2,3,4,5,6,7,8,9};

    //Scorriamo l'array
    for (int i = 0; i < 10; i++) {
        if (c == numeri[i]) {
            *result = digits[i];
            return 1;
        }
    }
    return 0;
}



int parse_color(char c, int* result) {
    //Array con tutte le cifre
    char* color[3] = {"red","green","blue"};

    //Scorriamo l'array
    for (int i = 0; i < 3; i++) {
        if (c == color[i][0]) {
            *result = i;
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



size_t intlen(int n) {
    //Size_t è un tipo di dato che rappresenta la dimensione di un oggetto
    size_t len = 0;
    //Dividiamo l'intero finchè non diventa 0 contando quante cifre ci sono
    do {
        n /= 10;
        ++len;
    } while (n != 0);
    return len;
}