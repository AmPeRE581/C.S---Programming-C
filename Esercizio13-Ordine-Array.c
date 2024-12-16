/*Esercizio1: Scrivere un programma C che genera in ingresso due array ordinati e li stampa a video.
Successivamente il programma deve fondere i due array in un solo array ordinato e stampare l'array ottenuto a video.
Implementare infine una funzione che verifica se un array è ordinato*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*Funzione per verificare se un array è ordinato*/
bool isSorted(int* array, int size){
    for(int i=1; i<size; i++){
        if(array[i-1]>array[i]){
            return false;
        }
    }
    return true;
}

/*Funzione per fondere due array ordinati*/
int* mergeSortedArrays(int* array1, int size1, int* array2, int size2, int* mergedSize){
    *mergedSize=size1+size2;
    int* mergedArray = (int*)malloc((*mergedSize)*sizeof(int));
    if(mergedArray == NULL){
        fprintf(stderr, "Errore di allocazione della memoria");
        exit(1);
    }

    int i=0; j=0; k=0;
    while(i<size1 && j<size2){
        if(array1[]<=array2[j]){
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }

    while(i<size1){
        mergedArray[k++] = array1[i++];
    }

    while(j<size2){
        mergedArray[k++] = array2[i++];
    }

    return mergedArray;
}

int main(){
    /*Generazione di due array ordinati*/
    int array1[]= {1,3,5,7,9};
    int size1 = sizeof(array1) / sizeof(array1[0]);


    int array2[] = {2,4,6,8,10};
    int size2 = sizeof(array2) / sizeof(array2[0]);

    /*Stampa degli array originali*/
    printf("Array1: ");
    for(int i=0; i<size1; i++){
        printf("%d", array1[i]);
    }
    printf("\n");

    printf("Array2: ");
    for(int i=0; i<size2; i++){
        printf("%d", array2[i]);
    }

    printf("\n");

    /*Fusione degli array*/
    int mergedSize;
    int* mergedArray = mergeSortedArrays(array1, size1, array2, size2, &mergedSize);

    /*Stampa dell'array fuso*/
    printf("Array fuso:");
    for(int i=0; i<mergedSize; i++){
        printf("%d", mergedArray[i]);
    }

    printf("\n");
    
    /*Verifica se l'array fuso è ordinato*/
    if(isSorted(mergedArray, mergedSize)){
        printf("L'array fuso è ordinato.\n");
    } else {
        printf("L'array fuso non è ordinato.\n");
    }

    /*Libera la memoria allocata*/
    free(mergedArray);

    return 0;
}