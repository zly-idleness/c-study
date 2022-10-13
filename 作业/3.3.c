//银行利率
#include <stdio.h>

int main ()
{
    const double rate = 0.0225;
    int n;
    double capital,deposit;
    //初始化
    scanf ("%d %lf",&n,&capital);
    deposit = capital;
    //输入本金及年限
    for (int i = 0;i < n;i++)
    {
        deposit = deposit * (1 + rate);
    }
    //求收入
    printf ("%lf\n",deposit);
    return 0;
}