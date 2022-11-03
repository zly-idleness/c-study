#include <stdio.h>
int f(int Mon)
{
    if (Mon == 0)
        return 0;
    if (Mon == 1)
        return 31;
    if (Mon == 2)
        return 28 + f(1);
    if (Mon == 4 || Mon == 9 || Mon == 6 || Mon == 11)
        return 30 + f(Mon - 1);
    else
        return 31 + f(Mon - 1);
}
int main(void)
{
    printf("请输入日期（年，月，日）\n");
    int Y, M, D;
    scanf("%d,%d,%d", &Y, &M, &D);
    int sum = 0;
    if (Y % 4 == 0 && Y % 100 != 0 && M > 2)
        sum = D + f(M - 1) + 1;
    else
        sum = D + f(M - 1);
    printf("\n%d月%d日是%d年的第%d天。", M, D, Y, sum);
}