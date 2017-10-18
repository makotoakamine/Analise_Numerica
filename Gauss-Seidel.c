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
    // float **X;
    float *X;
    float **L;
    float **U;
    int i = 0;
    int j = 1;
    int k = 0;
    int n;
    
    
    double acc=0;
    clock_t t1, t2;
    scanf("%d",&n);
    M = allocM(n);
    fillM(M,n);
    V = allocV(n);
    fillV(V,n);
    MV_temp = allocV(n);
    VV = allocV(n);
    X = allocV(n);
    zeroFyV(X,n);
    L = allocM(n);
    U = allocM(n);
    stripLU(M,L,U,n);
    t1 = clock();
    // printM(L,n);
    // printf("\n");
    // printM(U,n);
    
    // printf("\n");
    for(i=0;i<100;i++){
        MV_temp = scalarMultMV(MV_temp,U,X,n);
        VV = subVV(VV,V,MV_temp,n);
        X[0] = VV[0]/L[0][0];
        for(j=1;j<n;j++){
            X[j] = VV[j];
            for(k=0;k<j;k++){
                X[j] -= X[k]*L[j][k];
            }
            X[j] /= L[j][j];
        }
    }
    
    
    t2 = clock();
    acc += (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("Tempo(s): %.6f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    printV(X,n);
    printf("\n");
}



