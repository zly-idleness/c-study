#include <stdio.h>
long long pell(int n)
{
    if(n == 1)return 1;
    if(n == 2)return 2;
    return (2*pell(n-1) + pell(n-2) );
}
int main(void)
{
    int n;scanf ("%d",&n);
    for (int i = 0;i < n;i++)
    {
        int data; scanf("%d",&data);
        long long ans = pell(data);
        printf("%lld\n",ans); 
    }
    return 0;
}