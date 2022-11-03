#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int a, b, c, d;
    scanf("%d/%d,%d/%d", &a, &b, &c, &d);
    if (a * d - b * c > 0)
        printf("%d/%d > %d/%d", a, b, c, d);
    if (a * d - b * c < 0)
        printf("%d/%d < %d/%d", a, b, c, d);
    if (a * d - b * c == 0)
        printf("%d/%d = %d/%d", a, b, c, d);
    return 0;
}
