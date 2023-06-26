#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *run(void *arg)
{
    int i;
    for (i = 0; i < 5; i++) {
        printf("I am running\n");
        sleep(1);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    pthread_t tid;
    ret = pthread_create(&tid, NULL, run, NULL);
    if (ret != 0) {
        perror("fail to pthread_create");
    }
    pthread_detach(tid);
    pthread_join(tid, NULL);
    printf("after join\n");
    sleep(3);
    printf("I am leaving\n");
    return 0;
}