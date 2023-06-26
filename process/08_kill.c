#include <signal.h>
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
        int i = 0;
        for (i = 0; i < 5; i++)
        {
            printf("in son process\n");
            sleep(1);
        }
    }
    else
    {
        printf("in father process\n");
        sleep(2);
        printf("kill sub process now\n");
        kill(pid, SIGINT);
    }
    return 0;
}