#include <stdio.h>
#include <omp.h>

void sequential_pi(){
 long long num_terms = 100000000;  // Number of terms
    double pi = 0.0;
    double start,end;
    start = omp_get_wtime();
    for (long long i = 0; i < num_terms; i++) {
        double term = 4.0 / (2 * i + 1);
        if (i % 2 != 0){
                term = -term;
        }
        pi += term;
    }
    end = omp_get_wtime();
printf("\n\nSequential Calculation\n\n");
    printf("Estimated Pi: %f\n", pi);
    printf("Required time :%f\n",end-start);
    

}
int main() {
    sequential_pi();
    long long num_terms = 100000000;  // Number of terms
    double pi = 0.0;
    double start,end;
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:pi)
    for (long long i = 0; i < num_terms; i++) {
        double term = 4.0 / (2 * i + 1);
        if (i % 2 != 0){ 
		term = -term;
	}  
        pi += term;
    }
    end = omp_get_wtime();
	printf("\n\n Parallel Calculation\n\n");
    	printf("Estimated Pi: %f\n", pi);
	printf("Required time :%f\n",end-start);

   	return 0;
}
