#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 2

sem_t mutex;

void *thread_func(void *arg) {
    int id = (int)arg;
    
    printf("Lock acquired after wait\n");
    sem_wait(&mutex);
    
    printf("Thread %d started\n", id);
    // Access shared resource
    printf("Thread %d execution completed\n", id);
    
    printf("Lock released after signal\n");
    sem_post(&mutex);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;
    
    // Initialize semaphore
    sem_init(&mutex, 0, 1);
    
    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }
    
    // Wait for threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Destroy semaphore
    sem_destroy(&mutex);
    
    return 0;
}