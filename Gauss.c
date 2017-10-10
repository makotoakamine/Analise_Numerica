#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BasicFunc.h"

float** lowerTriangularFy(float **M, int n); // Retorna uma Matriz triangular inferior relacionado a Matriz M


void main(){
    float **M;
    int i = 0;
    int n = 5;
    
    double acc=0;
    clock_t t1, t2;
    //Inicializacao da Matriz
    M = allocM(n);
    identityFyM(M,n);
    
    t1 = clock();
    //trecho a ser cronometrado
    
    
    t2 = clock();
    acc += (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("%.6f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    printM(scalarMultM(3,M,n),n);
}





float** lowerTriangularFy(float **M, int n){
    int i = 0;
    int j = 0;
    int k = 0;
    float temp = 0;
    for(i=0;i<n;i++){
        if(M[i][i] == 0){
            j=i+1;
            while(M[j][i] == 0 && j<n){
                j++;
            }
            if(j==n){
                printf("Erro , nao e' possivel triangularizar a matriz.\n");
            }
            else{ // Permutar linhha
                for(k=i;k<n;k++){
                    temp = M[i][k];
                    M[i][k] = M[j][k];
                    M[j][k] = temp;
                }
            }
        }
        for(j=i+1;i<n;j++){
           if(M[i][j] != 0){
               temp
           }
        }
    }
    return M;
}