#include <iostream>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutexLock;

void* threadFunction(void* threadID) {
    int id = *(int*)threadID;
    pthread_mutex_lock(&mutexLock);
    std::cout << "Lock acquired on data item" << std::endl;
    std::cout << "Thread " << id << "...Completed" << std::endl;
    pthread_mutex_unlock(&mutexLock);
    std::cout << "Lock released on data item" << std::endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int threadID[3] = {1, 2, 3};
    pthread_mutex_init(&mutexLock, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, threadFunction, (void*)&threadID[i]);
        sleep(1);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutexLock);

    return 0;
}
