#include <stdio.h>
#include <string.h>
int main ()
{
    int n,m,k;
    scanf ("%d %d %d",&n,&m,&k);
    //初始化 & 输入
    int a[n][m];
    int T [m][k];
    memset (a,0,sizeof(a));
    memset (T,0,sizeof(T));

    for (int i= 0;i < n;i++)
    {

        for (int j = 0;j < m;j++)
        {
            scanf ("%d",&a[i][j]);
            //赋值
            T [j][a[i][j]] = 1;
            //将该天该场标记为true
        }
    }
    for (int s = 1;s <= k;s++)
    {
        int cnt = 0;
        for (int t = 0;t < m;t++)
        {
            if(T[t][s] == 1)
            {
                cnt ++;
            }
        }
        printf ("%d ",cnt);
    }
    printf ("\n");
    return 0;
}