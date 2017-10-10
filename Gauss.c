#include <stdio.h>
#include <stdlib.h>
#include "BasicFunc.h"


void main(){
    float *v;
    int i = 0;
    int n = 5;
    //v = (float *)malloc(n*sizeof(float));
    v = allocV(n);
    for(i=0;i<n;i++){
        scanf("%f",&v[i]);
    }
    
    
    for(i=0;i<n;i++){
        printf("%f",v[i]);
    }   
}