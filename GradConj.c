#include <stdlib.h>
#include <stdio.h>
#include "BasicFunc.h"
#include <math.h>
#include <time.h>

void copiaVetor(float *V1, float *V2, int n){
  int i;
  for(i=0; i<n; i++){
    V1[i] = V2[i];
  }
}

float* subVetores(float *V1, float *V2, int n){
  int i;
  float *SV;
  SV = allocV(n);
  for(i=0; i<n; i++){
    SV[i] = V1[i] - V2[i];
  }
  return SV;
}

float* sumVetores(float *V1, float *V2, int n){
  int i;
  float *SV;
  SV = allocV(n);
  for(i=0; i<n; i++){
    SV[i] = V1[i] + V2[i];
  }
  return SV;
}

float MultVetorLC(float *V1, int n){//multiplicação de um vetor Linha (transposta) por vetor coluna;
  int i;
  float MLC = 0;
  for(i=0; i<n; i++){
      MLC = MLC + (V1[i]*V1[i]);
    }
    return MLC;
}

float* scalarMultVM(float *V, float **M, int n){
    int i;
    int j;
    float *VM;
    VM = allocV(n);
    for(i=0;i<n;i++){
        VM[i] = 0;
        for(j=0;j<n;j++){
            VM[i] = VM[i] + (V[j] * M[j][i]);
        }
    }
    return VM;
}


float scalarMultVV(float *V1, float *V2, int n){
  int i;
  float MVV = 0;
  for(i=0; i<n; i++){
    MVV = MVV + (V1[i] * V2[i]);
  }
  return MVV;
}

float moduloVetor(float *V, int n){
  int i;
  float somatoria = 0;
  for(i=0; i<n; i++){
    somatoria = somatoria + pow(V[i],2);
  }
  return sqrt(somatoria);
}

void main(){
  int n;
  double acc=0;
  clock_t t1, t2;

  printf("Entre com n:");
  scanf("%d", &n);

  float **A;
  float *Y;
  float *Xnew;
  float *Xo;
  float *Xold;
  float *Rnew;
  float *Rold;
  float *P;

  A = allocM(n);
  Y = allocV(n);
  Xnew = allocV(n);
  Xo = allocV(n);
  Xold = allocV(n);
  Rnew = allocV(n);
  Rold = allocV(n);
  P = allocV(n);

  printf("Entre com a matriz: \n");
  fillM(A,n);

  printf("Entre com o vetor: \n");
  fillV(Y,n);

  float tol = pow(10,-8);
  float eps = tol + 1;
  int k = 0;
  int nmax = 10;
  double alpha;
  double beta;

  t1=clock();

  zeroFyV(Xo, n);
  copiaVetor(Xold, Xo, n);
  copiaVetor(Xnew, Xo, n);
  copiaVetor(Rold, subVetores(scalarMultMV(A, Xo, n), Y, n), n);
  copiaVetor(Rnew, Rold, n);
  copiaVetor(P, scalarMultV(-1, Rold, n), n);

  while(eps>tol & k<nmax){
    alpha = (MultVetorLC(Rold, n)) / (scalarMultVV(scalarMultVM(P, A, n), P, n));
    copiaVetor(Xnew, sumVetores(Xold, scalarMultV(alpha, P, n), n), n);
    copiaVetor(Rnew, subVetores(scalarMultMV(A, Xnew, n), Y, n), n);
    beta = MultVetorLC(Rnew, n) / MultVetorLC(Rold, n);
    copiaVetor(P, sumVetores(scalarMultV(-1, Rnew, n), scalarMultV(beta, P, n), n), n);
    k=k+1;

    eps = moduloVetor(subVetores(Xnew, Xold, n),n);
  }
  printV(Xnew, n);
  t2=clock();

  printf("Tempo(s): %.6f\n", (double)(t2-t1)/(CLOCKS_PER_SEC));
  acc += (double)(t2-t1)/CLOCKS_PER_SEC;
  printf("Tempo medio: %f\n", acc/n);


  free(A);
  A = NULL;
  free(Y);
  Y = NULL;
  free(Xnew);
  Xnew = NULL;
  free(Xo);
  Xo = NULL;
  free(Xold);
  Xold = NULL;
  free(Rnew);
  Rnew = NULL;
  free(Rold);
  Rold = NULL;
  free(P);
  P = NULL;
}