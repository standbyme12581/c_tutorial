#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open("file.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("fail to open");
        return -1;
    }

    printf("fd = %d\n", fd);

    close(fd);

    return 0;
}