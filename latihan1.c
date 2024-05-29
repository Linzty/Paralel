#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads = 20;
    int total[num_threads];
    omp_set_num_threads(num_threads);

    #pragma omp parallel
    {
        total[omp_get_thread_num()] = 0;

        #pragma omp for
        for(int i = 1; i <= 10; i++) {
            total[omp_get_thread_num()] += i;
        }

        if (total[omp_get_thread_num()] != 0) {
            printf("Total thread %d adalah = %d\n", omp_get_thread_num(), total[omp_get_thread_num()]);
            
        }
    }

    int grand_total = 0;
    for (int i = 0; i < num_threads; i++) {
        grand_total += total[i];
    }

    printf("Grand total = %d\n", grand_total);
    return 0;
}
