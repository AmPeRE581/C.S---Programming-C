/*Verificare il programma, e comprendere cosa lo stesso stampi quando viene avviato*/

#include <stdio.h>
#define L 7

int N=L;
void P(char* VET[], int DIM);

int main(){
    char* M[L] = {"pippo", "pluto", "paperino", "qui", "quo", "qua", "minnie"};
    int i;

    P(M, L-2);
    for(i= L-1; i-->0;){
        printf("%s\n", * (M+i));
        return 0;
    }

    void P(char* VET[], int DIM){
        int i;
        N++;
        for(i=0; i<DIM-1; i=i+2){
            strcpy(VET[i], VET[i+1]);
            return;
        }
    }
}

/*Il programma in questione stamperà... qua, quo, qui, qui, pluto, pluto*/