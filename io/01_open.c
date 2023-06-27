#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    // 使用open函数打开或创建一个文件
    // int fd = open("file.txt", O_RDONLY | O_CREAT, 0664);
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        // 通过全局变量errno打印错误
        // 注意需要添加errno.h头文件
        // printf("errno = %d\n", errno);
        // 通过perror函数输出函数调用失败的原因
        perror("fail to open");
        return -1;
    }

    printf("fd = %d\n", fd); // 3
    return 0;
}