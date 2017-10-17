#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "BasicFunc.h"


void fillValeat(float *V, int n){//preencher aleatoriamente o vetor mas não valida a matriz
    int i = 0;
    for(i=0;i<n;i++){
            V[i] = rand() %10;
            if(V[i] == 0) V[i] = V[i]+1;
    }
}

void fillMaleat(float **M, int n){ //preencher aleatoriamente a matriz mas não valida a matriz
    int i = 0;
    int j = 0;
    srand(time(NULL));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M[i][j] = rand() % 10;
            if (M[i][j] == 0) M[i][j] = M[i][j] + 1;
        }
    }
}

void matriztriangularsup(float **U, float **M, int n){ //matriz U triangular superior tal que Ut x U = A
    int k,j, i;
    float acRaiz=0, acRaiz2=0;

    for(k=0;k<n;k++){
      for(j=0;j<k;j++){
       acRaiz = acRaiz + pow((U[j][k]),2);
      }
      U[k][k] = sqrt((M[k][k] - acRaiz));
      acRaiz = 0;

        for(i=k+1;i<n;i++){

          for(j=0;j<k-1;j++){
            acRaiz2 = acRaiz2 + (U[j][k] * U[j][i]);
          }
          U[k][i] = (1/U[k][k]) * ((M[i][k] - acRaiz2));
          acRaiz2 = 0;
        }
   }
}

void resolvesistemas(float *V, float *W, float *X, float **U, int n){
  int i,j;

  for(i=0; i<n; i++){
    W[i] = V[i];
    for(j=0; j<i; j++){
      W[i] = W[i] - (U[j][i] * W[j]);
    }
    W[i] = W[i]/U[i][i];
  }

  for(i=(n-1); i>=0; i--){
    X[i] = W[i];
    for(j=(i+1); j<n; j++){
      X[i] = X[i] - (U[i][j] * X[j]);
    }
    X[i] = X[i]/U[i][i];
  }
}

void main() {
  int n;
  double acc=0;
  clock_t t1, t2;

  printf("valor de n: ");
  scanf("%d", &n);
  float **M = allocM(n);
  float **U = allocM(n);
  float *V = allocV(n);
  float *W = allocV(n);
  float *X = allocV(n);

  printf("Entre com a matriz:\n");
  //fillMaleat(M,n); Se for gerar aleatoriamente
  fillM(M,n);
  printf("Entre com o vetor:\n");
  //fillValeat(V,n); Se for gerar aleatoriamente
  fillV(V,n);


  t1=clock();
  matriztriangularsup(U,M,n);
  resolvesistemas(V,W,X,U,n);
  t2=clock();

  printM(M,n);
  printf("-----------------\n");
  printM(U,n);
  printf("-----------------\n");
  printf("Vetor X: \n");
  printV(X,n);
  printf("-----------------\n");
//  printV(W,n);
//  printf("-----------------\n");
  printf("Tempo(s): %.6f\n", (double)(t2-t1)/(CLOCKS_PER_SEC));
  acc += (double)(t2-t1)/CLOCKS_PER_SEC;
  printf("Tempo medio: %f\n", acc/n);

  free(M);
  free(U);
  free(V);
  free(W);
  free(X);

}