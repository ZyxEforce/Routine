#include<stdio.h>

/*当fahr=0,20,...300时*，分别对应打印华氏温度与摄氏温度对照表*/

//函数声明
void TemperatureControlTableFirst();
void TemperatureControlTableSecond();
void TEmperatureControlTableThird();

int main()
{
    TemperatureControlTableFirst();
    TemperatureControlTableSecond();
    TEmperatureControlTableThird();
    return 0;
}

//first edition 
void TemperatureControlTableFirst()
{
    int fahr = 0;
    int celsius = 0;
    int lower = 0;
    int upper = 0;
    int step = 0;

    lower = 0;  /*温度下限*/
    upper  = 300;      /*温度上限*/
    step = 20;         /*步长*/

    while( fahr <= upper)
    {
        celsius  = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n",fahr,celsius);
        fahr = fahr + step;
    }
}

//second edition
void TemperatureControlTableSecond()
{
    float fahr = 0;
    float celsius = 0;
    float lower = 0;
    float upper = 0;
    float step = 0;

    lower = 0;      /*温度下限*/
    upper = 300;    /*温度上限*/
    step = 20;       /*步长*/

    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f\t%6.1f\n",fahr,celsius);
        fahr = fahr + step;
    }
}

//third edition
void TEmperatureControlTableThird()
{
    float fahr = 0;
    float celsius = 0;
    float lower = 0;
    float upper = 0;
    float step = 0;

    lower = 0;
    upper = 300;
    step  = 30;

    printf("摄氏温度转华氏温度表\n");

    while(fahr < upper)
    {
        fahr = (celsius * 9) / 5 - 32;
        printf("%3.0f\t%6.1f \n",celsius, fahr);
        celsius = celsius + step; 
    }
}