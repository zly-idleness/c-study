#include <stdio.h>

int  main(void)
{
    int sum ;
    for (int i = 6;i < 10000000;i ++)
    {
        int temp = i;
        int flag = 0;
        for (int k = 0;k < 5;k++)
        {
            if (temp % 5 == 1){temp = (temp -1)*4/5;}
            else break;
            if (k == 4)flag = 1;
        }
        if (flag){ printf("%d\n",i); break ; }
    }
}