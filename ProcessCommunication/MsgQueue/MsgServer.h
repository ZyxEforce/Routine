#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<unistd.h>

//用于创建一个唯一的key
#define MSG_FILE "/home/index_sys/zyx/test/routine/ProcessCommunication"

//消息结构体
struct msg_form
{
    long mtype;
    char mtext[256];
};

