//买铅笔
//P 老师需要去商店买 $n$ 支铅笔作为小朋友们参加 NOIP 的礼物。她发现商店一共有 $3$ 种包装的铅笔，
//不同包装内的铅笔数量有可能不同，价格也有可能不同。为了公平起 见，P 老师决定只买同一种包装的铅笔。

//商店不允许将铅笔的包装拆开，因此 P 老师可能需要购买超过 $n$ 支铅笔才够给小朋友们发礼物。

//现在 P 老师想知道，在商店每种包装的数量都足够的情况下，要买够至少 $n$ 支铅笔最少需要花费多少钱。

//输入格式

//第一行包含一个正整数 $n$，表示需要的铅笔数量。

//接下来三行，每行用 $2$ 个正整数描述一种包装的铅笔：
//其中第 $1$ 个整数表示这种包装内铅笔的数量，第 $2$ 个整数表示这种包装的价格。

//保证所有的 $7$ 个数都是不超过 $10000$ 的正整数。

#include <stdio.h>
int main (void)
{
    typedef struct 
    {
        int num;
        int price;
    } A ;
    int n;
    int i;
    int amount = 0;//初始化
    A a[3];
    scanf("%d",&n);
    for ( i = 0;i < 3;i++)
    {
        scanf ("%d %d",&a[i].num,&a[i].price);
    }//读取输入
    for (i = 0;i < 3;i++)
    {
        int j;
        int temp = 0;
        for(j = 0;j*a[i].num < n;j++)
        {
            temp += a[i].price;
        }
        if(i == 0)
        {
            amount =temp;
        }
        if (temp < amount)
        {
            amount = temp;
        }
    }
    printf ("%d\n",amount);
    return 0;

}
