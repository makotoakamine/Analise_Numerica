#include <stdio.h>
#include "BasicFunc.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846
double funcaoR(double x){ //função de entrada
  return -pow(PI,2)*sin(PI*x);
}

void main(int argc, char *argv[]){
    int n, i, j, a ,b;
    double *V, R, x, alpha, beta;

//   printf("Número de partições: \n");
//   scanf("%d", &nos);
    n = atoi(argv[1]);
//   printf("Intervalo a b: \n");
//   scanf("%d %d", &a, &b);
    a = atoi(argv[2]);
    b = atoi(argv[3]);
//   printf("Entre com alpha e beta\n");
//   scanf("%f %f",&alpha, &beta);
    alpha = atof(argv[4]);
    beta = atof(argv[5]);
    double h = ((double)b-(double)a)/(double)n;
    V = allocV(n-1);
    //R = pow(x,4) + pow(x,3);
    printf("%d\n",n-1);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(i==j){
                printf("2\t");
            }
            else if(j == i+1){
                printf("-1\t");
                
            }
            else if(i == j+1){
                printf("-1\t");
            }
            else{
                printf("0\t");
            }
        }
        printf("\n");
    }
    FILE *fp;
    char filename[50];
    i = sprintf(filename,"Xrange_%d.txt",n-1);
    fp = fopen(filename,"w");
    for(i=0; i<n-1; i++ ){
        x = (double)a + ((double)i)*h;
        fprintf(fp,"%.10lf\n",x);
        V[i] = pow(h,2)*funcaoR(x);
    }
    fclose(fp);
    V[0] = V[0] + alpha;
    V[n-2] = V[n-2] + beta;
    
    for(i=0;i<n-1;i++){
        printf("%.10lf\n",V[i]);
    }
}