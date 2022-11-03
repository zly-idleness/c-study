#include <iostream>

#define N 100010
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int a[N], s[N];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;