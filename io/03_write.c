#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // 向终端写数据
    if (write(1, "hello world\n", 12) == -1)
    {
        perror("fail to write");
        return -1;
    }
    return 0;
}
