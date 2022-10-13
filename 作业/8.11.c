#include <stdio.h>
#include <string.h>

int main (void)
{
    int n;scanf ("%d",&n);//读入n

    int row[2][n+1];//递推
    memset(row,0,sizeof(row));//初始化

    row [0][0] = 1;
    printf("    1\n");

    for(int i = 1;i <= n;i++)
    {
        int If_Odd = i&1;//判断奇偶
        row[If_Odd][0] = 1;//首项为1
        for(int j = 1;j <= n;j++)
        {
            row[If_Odd][j] = row[If_Odd ^ 1][j] + row[If_Odd ^ 1][j-1];//由上一行递推
        }

        for(int j = 0;j <= i;j++)printf("%5d",row[If_Odd][j]);
        printf ("\n");//输出

    }
    return 0;
}