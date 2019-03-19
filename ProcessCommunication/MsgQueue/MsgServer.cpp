#include"MsgServer.h"

int main()
{
    int msqid;
    key_t key;
    struct msg_form msg;

    if((key = ftok(MSG_FILE, 'z')) < 0)
    {
        perror(" ftok error");
        exit(1);
    }

    //打印key值
    printf("Message Queue -Server key is:%d.\n", key);

    //创建消息队列
    if((msqid = msgget(key, IPC_EXCL|0777)) == -1)
    {
        perror("msgget error\n");
        exit(1);
    }

    //打印消息队列Id以及进程ID
    printf("My msqid is: %d.\n", msqid);
    printf("My pid is :%d.\n", getpid());

    //循环读取消息
    for(;;)
    {
        msgrcv(msqid, &msg,256, 888, 0);
        printf("Server:receive msg.mtext is : %s.\n",msg.mtext);
        printf("Server:receive msg.type is: %d.\n", msg.mtype);

        msg.mtype = 999;  //客户端接受的消息类型
        sprintf(msg.mtext,"hello, I`m server %d", getpid());
        msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
    }
    return 0;
}