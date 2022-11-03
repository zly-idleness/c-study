#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float a, b, c;

void sort(float a, float b, float c)
{
    if (a > b && fabs(a - b) > 1E-2)
    {
        float temp = a;
        a = b;
        b = temp;
    }
    if (b > c && fabs(b - c) > 1E-2)
    {
        float temp = b;
        c = b;
        c = temp;
    }
    if (a > b && fabs(a - b) > 1E-2)
    {
        float temp = a;
        a = b;
        b = temp;
    }
}
int main()
{

    scanf("%f%f%f", &a, &b, &c);
    sort(a, b, c);
    if (c > a + b)
        printf("不是三角形\n");
    else
    {
        int flag = 0;
        if (fabs(a - b) <= 1E-2 && fabs(b - c) <= 1E-2)
        {
            printf("等边");
            flag = 1;
        }
        if ((fabs(a - b) <= 1E-2 && fabs(b - c) > 1E-2) || (fabs(a - b) > 1E-2 && fabs(b - c) <= 1E-2))
        {
            printf("等腰");
            flag = 1;
        }
        if (fabs(a * a + b * b - c * c) <= 1E-2)
        {
            printf("直角");
            flag = 1;
        }
        if (!flag)
            printf("一般");
        printf("三角形\n");
        float S, p;
        p = (a + b + c) / 2;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("S=%.02f\n", S);
    }

    return 0;
}
