#include <stdio.h>
#include <stdlib.h>
#include "BasicFunc.h"


void main(){
    float **M;
    int i = 0;
    int n = 5;
    //v = (float *)malloc(n*sizeof(float));
    M = allocM(n);
    identityFyM(M,n);
    printM(scalarMultM(3,M,n),n);
}