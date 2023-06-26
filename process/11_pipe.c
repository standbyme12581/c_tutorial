#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

/* 验证无名管道文件读写的阻塞和非阻塞 */
int main(int agrc, char *argv[])
{
    int fd_pipe[2];
    char buf[] = "hello world";
    pid_t pid;
    if (pipe(fd_pipe) < 0)
    {
        perror("fail to pipe");
    }
    pid = fork();
    if (pid < 0)
    {
        perror("fail to fork");
        exit(-1);
    }
    if (pid == 0)
    {
        sleep(3);
        write(fd_pipe[1], buf, strlen(buf));
        _exit(0);
    }
    else
    {
        fcntl(fd_pipe[0], F_SETFL, 0);
        while (1)
        {
            memset(buf, 0, sizeof(buf));
            read(fd_pipe[0], buf, sizeof(buf));
            printf("buf = %s\n", buf);
            sleep(1);
        }
    }
    return 0;
}