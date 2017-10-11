#include <stdio.h>
#include <stdlib.h>


float** allocM(int n); // Aloca memoria para Matriz de dimensao n, nao inicializa
float* allocV(int n); // Aloca memoria para Matriz de dimensao n, nao inicializa

void fillM(float **M, int n); // Inicializa valores da Matriz M
void fillV(float *V, int n); // Inicializa valores da Matriz M
void zeroFyM(float **M, int n); // Inicializa os valores da Matriz com 0
void zeroFyV(float *V, int n); // Inicializa os valores do Vetor com 0
    
    
void printM(float **M, int n); // printa a Matriz M
void printV(float *V, int n); // print o vetor V


float** scalarMultM(float lambda, float **M, int n); // Multiplicacao Matriz por Escalar
float* scalarMultV(float lambda, float *V, int n); // Multiplicacao Vetor por Escalar
float* scalarMultMV(float **M, float *V, int n); // Multiplicacao Matriz x Vetor

float** matrixMult(float **M, float **N, int n); //Multiplicacao entre Matrizes nxn

float** upperTriangularFy(float **M, int n); // Retorna uma Matriz triangular superior relacionado a Matriz M


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

void fillV(float *V, int n){
    int i = 0;
    for(i=0;i<n;i++){
            scanf("%f",&V[i]);
    }
}

void zeroFyM(float **M, int n){
    int i = 0;
    int j = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M[i][j] = 0;
        }
    }
}


void zeroFyV(float *V, int n){
    int i = 0;
    for(i=0;i<n;i++){
            V[i] = 0;
        }
}

void identityFyM(float **M, int n){
    int i = 0;
    int j = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                M[i][i] = 1;
            }
            else{
                M[i][j] = 0;
            }
        }
    }
}

void printM(float **M, int n){
    int i = 0;
    int j = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%f\t",M[i][j]);
        }
        printf("\n");
    }
}

void printV(float *V, int n){
    int i = 0;
    for(i=0;i<n;i++){
            printf("%f\t",V[i]);
    }
    printf("\n");
}

float** scalarMultM(float lambda, float **M, int n){
   int i = 0;
   int j = 0;
   for(i=0;i<n;i++){
       for(j=0;j<n;j++){
           M[i][j] = lambda*M[i][j];
       }
   }
   return M;
}

float* scalarMultV(float lambda, float *V, int n){
    int i = 0;
    for(i=0;i<n;i++){
        V[i] = lambda*V[i];
    }
    return V;
}

float* scalarMultMV(float **M, float *V, int n){
    int i;
    int j;
    float *MV;
    MV = allocV(n);
    for(i=0;i<n;i++){
        MV[i] = 0;
        for(j=0;j<n;j++){
            MV[i] += M[i][j] * V[j];
        }
    }
    return MV;
}
float** matrixMult(float **M, float **N, int n){
    int i = 0;
    int j = 0;
    int k = 0;
    float **MN;
    MN = allocM(n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            MN[i][j] = 0;
            for(k=0;k<n;k++){
                MN[i][j] += M[i][k]*N[k][j];
            }
        }
    }
}

float** upperTriangularFy(float **M, int n){
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
                }
            }
        }
        //--------------------------------
        for(j=i+1;j<n;j++){
           if(M[j][i] != 0){
               temp = -(M[j][i]/M[i][i]);
               M[j][i] = 0;
               for(k=1+i;k<n;k++){
                   M[j][k] += temp*M[i][k];
               }
           }
        }
    }
    return M;
}