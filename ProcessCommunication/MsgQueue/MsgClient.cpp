#include"MsgServer.h"

int main()
{
    int msqid;
    key_t key;
    struct msg_form msg;

    //获取key的值
    if((key = ftok(MSG_FILE,'z')) < 0)
    {
        perror("ftok error");
        exit(1);
    }

    //打印key的值
    printf("Message Queue -Client key is: %d.\n", key);

    //打印消息队列
    if((msqid = msgget(key, IPC_CREAT|0777)) == -1)
    {
        perror("msgget error");
        exit(1);
    }

    //打印消息队列ID继承ID
    printf("My msqid is:%d.\n",msqid);
    printf("My pid is:%d.\n", getpid());

    //添加消息,类型为888
    msg.mtype = 888;
    sprintf(msg.mtext, "hello, I`m client %d", getpid());
    msgsnd(msqid, &msg, sizeof(msg.mtext), 0);

    //读取类型为999的消息
    msgrcv(msqid, &msg, 256, 999, 0);
    printf("Client:receive msg.mtext is:%s.\n", msg.mtext);
    printf("Client:receive msg.ntype is:%d.\n", msg.mtype);

    return 0;
}