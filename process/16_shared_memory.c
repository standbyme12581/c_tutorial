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
    if (key == -1) {
        perror("fail to ftok");
    }
    /* 创建共享内存 */
    shmid = shmget(key, BUFSZ, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("fail to shmget");
        exit(-1);
    }
    /* 映射 */
    shmadd = shmat(shmid, NULL, 0);
    if (shmadd < 0) {
        perror("fail to shmat");
        _exit(-1);
    }
    /* 拷贝数据至共享内存区 */
    printf("copy data to shared-memory\n");
    bzero(shmadd, BUFSZ);
    strcpy(shmadd, "data in shared memory\n");
    return 0;
}