#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *run(void *arg)
{
    int i = 0;
    while (1) {
        printf("I am running\n");
        sleep(1);
        i++;
        if (i == 3) {
            pthread_exit((void *)1);
        }
    }
    return NULL;
}

int main(int argc, char *argv)
{
    int ret = 0;
    pthread_t tid;
    void *value = NULL;
    ret = pthread_create(&tid, NULL, run, NULL);
    if (ret != 0) {
        perror("fail to pthread_create");
    }
    pthread_join(tid, &value);
    printf("value = %p\n", (int *)value);
    return 0;
}