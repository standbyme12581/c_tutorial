#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // 向文件写数据
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd == -1)
    {
        perror("fail to open");
        return -1;
    }

    if (write(fd, "hello world\n", 12) == -1)
    {
        perror("fail to write");
        return -1;
    }
    close(fd);
    return 0;
}
