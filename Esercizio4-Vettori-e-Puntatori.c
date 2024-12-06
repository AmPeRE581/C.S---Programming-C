#include <stdio.h>
#include <limits.h>

struct nodo{
    int info;
    struct nodo *next;
};

int trovaIndiceMassimo(struct nodo *vettore[], int dimensione){
    if(dimensione == 0){
        return 0; /*Nessuna lista, restituisco 0*/
    }

    int indiceMax = 0; /*Per memorizzare l'indice della lista con il massimo*/
    int valoreMassimo = INT_MIN; /*Valore massimo inizializzato al minimo possibile*/

    for(int i=0; i<dimensione; i++){
        struct nodo *corrente = vettore[i];
        while(corrente != NULL){
            if(corrente ->info > valoreMassimo){
                valoreMassimo = corrente->info;
                indiceMax =i;
            }
            corrente =corrente->next; /*Avanza al prossimo nodo*/
        }
    }

    /*Se tutte le liste sono vuote, valoreMassimo rimarrà INT_MIN*/
    if(valoreMassimo == INT_MIN){
        return 0; /*Restituisce 0 se tutte le liste sono vuote*/
    }

    return indiceMax;
}