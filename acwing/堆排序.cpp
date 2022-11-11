#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], cnt;

void down(int x)
{
    int s = x;
    if (x * 2 <= cnt && h[x * 2] < h[s])
        s = x * 2;
    if (x * 2 + 1 <= cnt && h[x * 2 + 1] < h[s])
        s = x * 2 + 1;
    if (x != s)
    {
        swap(h[x], h[s]);
        down(s);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    cnt = n;

    for (int i = n / 2; i >= 0; i--)
        down(i);
    while (m--)
    {
        printf("%d ", h[1]);
        h[1] = h[cnt--];
        down(1);
    }
    puts(" ");
    return 0;
}