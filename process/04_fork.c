#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

/* 验证子进程继承父进程的缓冲区 */
int main(int argc, char *argv[])
{
    pid_t pid;
    int length = 0;
    char buf[] = "a write to stdout\n";
    length = write(1, buf, strlen(buf));
    if (length != strlen(buf))
    {
        printf("write error\n");
    }
    printf("before fork\n");
    pid = fork();
    if (pid < 0)
    {
        perror("fail to fork");
    }
    else if (pid == 0)
    {
        printf("in son process\n");
    }
    else
    {
        sleep(1);
        printf("in father process\n");
    }
    return 0;
}