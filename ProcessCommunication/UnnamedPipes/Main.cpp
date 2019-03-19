#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int count;
    int status;
    int fd[2];
    pid_t pid;
    char buff[20];

    if(pipe(fd)<0)
    {
        printf("Create pipe Error! \n");
    }

    if((pid = fork()) < 0)
    {
        printf("Fork Error!\n");
    }
    else if(pid == 0)   //子进程
    {
        close(fd[0]); //关闭读端
        if( write(fd[1], "hello world\n",12) == -1)
        {
            printf("write pipe error!");
            exit(-1);
        }
    }
    else
    {
        if(waitpid(pid, &status, 0) != pid)
        {
            printf("waitpid error\n");
        }

        if(WIFEXITED(status) == 0);
        {
            printf("child process exit faild \n");
        }
        close(fd[1]);   //关闭写端
        count = read(fd[0],buff,20);
        printf("%d\n", count);
        printf("%s", buff);
        write(STDOUT_FILENO, buff, count);
    }
    
    return 0;
}