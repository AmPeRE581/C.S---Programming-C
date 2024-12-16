#include <stdio.h>
#include <stdlib.H>

/*Definizione della struttura del nodo*/
struct nodo{
    int valore;
    struct nodo *next;
};

/*Funzione per modificare la lista secondo le specifiche*/
void modificaLista(struct nodo* head){
    if(head == NULL || head->next == NULL){
        /*Lista vuota o con un solo elemento: Nessuna modifica*/
        return;
    }

    /*Trovare la lunghezza della lista*/
    int count=0; 
    struct nodo* temp=head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    /*Allocare un array per memorizzare i valori della lista*/
    int* values = (int*)malloc(count *sizeof(int));
    temp = head;
    for(int i=0; i<count; i++){
        values[i] = temp->valore;
        temp= temp->next;
    }

    /*Calcolare i nuovi valori per la lista (escludendo il primo elemento)*/
    for(int i=count-1; i>0; i--){
        values[i] = values[i] * values[i-1];
    }
    /*Aggiorna la lista con i nuovi valori*/
    temp = head->next; /*Il primo nodo rimane invariato*/
    for(int i=1; i<count; i++){
        temp->valore = values[i];
        temp = temp->next;
    }

    free(values);
}

/*Funzione per creare un nuovo nodo*/
struct nodo* creaNodo(int valore){
    struct nodo* nuovoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuovoNodo->valore = valore;
    nuovoNodo->next = NULL;
    return nuovoNodo;
}

/*Funzione per stampare la lista*/
void stampaLista(struct nodo* head){
    struct nodo* temp = head;
    while(temp != NULL){
        printf("%d", temp->valore);
        temp = temp->next;
    }
    printf("\n");
}

/*Funzione principale per testare la modifica della lista*/
int main(){
    /*creazione della lista: 4->6->2->3->9*/
    struct nodo* head = creaNodo(4);
    head->next = creaNodo(6);
    head->next->next = creaNodo(2);
    head->next->next->next = creaNodo(3);
    head->next->next->next->next = creaNodo(9);

    printf("Lista Originale: ");
    stampaLista(head);

    /*Modifica la lista*/
    modificaLista(head);

    printf("Lista Modificata: ");
    stampaLista(head);

    /*Liberare la memoria*/
    struct nodo* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp); 
    }

    return 0;
}