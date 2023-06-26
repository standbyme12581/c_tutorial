#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int count;

void *run(void *arg)
{
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < 100; i++)
        count++;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, run, NULL);
    pthread_create(&tid2, NULL, run, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("%d\n", count);
    return 0;
}