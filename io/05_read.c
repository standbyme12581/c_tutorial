#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // 从终端中读取
    ssize_t bytes;
    char str[32] = "";
    if ((bytes = read(0, str, 6)) == -1)
    {
        perror("fail to read");
        return -1;
    }
    printf("str = %s\n", str);
    printf("bytes = %ld\n", bytes);
    return 0;
}