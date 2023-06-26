#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int var = 8;

void *run_1(void *arg)
{
    int rec = 0;
    sleep(1);
    rec = (int)(arg);
    printf("new thread1 arg = %d\n", rec);
    return NULL;
}

void *run_2(void *arg)
{
    int rec = 0;
    sleep(1);
    rec = *((int *)arg);
    printf("new thread2 arg = %d\n", rec);
    return NULL;
}

int main(int agrc, char *agrv[])
{
    pthread_t tid1, tid2;
    int test = 100;
    /* 创建两个线程 */
    pthread_create(&tid1, NULL, run_1, (void *)test);
    pthread_create(&tid2, NULL, run_2, (void *)(&test));
    while (1);
    return 0;
}