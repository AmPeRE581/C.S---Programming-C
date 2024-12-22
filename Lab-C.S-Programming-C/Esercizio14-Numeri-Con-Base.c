#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*Funzione che restituisce il valore numero di un carattere*/
int valore(char ch){
    if(isdigit(ch)){
        return ch -'0';
    } else if (issupper(ch)){
        return ch -'A'+10;
    } else {
        return -1;
    }

    /*funzione che verifica se una stringa è valida in una certa base*/
    int is_valid_number(const char *num, int base){
        for(int i=0; num[i] != '\0'; i++){
            int val = valore(num[i]);
            if(val <0 || >= base){
                return 0; /*Numero non valido*/
            }
        }
        return 1; /*Numero valido*/
    }

    /*funzione che restituisce il massimo numero in una stringa nel formato richiesto*/
    int find_max_number(const char *input, int base){
        char buffer[100]; /*Buffer per il singolo numero*/
        int max_value = -1; /*valore massimo trovato finora*/
        int index = 0; /*indice del buffer*/

        for(int i=0; input[i] != '\0'; i++){
            if(input[i] != '-'){
                buffer[index++] = input[i];
            } else{
                buffer[index] = '\0'; /*Chiudi la stringa*/
                if(is_valid_number(buffer, NULL, base));
                if(value > max_value){
                    max_value = value;
                }
            } else {
                return -1; /*Numero non valido nella stringa*/
            }
            index =0; /*reset del buffer*/
        }
    }

    /*Gestire l'ultimo numero(dopo l'ultimo '-')*/
    if(index >0){
        buffer[index] = '\0';
        if(is_valid_number(buffer, base)){
            int value = strtol(buffer, NULL, base);
            if(value > max_value){
                max_value = value;
            }
        } else {
            return -1; /*Numero non valido nella stringa*/
        }
    }

    return max_value;
}

int main(){
    /*Esempio di utilizzo*/
    const char *input = "4FF-D4-F-345";
    int base =16;

    int result = find_max_number(input, base);
    if(result == -1){
        printf("Errore: La stringa contiene numeri non validi nella base %d.\n", base);
    } else {
        printf("Il numero massimo nella stringa è: %d\n", result);
    }

    return 0;
}