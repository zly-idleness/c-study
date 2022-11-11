#include <iostream>

using namespace std;

const int N = 100010;

int an[N];

int find(int x) //�������ڽڵ㲢����x�����ڽڵ�
{
    if (an[x] != x)
        an[x] = find(an[x]);
    return an[x];
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        an[i] = i;

    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M')
            an[find(a)] = find(b);
        else
        {
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}