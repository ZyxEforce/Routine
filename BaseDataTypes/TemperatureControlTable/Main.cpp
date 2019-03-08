#include<stdio.h>

/*当fahr=0,20,...300时*，分别对应打印华氏温度与摄氏温度对照表*/

int main()
{
    int fahr;
    int celsius;
    int lower;
    int upper;
    int step;

    lower = 0;       /*温度表的下限*/
    upper = 300;       /*温度表的上限*/
    step = 20;        /*步长*/

    fahr = lower;
    while(fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;      /*5/9是因为整数操作将执行舍位，结果中的西哦啊属部分会被遗弃*/
        printf("%d\t%d\n",fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}