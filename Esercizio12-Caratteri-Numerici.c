#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Funzione per sommare due numeri rappresentanti come stringhe*/
char* sommaStringheNumeriche(const char* num1, const char* num2;){
    int len= strlen(num1); /*Lunghezza delle stringhe (si suppone siano uguali)*/

    /*Allocazione della stringa risultato (+1 per il terminatore '\0')*/
    char* risultato = (char*)malloc((len+1)*sizeof(char));
    if(risultato == NULL){
        fprintf(stderr, "Errore di allocazione della memoria\n");
        exit(1);
    }
    risultato[len] = '\0'; /*Terminatore della stringa*/

    /*Calcolo della somma cifra per cifra*/
    for(int i= len-1; i>=0; i--){
        int cifra1 = num1[i]-'0'; /*Converte il carattere in numero intero*/
        int cifra2 = num2[i]-'0'; /*Converte il carattere in numero intero*/
        int somma=cifra1+cifra2; /*Somma delle cifre*/

        risultato[i] = somma +'0'; /*Converte il risultato in carattere numerico*/
    }
    return risultato; /*Restituisce la stringa risultato*/
}

/*Funzione principale per testare la somma*/
int main(){
    /*Stringhe di input*/
    const char* num1 = "6795241135292314";
    const char* num2 = "2314332174634521";

    /*Calcolo della somma*/
    char* risultato = sommaStringheNumeriche(num1, num2);

    /*Stampa il risultato*/
    printf("Somma: %s\n", risultato);

    /*Libera la memoria allocata*/
    free(risultato);

    return 0;
}