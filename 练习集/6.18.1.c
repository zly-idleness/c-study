#include <stdio.h>

int main ()
{
    for (int i = 0;i < 10;i++)
    {
            if (i == 1)
        {
            printf ("-  -  -  -  -  -  -  -  -\n");
        }
        for (int j = 1;j < 10;j++)
        {
            if(i == 0)
            {
                printf ("%d  ",j);
            }
            else printf ("%d ",i * j);
            if (i * j < 10 &&i * j != 0)
            printf (" ");
        }
        printf ("\n");
    }
    return 0;
}