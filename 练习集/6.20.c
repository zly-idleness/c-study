#include <stdio.h>
int main ()
{
    for (int num = 1000;num <= 10000;num++)
    {
        int a = num / 1000;
        int b = (num / 100) % 10;
        int c = num % 10;
        int d = (num/10) % 10;

        int flag = 0;

        for (int i = 1;i <= 100;i++)
        {
            if(i * i == num)
            flag = 1;
        }

        if (a == b && c == d && flag == 1)
        printf ("%d\n",num);
    }
    return 0;
}