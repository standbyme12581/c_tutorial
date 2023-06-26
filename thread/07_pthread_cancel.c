#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *run(void *arg)
{
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    while (1) {
        printf("this is new thread_cancel\n");
        sleep(1);
    }
    return NULL;
}

int main(int argc, char *agrv[])
{
    pthread_t tid;
    int ret = 0;
    pthread_create(&tid, NULL, run, NULL);
    if (ret != 0) {
        perror("fail to pthread_create");
    }
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, NULL);
    return 0;
}