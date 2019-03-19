#include<stdio.h>

void GetChar2Put();
void GetChar2PutB();

int main()
{
    GetChar2PutB();
    GetChar2Put();
    return 0;
}

/*copy input to output; 1st version*/
void GetChar2Put()
{
    int c_var;
    while((c_var = getchar()) != EOF)
    {
       putchar(c_var);
    }
}

void GetChar2PutB()
{
    bool b_var = (getchar() != EOF);
    printf("getchar() != EOF:%d\n", b_var);
}