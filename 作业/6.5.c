#include <stdio.h>

int main ()
{
    double C,F;
    for (F = 0;F <= 300;F += 10)
    {
        C = (F - 32)*5 / 9;
        printf (" F = %f\t C = %f\t\n",F ,C);
    }
    return 0;
}
