#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BasicFunc.h"

void main(){
    float **M;
    float *V;
    float *X;
    float **D;
    float **R;
    int i = 0;
    int n;
    
    
    double acc=0;
    clock_t t1, t2;
    //Inicializacao da Matriz
    scanf("%d",&n);
    M = allocM(n);
    fillM(M,n);
    V = allocV(n);
    fillV(V,n);
    X = allocV(n);
    D = allocM(n);
    zeroFyM(D,n);
    R = allocM(n);
    zeroFyM(R,n);
    t1 = clock();
    //trecho a ser cronometrado
    D = diagInv(M,n);
    printM(D,n);
    t2 = clock();
    acc += (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("Tempo(s): %.6f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    printf("Matriz escalonada:\n");
    printf("Vetor coeficiente independente: \n");
    printf("Vetor solucao: \n");
    printf("\n");
}