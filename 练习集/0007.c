//# [NOIP2001 普及组] 数的计算
//
//## 题目描述
//
//我们要求找出具有下列性质数的个数（包含输入的正整数 n）。
//
//先输入一个正整数 n（n<  1000），然后对此正整数按照如下方法进行处理：
//
//1. 不作任何处理；
//
//2. 在它的左边拼接一个正整数，但该正整数不能超过原数，或者是上一个被拼接的数的一半；
//
//3. 加上数后，继续按此规则进行处理，直到不能再加正整数为止。
//
//
//
//一行，一个正整数 n（n <1000）。
//
//一个整数，表示具有该性质数的个数。
#include <stdio.h>

 int main ()
 {
    int n;
    int f [1005] ;
    scanf ("%d",&n);//初始化及输入

    for (int t = 0;t <= n;t++)
    {
        f[t] = 1;
    }//数组初始化

    for (int i = 2;i <= n;i++)
    {
        for (int j = 1;j <= i/2;j++)
        {
            f[i] = f[i] + f[j];
        }                            //f[n] = 自身 + 不超过自身一半的f[i]求和
    }
    printf ("%d\n",f[n]);
    return 0;
 }
