#include <stdio.h>

int main()
{
    double rate;
    int capital, n;
    double deposit;

    scanf("%d %d", &capital, &n);
    deposit = capital;

    switch (n)
    {
    case 1:
        rate = 0.0225;
        break;
    case 2:
        rate = 0.0243;
        break;
    case 3:
        rate = 0.0270;
        break;
    case 5:
        rate = 0.0288;
        break;
    case 8:
        rate = 0.0300;
        break;

    default:
        break;
    }
    for (int i = 0; i < n; i++)
    {
        deposit = deposit * (1 + rate);
    }
    printf("%f", deposit);
    return 0;
}