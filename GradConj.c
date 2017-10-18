#include <stdlib.h>
#include <stdio.h>
#include "BasicFunc.h"
#include <math.h>
#include <time.h>

void copiaVetor(double *V1, double *V2, int n){
  int i;
  for(i=0; i<n; i++){
    V1[i] = V2[i];
  }
}

double* subVetores(double *V1, double *V2, int n){
  int i;
  double *SV;
  SV = allocV(n);
  for(i=0; i<n; i++){
    SV[i] = V1[i] - V2[i];
  }
  return SV;
}

double* sumVetores(double *V1, double *V2, int n){
  int i;
  double *SV;
  SV = allocV(n);
  for(i=0; i<n; i++){
    SV[i] = V1[i] + V2[i];
  }
  return SV;
}

double MultVetorLC(double *V1, int n){//multiplicação de um vetor Linha (transposta) por vetor coluna;
  int i;
  double MLC = 0;
  for(i=0; i<n; i++){
      MLC = MLC + (V1[i]*V1[i]);
    }
    return MLC;
}

double* scalarMultVM(double *V, double **M, int n){
    int i;
    int j;
    double *VM;
    VM = allocV(n);
    for(i=0;i<n;i++){
        VM[i] = 0;
        for(j=0;j<n;j++){
            VM[i] = VM[i] + (V[j] * M[j][i]);
        }
    }
    return VM;
}


double scalarMultVV(double *V1, double *V2, int n){
  int i;
  double MVV = 0;
  for(i=0; i<n; i++){
    MVV = MVV + (V1[i] * V2[i]);
  }
  return MVV;
}

double moduloVetor(double *V, int n){
  int i;
  double somatoria = 0;
  for(i=0; i<n; i++){
    somatoria = somatoria + pow(V[i],2);
  }
  return sqrt(somatoria);
}

void main(int argc, char *argv[]){
  int n;
  double acc=0;
  clock_t t1, t2;

  // printf("Entre com n:");
  scanf("%d", &n);

  double **A;
  double *Y;
  double *Xnew;
  double *Xo;
  double *Xold;
  double *Rnew;
  double *Rold;
  double *P;
  double *MV_temp;
  double *VV;
  double *lambdaV;
  
  A = allocM(n);
  Y = allocV(n);
  Xnew = allocV(n);
  Xo = allocV(n);
  Xold = allocV(n);
  Rnew = allocV(n);
  Rold = allocV(n);
  P = allocV(n);
  MV_temp = allocV(n);
  VV = allocV(n);
  lambdaV = allocV(n);
  
  //printf("Entre com a matriz: \n");
  fillM(A,n);

  //printf("Entre com o vetor: \n");
  fillV(Y,n);

  double tol = pow(10,-8);
  double eps = tol + 1;
  int k = 0;
  int nmax = atoi(argv[1]);
  double alpha;
  double beta;

  t1=clock();

  zeroFyV(Xo, n);
  copiaVetor(Xnew, Xo, n);
  
  // Rold = (b-AXo)
  MV_temp = scalarMultMV(MV_temp, A, Xo, n);
  VV = subVV(VV, Y, MV_temp, n);
  copiaVetor(Rold,VV, n);
  
  
  copiaVetor(Rnew, Rold, n);
  //P = r
  // lambdaV = scalarMultV(lambdaV, -1, Rold, n); 
  // copiaVetor(P, lambdaV, n);
  copiaVetor(P, Rold, n);

  while(eps>tol & k<nmax){
    copiaVetor(Xold, Xnew, n);
    copiaVetor(Rold, Rnew, n);
    
    //alpha =  RtR/PtAP
    MV_temp = scalarMultMV(MV_temp, A, P, n);
    alpha = (scalarMultVV(Rold, Rold, n)) / (scalarMultVV(P, MV_temp, n));
    
    //Xnew = Xold - alpha*P
    lambdaV = scalarMultV(lambdaV, alpha, P, n);
    VV = sumVV(VV, Xold, lambdaV,n);
    copiaVetor(Xnew, VV, n);
    
    //Rnew = R_old - alpha*A*P
    MV_temp = scalarMultMV(MV_temp, A, P, n);
    MV_temp = scalarMultV(MV_temp,alpha,MV_temp, n);
    VV = subVV(VV, Rold, MV_temp,n);
    copiaVetor(Rnew, VV, n);
    
    //Beta = RnewTRnew/RoldTRold
    beta = scalarMultVV(Rnew, Rnew, n) / scalarMultVV(Rold, Rold, n);
    
    //P = Rnew + Beta.P
    lambdaV = scalarMultV(lambdaV, beta, P, n);
    VV = sumVV(VV, Rnew, lambdaV, n);
    copiaVetor(P, VV, n);
    k=k+1;

    VV = subVV(VV,Xnew,Xold,n);
    eps = Ninf(VV,n);
  }
  t2=clock();
  acc += (double)(t2-t1)/CLOCKS_PER_SEC;
  
  printf("Gradientes Conjugados: \n");
  printf("Tempo(s): %.6f\n", (double)(t2-t1)/(CLOCKS_PER_SEC));
  printf("Iteracoes: %d\n",k);
  if(argv[2][0] == 'Y'){
    printV(Xnew, n);
    printf("\n");
  }
}