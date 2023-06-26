#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* 验证父子进程分别有各自独立的地址空间 */
int var = 10;
int main(int argc, char *argv[])
{
    pid_t pid;
    int num = 9;
    pid = fork();
    if (pid < 0)
    {
        perror("fail to fork");
    }
    if (pid == 0)
    {
        var++;
        num++;
        printf("in son process var = %d, num = %d\n", var, num);
    }
    else
    {
        sleep(1);
        printf("in father process var = %d, num = %d\n", var, num);
    }
    printf("common code area\n");
    return 0;
}