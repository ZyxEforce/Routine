#include<stdio.h>

int main()
{
    printf("int类型所占字节数%d \n",sizeof(int));
    printf("char类型所占字节数%d \n",sizeof(char));
    printf("float类型所占字节位数%d \n",sizeof(float));
    printf("double类型所占字节位数%d \n ",sizeof(double));
    printf("long类型所占字节位数%d \n",sizeof(long));

    return 0;
}