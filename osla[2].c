#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

sem_t lock; // semaphore variable

void threadFunc(int id) {
    sem_wait(&lock); // wait for the lock to be available
    cout << "Thread " << id << " started" << endl;
    // simulate some work
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Thread " << id << " execution completed" << endl;
    sem_post(&lock); // release the lock
}

int main() {
    sem_init(&lock, 0, 1); // initialize the semaphore with value 1
    thread t1(threadFunc, 1);
    thread t2(threadFunc, 2);
    t1.join();
    t2.join();
    sem_destroy(&lock); // destroy the semaphore
    return 0;
}
