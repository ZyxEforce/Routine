#include<stdio.h>

int main()
{
    int i_var = 123;
    unsigned ui_var2 = 123;
    float f_var3 = 123.123;
    char c_var4 = 'a';
    double f_var5 = 123.123;

    printf("%d\n", i_var);          //整形
    printf("%u\n", ui_var2);        //无符号整形
    printf("%f\n", f_var3);         //浮点型
    printf("%c\n", c_var4);         //字符型
    printf("%f\n", f_var5);         //双精度型

    printf("\"转义字符\",\"反斜杠\\ \" \n");

    printf("\c \n");

    return 0;
}