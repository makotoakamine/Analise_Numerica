#include<stdio.h>
#include<time.h>

int main(void)
{
    int i, k, n=100;
    double acc=0;
    clock_t t1, t2;
		
    for (k=0; k<n; k++) {
        t1 = clock();
        srand(time(NULL));
        for (i=0; i<1000000; i++) {
            rand();
        }
        t2 = clock();
        
        printf("%.6f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
        acc += (double)(t2-t1)/CLOCKS_PER_SEC;
    }
    
    printf("Tempo medio: %f\n", acc/n);
    return 0;
}


