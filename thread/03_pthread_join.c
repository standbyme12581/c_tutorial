#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *run(void *arg)
{
    static int num = 123;
    printf("after 2 seconds, thread will return\n");
    sleep(2);
    return &num;
}

int main(int agrc, char *agrv[])
{
    pthread_t tid;
    int ret = 0;
    void *value = 0;
    ret = pthread_create(&tid, NULL, run, NULL);
    if (ret != 0) {
        perror("fail to pthread_create");
    }
    pthread_join(tid, &value);
    printf("valie = %d\n", *((int *)value));
    return 0;
}