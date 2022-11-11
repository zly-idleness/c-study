#include <iostream>

using namespace std;

const int N = 100010;

int p[N], cnt[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }

    while (m--)
    {
        string op1;
        int a, b;

        cin >> op1;
        if (op1 == "C")
        {
            scanf("%d%d", &a, &b);
            a = find(a), b = find(b);
            if (a != b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if (op1 == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
        else if (op1 == "Q2")
        {
            cin >> a;
            a = find(a);
            printf("%d\n", cnt[a]);
        }
    }
    return 0;
}