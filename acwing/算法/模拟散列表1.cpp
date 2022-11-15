//???
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 100003;

int h[N];
int e[N], ne[N], idx;

void insert(int x)
{
    int t = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[t];
    h[t] = idx++;
}
bool find(int x)
{
    int t = (x % N + N) % N;
    for (int i = h[t]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I')
            insert(x);
        else
        {
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
