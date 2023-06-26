#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

// 验证线程调用pthread_exit函数时，系统自动调用线程清理函数
void cleanup(void *arg)
{
    printf("clean up ptr = %s\n", (char *)arg);
    free((char *)arg);
}

void *run(void *arg)
{
    char *ptr = NULL;

    /* 建立线程清理函数 */
    printf("this is new thread\n");
    ptr = (char *)malloc(100);
    pthread_cleanup_push(cleanup, (void *)ptr);
    bzero(ptr, 100);
    strcpy(ptr, "memory from malloc");
    printf("before exit\n");
    pthread_exit(NULL);
    sleep(3);

    /* 注意push与pop必须配对使用，即使pop执行不到 */
    printf("before pop\n");
    pthread_cleanup_pop(1);
    return NULL;
}

int main(int agrc, char *argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, run, NULL);
    pthread_join(tid, NULL);
    printf("process is dying\n");
    return 0;
}