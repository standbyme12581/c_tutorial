#include <stdio.h>

// remove属于库函数
int main(int argc, char *argv[])
{
    if (remove("file.txt") == -1)
    {
        perror("fail to remove");
        return -1;
    }
    printf("delete done\n");
    return 0;
}