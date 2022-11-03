#include <stdio.h>
#include <math.h>

int main()
{
    double n;
    scanf("%lf", &n);
    double left = 0.0, right = n, res = 0.0;
    if (n < 0)
    {
        left = n, right = 0.0;
    }

    while (fabs((n - res)) >= 1e-8)
    {
        double mid = (left + right) / 2;
        res = mid * mid * mid;
        if (res < n)
            left = mid;
        else
            right = mid;
    }

    printf("%f", left);
    return 0;
}