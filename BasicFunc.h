#include <stdio.h>
#include <stdlib.h>


float** allocM(int n); // Aloca memoria para matriz de dimensao n, nao inicializa
float* allocV(int n); // Aloca memoria para matriz de dimensao n, nao inicializa
void populateM(float **M, int n) // Inicializa valores da matriz M
void populateV(float *V, int n) // Inicializa valores da matriz M


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