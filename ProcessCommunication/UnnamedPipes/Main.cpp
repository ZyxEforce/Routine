#include<staio.h>
#include<unistd.h>

int main()
{
    int fd[2];
    pid_t pid;
    char buff[20];

    if(pipe(fp)<0)
    {
        printf("Create pipe Error!");
    }


    if(pid = fork() < 0)
    {
        printf("Fork Error!\n");
    }
    else if(pid > 0)
    {
        close(fd[0]); //关闭读端
        write(fd[1], "hello world\n",12);
    }
    else
    {
        close(fd[0]);   //关闭写端
        read(fd[0],buff,20);
        printf("%s", buff);
    }
    
}