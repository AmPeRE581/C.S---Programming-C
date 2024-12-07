#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Funzione che rimuove tutte le occorrenze di un carattere da una stringa
* @param input La stringa di input
* @param to_remove Il carattere da rimuovere
* @return Una nuova stringa senza le occorrenze del carattere specificato
*         o NULL in caso di errore di allocazione della memoria
*/

char *remove_char(const char *input, char to_remove){
    if(input == NULL){
        return NULL;
    }

    /*Conta i caratteri che non corrispondono a 'to_remove'*/
    size_t count =0;
    for(size_t i=0; input[i] != '\0'; i++){
        if(input[i] != to_remove){
            count++;
        }
    }

    /*Alloca memoria per la stringa (incluso il terminatore nullo)*/
    char *result = (char *)malloc((count+1)*sizeof(char));
    if(result == NULL){
        perror("Errore di allocazione della memoria");
        return NULL;
    }

    /*Copia i caratteri diversi da 'to_remove' nella nuova stringa*/
    size_t j=0;
    for(size_t i=0; input[i] != '\0'; i++){
        if(input[i] != to_remove){
            result[j++] = input[i];
        }
    }
    /*Termina la stringa con il carattere nullo*/
    result[j] = '\0';

    return result;
}

int main(){
    /*Input di esempio*/
    const char *input = "tutta statistica"
    char to_remove = 't';

    /*Chiamata alla funzione*/
    char *output = remove_char(input, to_remove);
    if(output == NULL){
        printf("Errore durante l'elaborazione.\n");
        return 1;
    }

    /*Stampa il risultato*/
    printf("Stringa di partenza: '%s'\n", input);
    printf("Stringa senza '%c': '%s'\n", to_remove, output);

    /*Libera la memoria allocata*/
    free(output);

    return 0;
}