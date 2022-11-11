#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
const int N = 100010;

int n;

int h[N], ph[N], hp[N];
int cnt, idx;

void heap_swap(int x, int y)
{
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}
void down(int x)
{
    int s = x;
    if (x * 2 <= cnt && h[x * 2] < h[s])
        s = x * 2;
    if (x * 2 + 1 <= cnt && h[x * 2 + 1] < h[s])
        s = x * 2 + 1;
    if (x != s)
    {
        heap_swap(x, s);
        down(s);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u /= 2;
    }
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        char op[5];
        int k, x;

        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            cnt++;
            idx++;
            ph[idx] = cnt;
            hp[cnt] = idx;
            h[cnt] = x;
            up(cnt);
        }
        else if (!strcmp(op, "PM"))
            printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}