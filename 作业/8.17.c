`#include <stdio.h>
void Print_Fact(int n)
{
    int a [50] = {1,};//用数组储存
    int pos = 0;//位数
    int forward = 0;//判断进位
    for(int i = 2;i <= n;i++)
    {
        for(int j = 0;j <= pos;j++)
        {
            int temp = a[j] * i + forward;
            a [j] = temp % 10;
            forward = temp / 10;
        }
        while(forward)
        {
            pos++;
            a[pos] = forward % 10;
            forward /= 10;
        }
    }
    for (int k = pos;k >= 0;k--)printf ("%d",a[k]);
    printf("\n");
}
int main (void)
{
    printf("1\n");
    for(int i = 2;i <= 40;i++)
        Print_Fact(i);
        return 0;
}