#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    int ret;
    ret = mkfifo("my_fifo", S_IRUSR | S_IWUSR);
    if (ret != 0)
    {
        perror("fail to mkfifo");
    }
    printf("before open\n");
    fd = open("my_fifo", O_WRONLY);
    if (fd < 0)
    {
        perror("open fifo");
    }
    printf("after open\n");
    return 0;
}