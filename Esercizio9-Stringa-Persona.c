#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Funzione per rimuovere spazi multipli all'inizio e alla fine della stringa e tra le parole*/
void normalize_string(char *str){
    char *src = str, *dst = str;
    int space =0;

    while(isspace((unsigned char)*src)){ /*Salta gli spazi iniziali*/
        scr++;
    }

    while(*src){
        if(isspace((unsigned char)*src)){
            if(!space){
                *dst++ = ''; /*Sostituisce spazi multipli con uno solo*/
                space=1;
            }
        } else {
            *dst++ = *src;
            space =0;
        }
        src++;
    }

    if(dst > str && isspace((unsigned char)*(dst-1))) /*Rimuove lo spazio finale*/
    dst--;

    *dst = '\0';
}

/*Funzione per costruire la stringa finale*/
char *build_full_name(const char *name_surname, const char *nickname){
    /*Copia delle stringhe di input per normalizzazione*/
    char name_copy[256], nickname_copy[256];
    strncpy(name_copy, name_surname, sizeof(name_copy)-1);
    strncpy(nickname_copy, nickname, sizeof(nickname_copy)-1);
    name_copy[255] = '\0';
    nickname_copy[255] = '\0';

    /*Normalizza le stringhe*/
    normalize_string(name_copy);
    normalize_string(nickname_copy);

    /*Trova il primo spazio nella stringa normalizzata per separare nome e cognome*/
    char *space_pos = strchr(name_copy, '');
    if(!space_pos){
        fprintf(stderr, "Errore: la stringa 'nome e cognome' non contiene un cognome valido.\n");
        return NULL;
    }

    /*Separa il nome dal cognome*/
    *space_pos = '\0';
    const char *name =name_copy;
    const char *surname =space_pos+1;

    /*Calcola la dimensione della stringa finale*/
    size_t result_len =strlen(name) + strlen(surname) +strlen(nickname_copy) +6; /*Spazi e parentesi*/

    /*Alloca la stringa finale*/
    char *result =malloc(result_len);
    if(!result){
        fprintf(stderr, "Errore: Allocazione memoria fallita.\n");
        return NULL;
    }

    /*Costruisce la stringa finale*/
    snprintf(result, result_len, "%s (%s) %s", name, nickname_copy, surname);

    return result;
}

int main(){
    /*Input di esempio*/
    const char *name_surname = "Bruce Springsteen";
    const char *nickname = "The Boss";

    /*Costruzione del nome completo*/
    char *full_name = build_full_name(name_surname, nickname);
    if(full_name){
        printf("Nome Completo: %s\n", full_name);
        free(full_name); /*Libera la memoria allocata*/
    }

    return 0;
}