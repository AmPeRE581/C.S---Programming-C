#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 21 /*Massima lunghezza del nome (20 caratteri + terminatore)*/

struct elem{
    char *nome;
    int eta;
};

/*Funzione per creare e popolare il vettore di studenti*/
struct elem* creaClasse(int numStudenti){
    if(numStudenti <=0){
        return NULL; /*Se il numero di studenti è 0 o negativo, restituisci NULL*/
    }

    /*Allocazione della memoria per il vettore di studenti*/
    struct elem *classe = (struct elem *)malloc(numStudenti * sizeof(struct elem));
    if(classe == NULL){
        printf("Errore nell'allocazione della memoria.\n");
        return NULL;
    }

    /*Lettura dei dati per ogni studente*/
    for(int i=0; i<numStudenti; i++){
        classe[i].nome = (char *)malloc(MAX_NOME *sizeof(char));
        if(classe[i].nome == NULL){
            printf("Errore nell'allocazione della memoria per il nome dello studente %d.\n",i+1);

            /*Libera la memoria già allocata in caso di errore*/
            for(int j=0; j<i; j++){
                free(classe[j].nome);
            }

            free(classe);
            return NULL;
        }

         /*Lettura del nome e dell'età dello studente*/
        printf("Inserisci il nome dello studente %d: ",i+1);
        scanf("%20s", classe[i].nome); /*Limita a 20 caratteri*/
        printf("Inserisci l'età dello studente %d: ",i+1);
        scanf("%d", &classe[i].eta);

return classe; /*Restituisca il puntatore al vettore*/
    }
}

/*Funzione per liberare la memoria della classe*/
void liberaClasse(struct elem *classe, int numStudenti){
    for(int i=0; i<numStudenti; i++){
        free(classe[i].nome);
    }

    free(classe);
}

int main(){
    int numStudenti;

    /*Lettura del numero di studenti*/
    printf("Quanti studenti vuoi inserire? ");
    scanf("%d", &numStudenti);

    /*Creazione della classe*/
    struct elem *classe = creaClasse(numStudenti);
    if(classe == NULL){
        printf("Impossibile creare la classe.\n");
        return 1;
    }

    /*Stampa dei dati degli studenti*/
    printf("\nDati degli studenti:\n");
    for(int i=0; i<numStudenti; i++){
        printf("Studente %d: Nome: %s, Età: %d\n", i+1, classe[i].nome, classe[i].eta);
    }

    /*Libera la memoria allocata*/
    liberaClasse(classe, numStudenti);

    return 0;
}