#include <stdio.h>

int age (int i)
{if(i == 1)return 10;  else return age (i-1)+2;}
int main (void)
{
    printf ("%d\n",age(5));
    return 0;
}