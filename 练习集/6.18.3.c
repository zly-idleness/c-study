#include <stdio.h>

int main ()
{
    printf ("1  2  3  4  5  6  7  8  9\n");
    printf ("-  -  -  -  -  -  -  -  -\n");
    for (int i = 1;i < 10;i++)
    {
        for (int j = 1;j < 10;j++)
        {
            
            if (j >= i)
            {
            printf ("%d ",i * j);
            if (i * j < 10 )
            printf (" ");
            }
            else printf ("   ");
        }
        printf ("\n");
    }
    return 0;
}