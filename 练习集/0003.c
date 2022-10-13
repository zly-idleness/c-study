#include <stdio.h>
int main ()
{
    int N;
    int abs ();
    scanf ("%d",&N);
    //初始化 && 输入
    for (int i = 0;N != 0;i++)
    {
        if(N %10 != 0)
        {
        printf("%d",N % 10);
        N /=10;
        N =abs (N);
        }
        else 
        N/=10 ;
    }
    //输出
    printf ("\n");
    return 0;
}