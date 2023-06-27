#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 64

int main(int argc, char *argv[])
{
    // 从文件中读取
    int fd;
    if ((fd = open("file.txt", O_RDONLY | O_CREAT, 0664)) == -1)
    {
        perror("fail to open");
        return -1;
    }

    ssize_t bytes;
    char buf[N] = "";
    if ((bytes = read(fd, buf, 32)) == -1)
    {
        perror("fail to read");
        return -1;
    }
    printf("buf = %s\n", buf);
    printf("bytes = %ld\n", bytes);

    close(fd);
    return 0;
}