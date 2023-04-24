#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;
pthread_mutex_t third_mutex;

void *thread_one(void *arg)
{
    pthread_mutex_lock(&first_mutex);
    printf("Thread ONE Acquired first_mutex\n");
    sleep(1);
    pthread_mutex_unlock(&first_mutex);
    printf("Thread ONE Released first_mutex\n");
    return NULL;
}

void *thread_two(void *arg)
{
    pthread_mutex_lock(&second_mutex);
    printf("Thread TWO Acquired second_mutex\n");
    sleep(1);
    pthread_mutex_lock(&third_mutex);
    printf("Thread TWO Acquired third_mutex\n");
    sleep(1);
    pthread_mutex_unlock(&third_mutex);
    printf("Thread TWO Released third_mutex\n");
    pthread_mutex_unlock(&second_mutex);
    printf("Thread TWO Released second_mutex\n");
    return NULL;
}

void *thread_three(void *arg)
{
    pthread_mutex_lock(&third_mutex);
    printf("Thread THREE Acquired third_mutex\n");
    sleep(1);
    pthread_mutex_lock(&first_mutex);
    printf("Thread THREE Acquired first_mutex\n");
    sleep(1);
    pthread_mutex_unlock(&first_mutex);
    printf("Thread THREE Released first_mutex\n");
    pthread_mutex_unlock(&third_mutex);
    printf("Thread THREE Released third_mutex\n");
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, thread_one, NULL);
    pthread_create(&t2, NULL, thread_two, NULL);
    pthread_create(&t3, NULL, thread_three, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Thread joined\n");

    return 0;
}