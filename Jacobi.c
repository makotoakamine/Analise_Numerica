//Modificar o trecho da multiplicacao
//Otimizar levando em conta que a matriz diagonal nao precisa
//ser invertida.
//Fazer uma matriz esparsa para calcular os termo dependentes.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BasicFunc.h"
#include <math.h>

void main(int argc, char *argv[]){
    double **M;
    double *V;
    double *MV_temp;
    double *VV;
    double **X;
    double *D;
    double **R;
    int i = 0;
    int j = 1;
    int n;
    double tol = pow(10,-8);
    double eps = 1.000000 + tol;
    int nmax = atoi(argv[1]);
    
    
    double acc=0;
    clock_t t1, t2;
    //Inicializacao da Matriz
    scanf("%d",&n);
    M = allocM(n);
    fillM(M,n);
    V = allocV(n);
    fillV(V,n);
    MV_temp = allocV(n);
    VV = allocV(n);
    X = (double **)malloc(2*sizeof(double *)); 
    X[0] = allocV(n);
    X[1] = allocV(n);
    zeroFyV(X[0],n);
    zeroFyV(X[1],n);
    D = allocV(n);
    R = allocM(n);
    sparse_stripDR(M,D,R,n);
    t1 = clock();
    //trecho a ser cronometrado
    for(i=0;i<nmax && eps > tol;i++){
        MV_temp = scalarMultMV(MV_temp,R,X[i&1],n); 
        VV = subVV(VV,V,MV_temp,n); 
        for(j=0;j<n;j++){
            X[(i+1)&1][j] = VV[j]/D[j];
        }
        VV = subVV(VV,X[(i+1)&1],X[i&1],n);
        eps = Ninf(VV,n);
    }
    
    
    t2 = clock();
    acc += (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("Jacobi: \n");
    printf("Tempo(s): %.6f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    printf("Iteracoes: %d\n",i);
    if(argv[2][0] == 'Y'){
        printV(X[i&1],n);
        printf("\n");
    }
    else{
        FILE *fp;
        char filename[50];
        j=sprintf(filename,"jacobi_y_%d.txt",n);
        fp = fopen(filename,"w");
        for(j=0;j<n;j++){
        fprintf(fp,"%.10lf\n",X[i&1][j]);
        }
        fclose(fp);
    }
}
