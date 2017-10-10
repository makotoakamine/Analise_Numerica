#include <stdio.h>
#include <stdlib.h>


// float** allocM(int n);  Aloca memoria para matriz de dimensao n, nao inicializa
// float* allocV(int n);  Aloca memoria para matriz de dimensao n, nao inicializa
// void fillM(float **M, int n)  Inicializa valores da matriz M
// void fillV(float *V, int n)  Inicializa valores da matriz M


float** allocM(int n){
    float **M;
    int i = 0;
    M = (float **)malloc(n*sizeof(float *));
    for(i=0;i<n;i++){
        M[i] = (float *)malloc(n*sizeof(float));
    }
    return M;
}

float* allocV(int n){
    float *v;
    int i = 0;
    v = (float *)malloc(n*sizeof(float));
    return v;
}

void fillM(float **M, int n){
    int i = 0;
    int j = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%f",&M[i][j]);
        }
    }
}

void fillV(float **V, int n){
    int i = 0;
    for(i=0;i<n;i++){
            scanf("%f",&V[i]);
    }
}


void printM(float **M, int n){
    int i = 0;
    int j = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%f ",M[i][j]);
        }
        printf("\n");
    }
}


void printV(float **V, int n){
    int i = 0;
    for(i=0;i<n;i++){
            printf("%f ",V[i]);
    }
}