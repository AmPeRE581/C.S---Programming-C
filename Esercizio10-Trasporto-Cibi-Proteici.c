#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double bid; /*Offerta in milioni di euro*/
    double capacity; /*Capacità di trasporto in tonnellate*/
} Company;

/*Funzione per trovare l'indice della compagnia con l'offerta migliore*/
int find_best_bid(Company companies[], int n){
    int best_index =-1;
    double best_score =-1.0;

    for(int i=0; i<n; i++){
        double score = companies[i].capacity / companies[i].bid;
        if(score > best_score){
            best_score = score;
            best_index = i;
        }
    }

    return best_index;
}

int main(){
    int n;

    printf("Inserire il numero di compagnie che partecipano alla gara d'appalto (max %d): ", MAX_COMPANIES);
    scanf("%d", &n);

    if(n<=0 || n > MAX_COMPANIES){
        printf("Numero di compagnie non valido. Deve essere tra 1 e %d.\n", MAX_COMPANIES);
        return 1;
    }

    Company companies[MAX_COMPANIES];

    for(int i=0; i<n; i++){
        printf("\nInserire i dettagli della compagnia %d:\n", i+1);
        printf("Nome: ");
        /*Inserire lo scanf...*/
        printf("Offerta (in milioni di euro):");
        scanf("%lf", &companies[i].bid);
        printf("Capacità di trasporto (in tonnellate):");
        scanf("%lf", &companies[i].capacity);

        if(companies[i].bid <=0 || companies[i].capacity <=0){
            printf("Errore: Offerta e capacità devono essere valori positivi.\n");
            return 1;
        }

    }

    int best_index = find_best_bid(companies, n);
    if(best_index != -1){
        printf("\nLa compagnia vincitrice è: %s\n", companies[best_index].name);
        printf("Offerta: %.2f milioni di euro\n", companies[best_index].bid);
        printf("Capacità di trasporto: %.2f tonnellate\n", companies[best_index].capacity);
    } else {
        printf("\nNon è stato possibile determinare un vincitore.\n");
    }

    return 0;
}