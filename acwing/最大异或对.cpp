#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 3100010;

int n;
int a[N], son[M][2], idx; // son���鴢�浱ǰ�ڵ���±�

void insert(int x)
{
    int p = 0;

    for (int i = 30; i >= 0; i--)
    {
        int &s = son[p][x >> i & 1]; //����p�ڵ���ӽڵ�
        if (!s)                      //����������򴴽�
            s = ++idx;
        p = s;
    }
}

int search(int x)
{
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--) //�����λ��ʼ
    {
        int u = x >> i & 1;
        if (son[p][!u]) //̰��  �����Һ͵�ǰλ��ͬ��
        {
            p = son[p][!u];
            res += 1 << i; //ת��ʮ���ƽ��
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