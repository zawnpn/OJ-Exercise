#include<cstdio>

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if (n < 0 || n > 100)
        {
            printf("Score is error!\n");
        }
        else if (n <= 59)
        {
            printf("E\n");
        }
        else if (n <= 69)
        {
            printf("D\n");
        }
        else if (n <= 79)
        {
            printf("C\n");
        }
        else if (n <= 89)
        {
            printf("B\n");
        }
        else
        {
            printf("A\n");
        }
    }
    return 0;
}