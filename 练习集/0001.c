//# 小玉买文具

//题目描述

//班主任给小玉一个任务，到文具店里买尽量多的签字笔。已知一只签字笔的价格是 1元 9 角，
//而班主任给小玉的钱是 a元 b角，小玉想知道，她最多能买多少只签字笔呢。

// 输入格式

//输入只有一行两个整数，分别表示 $a$ 和 $b$。

// 输出格式

//输出一行一个整数，表示小玉最多能买多少只签字笔。
#include <stdio.h>
#define price 19
int main ()
{
    int a,b;
    int amount,num;
    scanf("%d %d",&a,&b);
    amount = a*10+b;
    num = amount / price ;
    printf ("%d\n",num);
    return 0;


}

