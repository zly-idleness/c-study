#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 3100010;

int n;
int a[N], son[M][2], idx; // son数组储存当前节点的下标

void insert(int x)
{
    int p = 0;

    for (int i = 30; i >= 0; i--)
    {
        int &s = son[p][x >> i & 1]; //查找p节点的子节点
        if (!s)                      //如果不存在则创建
            s = ++idx;
        p = s;
    }
}

int search(int x)
{
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--) //从最高位开始
    {
        int u = x >> i & 1;
        if (son[p][!u]) //贪心  尽量找和当前位不同的
        {
            p = son[p][!u];
            res += 1 << i; //转化十进制结果
        }
        else
        {
            p = son[p][u];
        }
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        insert(a[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, search(a[i]));

    cout << ans << endl;
    return 0;
}