#include <stdio.h>
int main ()
{
    int S[40] = {0,};   int cnt = 0;
    for (int i = 0;i <= 40;i++)
    {   
        scanf("%d",&S[i]);
        if(S[i] < 60)   { cnt++;printf ("不及格人数为: %d\n",cnt); }
    }
    return 0;
}