#include <stdio.h>
int main ()
{
    int num;
    int sum = 0;
    scanf ("%d",&num);
    for(int i = 0;num>0;i++)
    {
        sum += num % 10;
        num /=10;
    }
    printf("%d",sum);
    return 0;
}