#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFSZ 2048

int main(int argc, char *argv[])
{
    int shmid;
    int ret;
    key_t key;
    char *shmadd;

    key = ftok(".", 2012);
    if (key == -1)
    {
        perror("fail to ftok");
    }
    system("ipcs -m");
    /* 创建共享内存 */
    shmid = shmget(key, BUFSZ, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmget");
        exit(-1);
    }
    /* 映射 */
    shmadd = shmat(shmid, NULL, 0);
    if (shmadd < 0)
    {
        perror("fail to shmat");
        exit(-1);
    }
    /* 读共享内存区数据 */
    printf("data = [%s]\n", shmadd);
    /* 分离共享内存和当前进程 */
    ret = shmdt(shmadd);
    if (ret < 0)
    {
        perror("fail to shmdt");
        exit(1);
    }
    else
    {
        printf("deleted shared-memory\n");
    }
    /* 删除共享内存 */
    shmctl(shmid, IPC_RMID, NULL);
    system("ipcs -m");
    return 0;
}