#include <stdio.h>
#include <omp.h>

int main() {
    int N = 20;
    int total_sum = 0;

    #pragma omp parallel
    {
        int partial_sum = 0;

        #pragma omp for lastprivate(total_sum)
        for (int i = 1; i <= N; i++) {
            partial_sum += i;
        }

        total_sum = partial_sum;
    }

    printf("Total sum of first %d natural numbers: %d\n", N, total_sum);
    return 0;
}

