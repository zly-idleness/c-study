#include <stdio.h>

#define N 100010

void bsearch_1(int q[], int k, int l, int r) //урвС╠ъ╫Г
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (q[mid] <= k)
            l = mid;
        else
            r = mid - 1;
    }
    if (q[l] != k)
    {
        printf("-1 -1\n");
        return;
    }
    printf("%d ", l);
}
void bsearch_2(int q[], int k, int l, int r) //урср╠ъ╫Г
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (q[mid] >= k)
            r = mid;
        else
            l = mid + 1;
    }
    if (q[l] != k)
    {
        printf("-1 -1\n");
        return;
    }
    printf("%d\n", r);
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int S[N];

    for (int i = 0; i < n; i++)
        scanf("%d", &S[i]);

    for (int j = 0; j < q; j++)
    {
        int k;
        scanf("%d", &k);
        bsearch_1(S, k, 0, n - 1);
        bsearch_2(S, k, 0, n - 1);
    }
    return 0;
}