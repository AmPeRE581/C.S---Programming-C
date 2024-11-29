/*Una sequenza di 27 interi si dice perfetta se consiste di tre 1, tre 2, . . . , tre 9, posizionati in
modo che per ogni i 2 [1::9] ci sono esattamente i numeri tra le occorrenze successive di i.
Ad esempio, la sequenza
(1,9,1,2,1,8,2,4,6,2,7,9,4,5,8,6,3,4,7,5,3,9,6,8,3,5,7)
`e perfetta. 
Si scriva una funzione C che prende come parametro un vettore di 27 interi e
restituisce 1 se il vettore contiene una sequenza perfetta e 0 altrimenti.*/

#include <stdio.h>

/*Funzione per verificare se una sequenza è perfetta*/

int e_una_sequenza_perfetta(int sequenza[27]){
    int counts[10] ={0}; /*Conta le occorrenze di ogni numero da 1 a 9*/
    int positions[10][3] ={{0}}; /*Posizioni delle tre occorrenze di ogni numero*/

    /*Conta le occorrenze e salva le posizioni*/
    for(int i=0; i<27; i++){
        int num =sequenza[i];
        if(num <1 || num >9){
            return 0; /*Numero fuori dal range...valore non valido*/
        }
        if(counts[num] >= 3){
            return 0;
        }
        positions[num][counts[num]] =i;
        counts[num]++;
    }

    /*Controlla se ogni numero ha esattamente tre occorrenze e la distanza corretta*/
    for(int i=1; i<=9; i++){
        if(counts[i] != 3){
            return 0; /*Meno di tre occorrenze*/
        }
        if(positions[i][1] - positions[i][0] != i || positions[i][2] - positions[i][1] != i){
            return 0; /*Le distanze non corrispondono al valore del numero*/
        }
    }

    return 1;
}

int main(){
    int sequenza[27] = {1, 9, 1, 2, 1, 8, 2, 4, 6, 2, 7, 9, 4, 5, 8, 6, 3, 4, 7, 5, 3, 9, 6, 8, 3, 5, 7};

    if(e_una_sequenza_perfetta(sequenza)){
        printf("La sequenza è perfetta.\n");
    } else {
        printf("La sequenza non è perfetta.\n");
    }

    return 0;
}