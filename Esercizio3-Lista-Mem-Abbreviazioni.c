#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definizione della struttura*/
struct elem{
    char abbr[3]; /*Aggiunto spazio per il terminatore '\0'*/
    char *estesa;
    struct elem *next;
};

/*Funzione per gestire la lista*/
int gestisciLista(struct elem **head, const char *abbr, const char *estesa){
    struct elem *current  = *head;
    struct elem *prev = NULL;

    /*Scorriamo la lista per cercare l'abbreviazione*/
    while(current != NULL){
        if(strcmp(current->abbr, abbr)==0){
            if(strcmp(current->estesa, estesa)==0){
                return 0;
            } else {
                /*Aggiorna la parola estesa*/
                free(current->estesa); /*Libera la vecchia stringa*/
                current->estesa = strdup(estesa); /*Copia la nuova parola*/
                return 2;
            }
        }
        prev = current;
        current = current->next;
    }

    /*La coppia non è presente, aggiungiamo un nuovo record*/
    struct elem *newElem = (struct elem*)malloc(sizeof(struct elem));
    if(newElem == NULL){
        fprintf(stderr, "Errore di allocazione memoria\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newElem->abbr, abbr); /*copia l'abbreviazione*/
    newElem->estesa = strdup(estesa); /*Copia la parola estesa*/
    newElem->next = NULL;

    if(prev == NULL){
        /*Lista vuota*/
        *head = newElem;
    } else {
        /*Aggiungi in coda*/
        prev->next = newElem;
    }
    return 1; /*Coppia aggiunta*/
}

/*Funzione per stampare la lista (debug)*/
void stampaLista(struct elem *head){
    while(head != NULL){
        printf("Abbreviazione: %s, Estesa: %s\n", head->abbr, head->estesa);
        head = head->next;
    }
}

/*Funzione per liberare la lista*/
void liberaLista(struct elem *head){
    struct elem *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp->estesa);
        free(temp);
    }
}

/*Esempio di utilizzo*/
int main(){
    struct elem *head = NULL;

    printf("Caso 1: %d\n", gestisciLista(&head, "TO", "Torino"));
    printf("Caso 2: %d\n", gestisciLista(&head, "MI", "Milano"));
    printf("Caso 3: %d\n", gestisciLista(&head, "TO", "Torino"));
    printf("Caso 4: %d\n", gestisciLista(&head, "TO", "Torin"));

    stampaLista(head);

    liberaLista(head);
    return 0;
}