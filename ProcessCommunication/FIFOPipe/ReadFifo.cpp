#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

#define FILE_NAME "/home/index_sys/zyx/test/routine/ProcessCommunication/FIFOPipe/fifo.txt"


int main()
{
    int fd;
    int len;
    char buff[1024];

    if(mkfifo(FILE_NAME, 0666) < 0 && errno != EEXIST)
    {
        perror("Create FIFO Faild");
    }

    if((fd = open(FILE_NAME, O_RDONLY)) < 0)
    {
        perror("OPen FIFO Faild");
        exit(1);
    }

    len = read(fd, buff, 1024);
    while(len > 0)
    {
        buff[len] = '\0';
        printf("Read message: %s", buff);
        len = read(fd, buff, 1024);
        printf("%d\n", len);
    }

    close(fd);

    return 0;
}