#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

typedef struct struct_msg
{
    long mtype;     /* 消息类型 */
    char mtext[50]; /* 消息正文 */
} MSG;

int main(int argc, char *agrv[])
{
    key_t key;
    int msgqid;
    MSG msg;
    key = ftok(".", 2012);
    msgqid = msgget(key, IPC_CREAT | 0666);
    if (msgqid == -1)
    {
        perror("fail to msgget");
        exit(-1);
    }
    msg.mtype = 10;
    strcpy(msg.mtext, "hello world");
    msgsnd(msgqid, &msg, sizeof(msg.mtext), 0);
    return 0;
}