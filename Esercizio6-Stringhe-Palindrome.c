#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Funzione per controllare se una stringa è palindroma*/
int is_palindrome(const char *str){
    int left =0, right = strlen(str)-1;

    while(left<right){
        /*Ignora gli spazi bianchi*/
        while(left < right && isspace((unsigned char)str[left])){
            left++;
        }
        while(left < right && isspace((unsigned char)str[right])){
            right--;
        }
        /*Confronta i caratteri*/
        if(tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])){
            return 0; /*Non è palindroma*/
        }

        left++;
        right--;
    }

    return 1; /*E' palindroma*/
}

/*Funzione per trovare l'ultima stringa palindroma*/
char *find_last_palindrome(char **strings){
    char *last_palindrome = NULL;

    for(int i=0; strings[i][0] != '\0'; i++){
        if(is_palindrome(strings[i])){
            /*Libera la memoria precedente, se esistente*/
            if(last_palindrome != NULL){
                free(last_palindrome);
            }

            /*Copia la nuova stringa palindroma*/
            last_palindrome = malloc(strlen(strings[i])+1);
            if(last_palindrome == NULL){
                perror("Errore di allocazione memoria");
                exit(EXIT_FAILURE);
            }
            strcpy(last_palindrome, strings[i]);
        }
    }

    return last_palindrome;
}

int main(){
    /*Esempio di vettore di stringhe*/
    char *strings[] = {
        "aerea",
        "etna gigante",
        "non palindrome",
        "another one",
        "", /*Stringa vuota per terminare*/
    };

    char *result = find_last_palindrome(strings);

    if(result != NULL){
        printf("L'ultima stringa palindroma è: '%s'\n", result);
        free(result); /*Libera la memoria allocata*/
    } else {
        printf("Nessuna stringa palindroma trovata.\n");
    }

    return 0;
}