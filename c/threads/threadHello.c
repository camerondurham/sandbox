#define NTHREADS 10
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

pthread_t threads[NTHREADS];
void go (int n) {
    printf("Hello from thread %d\n", n);
    pthread_exit(100 + n);
}
int main() {
    long exitValue = 0;
    // Create 10 threads
    for (int i = 0; i < NTHREADS; i++) pthread_create(&threads[i], NULL, go,  i);
    for (int i = 0; i < NTHREADS; i++) {
        exitValue = pthread_join(threads[i], NULL);
        printf("Thread %d returned with %ld\n", i, exitValue);
    }
    printf("Main thread done.\n");
}

