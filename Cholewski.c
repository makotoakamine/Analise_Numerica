#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "BasicFunc.h"


void fillValeat(double *V, int n){//preencher aleatoriamente o vetor mas não valida a matriz
    int i = 0;
    for(i=0;i<n;i++){
            V[i] = rand() %10;
            if(V[i] == 0) V[i] = V[i]+1;
    }
}

void fillMaleat(double **M, int n){ //preencher aleatoriamente a matriz mas não valida a matriz
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

void matriztriangularsup(double **U, double **M, int n){ //matriz U triangular superior tal que Ut x U = A
    int k,j, i;
    double acRaiz=0, acRaiz2=0;

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

void resolvesistemas(double *V, double *W, double *X, double **U, int n){
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

void main(int argc, char *argv[]) {
  int n;
  double acc=0;
  clock_t t1, t2;

  // printf("valor de n: ");
  scanf("%d", &n);
  double **M = allocM(n);
  double **U = allocM(n);
  double *V = allocV(n);
  double *W = allocV(n);
  double *X = allocV(n);

  // printf("Entre com a matriz:\n");
  //fillMaleat(M,n); Se for gerar aleatoriamente
  fillM(M,n);
  // printf("Entre com o vetor:\n");
  //fillValeat(V,n); Se for gerar aleatoriamente
  fillV(V,n);


  t1=clock();
  matriztriangularsup(U,M,n);
  resolvesistemas(V,W,X,U,n);
  t2=clock();

  // printM(M,n);
  // printf("-----------------\n");
  // printM(U,n);
  // printf("-----------------\n");
//  printV(W,n);
//  printf("-----------------\n");
  printf("Cholewski: \n");
  printf("Tempo(s): %.6f\n", (double)(t2-t1)/(CLOCKS_PER_SEC));
  acc += (double)(t2-t1)/CLOCKS_PER_SEC;
  if(argv[1][0] == 'Y'){
    printV(X,n);
    printf("\n");
  }
  else{
    FILE *fp;
        char filename[50];
        int i;
        i=sprintf(filename,"cholewski_y_%d.txt",n);
        fp = fopen(filename,"w");
        for(i=0;i<n;i++){
        fprintf(fp,"%.10lf\n",X[i]);
        }
        fclose(fp);
  }
}
