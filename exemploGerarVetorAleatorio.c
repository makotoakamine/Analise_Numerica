#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    srand(time(NULL));
    long int i;
    long int n = atoi(argv[1]);
    long int vetor[n];
    
    for (i=0; i<n; i++) {
        vetor[i] = rand();
    }
    
    for (i=0; i<n-1; i++) {
        printf("%ld\n", vetor[i]);
    }
    printf("%ld", vetor[i]);
}
