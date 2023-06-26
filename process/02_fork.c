#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("fail to fork");
    }
    if (pid == 0)
    {
        while (1)
        {
            printf("this is son process\n");
            sleep(1);
        }
    }
    else
    {
        while (1)
        {
            printf("this is father process\n");
            sleep(1);
        }
    }
    return 0;
}