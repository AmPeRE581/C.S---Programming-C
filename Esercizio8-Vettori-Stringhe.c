#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trasforma_vettore(char **vettore, size_t dimensione){
    for(size_t i=0; i<dimensione; i++){
        size_t len = strlen(vettore[i]);
        if(len<2){
            continue; /*Ignora stringhe con meno di due caratteri*/
        }

        /*Ottieni le ultime due lettere di 'vettore[i]'*/
        char last_two[3];
        last_two[0] = vettore[i][len -2];
        last_two[1] = vettore[i][len-1];
        last_two[2] = '\0';

        /*Cerca la prima stringa seguente che inizi con 'last_two'*/
        for(size_t j=i+1; j<dimensione; j++){
            if(strncmp(vettore[j], last_two, 2)==0){
                /*Trova la lunghezza della nuova stringa*/
                size_t new_len =len+strlen(vettore[j])-2;

                /*Alloca memoria per la nuova stringa*/
                char *nuova_stringa =(char *)malloc((new_len+1)*sizeof(char));
                if(nuova_stringa == NULL){
                    perror("Errore di allocazione memoria");
                    exit(EXIT_FAILURE);
                }

                /*Combina 'vettore[i]' e 'vettore[j]' evitando di ripetere le ultime due lettere*/
                strncpy(nuova_stringa, vettore[i], len-2); /*Copia senza le ultime due lettere*/
                strcpy(nuova_stringa + len-2, vettore[j]);

                /*Sostituisci la stringa originale*/
                free(vettore[i]);
                vettore[i] = nuova_stringa;
                break; /*Modifica effettuata, passa alla stringa successiva*/
            }
        }
    }
}

int main(){
    /*Esempio di vettore di stringhe*/
    char *vettore[] = {
        strdup("casa"),
        strdup("postino"),
        strdup("sasso"),
        strdup("osteria"),
        strdup("salvia"),
        strdup("notare"),
        strdup("renna")

    };

    size_t dimensione = sizeof(vettore) / sizeof(vettore[0]);

    /*Trasformazione del vettore*/
    trasforma_vettore(vettore, dimensione);

    /*Stampa il vettore trasformato*/
    printf("Vettore trasformato:\n");
    for(size_t i=0: i<dimensione; i++){
        printf("%s\n", vettore[i]);
        free(vettore[i]); /*Libera la memoria di ogni stringa*/
    }

    return 0;
}