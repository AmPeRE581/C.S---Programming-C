#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 21 /*Massima lunghezza del nome (20 caratteri + terminatore)*/

struct elem {
    char *nome;
    int eta;
};

/*Funzione per creare e popolare il vettore di studenti*/
struct elem* creaClasse(int numStudenti) {
    if (numStudenti <= 0) {
        return NULL; /*Se il numero di studenti è 0 o negativo, restituisci NULL*/
    }

    struct elem *classe = (struct elem *)malloc(numStudenti * sizeof(struct elem));
    if (classe == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return NULL;
    }

    for (int i = 0; i < numStudenti; i++) {
        classe[i].nome = (char *)malloc(MAX_NOME * sizeof(char));
        if (classe[i].nome == NULL) {
            printf("Errore nell'allocazione della memoria per il nome dello studente %d.\n", i + 1);

            for (int j = 0; j < i; j++) {
                free(classe[j].nome);
            }

            free(classe);
            return NULL;
        }

        printf("Inserisci il nome dello studente %d: ", i + 1);
        scanf("%20s", classe[i].nome);
        printf("Inserisci l'età dello studente %d: ", i + 1);
        scanf("%d", &classe[i].eta);
    }

    return classe;
}

/*Funzione per liberare la memoria della classe*/
void liberaClasse(struct elem *classe, int numStudenti) {
    for (int i = 0; i < numStudenti; i++) {
        free(classe[i].nome);
    }

    free(classe);
}

int main() {
    int numStudenti;

    printf("Quanti studenti vuoi inserire? ");
    while (scanf("%d", &numStudenti) != 1 || numStudenti <= 0) {
        printf("Inserisci un numero valido di studenti: ");
        while (getchar() != '\n'); // Pulisci il buffer di input
    }

    struct elem *classe = creaClasse(numStudenti);
    if (classe == NULL) {
        printf("Impossibile creare la classe.\n");
        return 1;
    }

    printf("\nDati degli studenti:\n");
    for (int i = 0; i < numStudenti; i++) {
        printf("Studente %d: Nome: %s, Età: %d\n", i + 1, classe[i].nome, classe[i].eta);
    }

    liberaClasse(classe, numStudenti);

    return 0;
}