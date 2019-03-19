#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<errno.h>

#define FILE_NAME "/home/index_sys/zyx/test/routine/ProcessCommunication/FIFOPipe/fifo.txt"

int main()
{
    int fd;
    int n;
    int i;
    char buf[1024];

    time_t tp;

    printf("I am %d process. \n", getpid());

    if(mkfifo(FILE_NAME, 0666) < 0 && errno != EEXIST)
    {
        perror("Create FIFO Faild");
    }

    if((fd = open(FILE_NAME, O_WRONLY)) < 0)
    {
        perror("Open FIFO Failed");
        exit(-1);
    }

    for(i = 0; i < 10; i++)
    {
        time(&tp);
        n = sprintf(buf, "Process %d`s time is %s", getpid(), ctime(&tp));
        printf("Send message:%s", buf);

        if(write(fd, buf, n+1) < 0)
        {
            perror("Write FIFO Failed");
            close(fd);
            exit(1);
        }

        sleep(1);
    }

    return 0;
}