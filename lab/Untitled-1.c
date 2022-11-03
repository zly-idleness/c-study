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
        printf("����������\n");
    else
    {
        int flag = 0;
        if (fabs(a - b) <= 1E-2 && fabs(b - c) <= 1E-2)
        {
            printf("�ȱ�");
            flag = 1;
        }
        if ((fabs(a - b) <= 1E-2 && fabs(b - c) > 1E-2) || (fabs(a - b) > 1E-2 && fabs(b - c) <= 1E-2))
        {
            printf("����");
            flag = 1;
        }
        if (fabs(a * a + b * b - c * c) <= 1E-2)
        {
            printf("ֱ��");
            flag = 1;
        }
        if (!flag)
            printf("һ��");
        printf("������\n");
        float S, p;
        p = (a + b + c) / 2;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("S=%.02f\n", S);
    }

    return 0;
}
