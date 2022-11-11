#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;

int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int cnt = 0;
    while (k--)
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n)
            cnt++;
        else
        {
            int px = find(x), py = find(y);
            if (t == 1)
            {
                if (px == py && (d[x] - d[y]) % 3)
                    cnt++;
                else if (px != py)
                {
                    p[px] = p[y];
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3)
                    cnt++;
                else if (px != py)
                {
                    p[px] = p[y];
                    d[px] = d[y] - d[x] + 1;
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
