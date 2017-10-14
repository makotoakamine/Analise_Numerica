//Modificar o trecho da multiplicacao
//Otimizar levando em conta que a matriz diagonal nao precisa
//ser invertida.
//Fazer uma matriz esparsa para calcular os termo dependentes.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BasicFunc.h"

void main(){
    float **M;
    float *V;
    float *MV_temp;
    float *VV;
    float **X;
    float **D;
    float **R;
    int i = 0;
    int j = 1;
    int n;
    
    
    double acc=0;
    clock_t t1, t2;
    //Inicializacao da Matriz
    scanf("%d",&n);
    M = allocM(n);
    fillM(M,n);
    V = allocV(n);
    fillV(V,n);
    MV_temp = allocV(n);
    VV = allocV(n);
    X = (float **)malloc(2*sizeof(float *)); 
    X[0] = allocV(n);
    X[1] = allocV(n);
    zeroFyV(X[0],n);
    zeroFyV(X[1],n);
    D = allocM(n);
    R = allocM(n);
    stripDR(M,D,R,n);
    t1 = clock();
    //trecho a ser cronometrado
    D = diagInv(D,n);
    for(i=0;i<100;i++){
        printM(R,n);
        printV(X[i&1],n);
        MV_temp = scalarMultMV(MV_temp,R,X[i&1],n);
        printV(MV_temp,n);
        VV = subVV(VV,V,MV_temp,n);
        printV(VV,n);
        X[(i+1)&1] = scalarMultMV(X[i&1],D,VV,n);
        printf("solucao corrente:\n");
        printV(X[(i+1)&1],n);
        printf("\n");
    }
    
    
    t2 = clock();
    acc += (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("Tempo(s): %.6f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    printf("Vetor solucao: \n");
    printV(X[i&1],n);
    printf("\n");
}