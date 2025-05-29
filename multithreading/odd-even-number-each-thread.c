#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sync_odd;
sem_t sync_even;

int value=1;

void* printodd(void*);
void* printeven(void*);

void* printodd(void*)
{
    while(1)
    {
        sem_wait(&sync_odd);
        printf("\n odd thread %d\n", value++);
        sem_post(&sync_even);
    }
}

void* printeven(void*)
{
    while(1)
    {
        sem_wait(&sync_even);
        printf("\n even thread %d\n", value++);
        sem_post(&sync_odd);
    }
}

int main()
{
    pthread_t t1, t2;

    sem_init(&sync_odd,  0, 1);
    sem_init(&sync_even, 0, 0);

    pthread_create(&t1, NULL, printodd, NULL);
    pthread_create(&t2, NULL, printeven, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
