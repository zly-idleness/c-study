#include <stdio.h>
int main (void)
{
    const int chair = 30;
    int height ;
    int apple [10];
    int cnt = 0;
    //初始化
    for (int i = 0;i < 10;i++)
    {
        scanf ("%d",&apple[i]);
    }

    scanf ("%d",&height);
    for (int i = 0;i < 10;i++)
    {
        if (apple[i] <= height + chair)
        {
            cnt++;
        }
    }
    printf ("%d\n",cnt);
}