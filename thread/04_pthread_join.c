#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// 测试被等待线程的返回值
void *run(void *arg)
{
    int num = 123;
    printf("after 2 seconds, thread will return\n");
    sleep(2);
    return (void *)num;
}

int main(int agrc, char *agrv[])
{
    pthread_t tid;
    int ret = 0;
    int value = 0;
    ret = pthread_create(&tid, NULL, run, NULL);
    if (ret != 0) {
        perror("fail to pthread_create");
    }
    pthread_join(tid, (void *)(&value));
    printf("value = %d\n", value);
    return 0;
}