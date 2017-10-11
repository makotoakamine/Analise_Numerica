#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BasicFunc.h"

void rowEl(float **M, float *V, int n); // escalona a matriz [MV] -M MX=V 
float* solveMXV(float **M, float *V, int n); // resolve o sistema escalonado triangular superior MX=V, retorna X

void main(){
    float **M;
    float *V;
    float *X;
    int i = 0;
    int n;
    
    
    double acc=0;
    clock_t t1, t2;
    //Inicializacao da Matriz
    scanf("%d",&n);
    M = allocM(n);
    V = allocV(n);
    X = allocV(n);
    fillM(M,n);
    fillV(V,n);
    t1 = clock();
    //trecho a ser cronometrado
    rowEl(M,V,n);
    X = solveMXV(M,V,n);
    t2 = clock();
    acc += (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("Tempo(s): %.6f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    printf("Matriz escalonada:\n");
    printM(upperTriangularFy(M,n),n);
    printf("Vetor coeficiente independente: \n");
    printV(V,n);
    printf("Vetor solucao: \n");
    printV(X,n);
    printf("\n");
}





void rowEl(float **M, float *V, int n){
    int i = 0;
    int j = 0;
    int k = 0;
    float temp = 0.00000;
    for(i=0;i<n-1;i++){
        if(M[i][i] == 0){ //Se pivo = 0
            j=i+1;
            while(M[j][i] == 0 && j<n){
                j++;
            }
            if(j==n){
                printf("Erro , nao e' possivel triangularizar a matriz.\n");
            }
            else{ //Trocar linha 
                for(k=i;k<n;k++){
                    temp = M[i][k];
                    M[i][k] = M[j][k];
                    M[j][k] = temp;
                    temp = V[i];
                    V[i] = V[j];
                    V[j] = temp;
                }
            }
        }
        //----------------------------
        for(j=i+1;j<n;j++){
           if(M[j][i] != 0){
               temp = -(M[j][i]/M[i][i]);
               M[j][i] = 0;
               for(k=1+i;k<n;k++){
                   M[j][k] += temp*M[i][k];
               }
               V[j] += temp*V[i];
           }
        }
    }
}




float* solveMXV(float **M, float *V, int n){
    int i = 0;
    int j = 0;
    float *X;
    X = allocV(n);
    X[n-1] = V[n-1]/M[n-1][n-1];
    for(i=2;i<=n;i++){
        X[n-i] = V[n-i];
        for(j=1;j<i;j++){
            X[n-i] -= M[n-i][n-j]*X[n-j];
        }
        X[n-i] /= M[n-i][n-i];
    }
    return X;
}