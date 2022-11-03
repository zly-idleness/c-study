# �㷨��ϰ��

## ����

```cpp

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1;
    int x = q[l + r >> 1];
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, j + 1, r);
    quick_sort(q, l, j);
}
```

## �鲢

```cpp
void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(q, mid + 1, r);
    merge_sort(q, l, mid);

    int cnt = 0;
    int tmp[r - l + 1];
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[cnt++] = q[i++];
        else
            tmp[cnt++] = q[j++];
    }
    while (i <= mid)
        tmp[cnt++] = q[i++];
    while (j <= r)
        tmp[cnt++] = q[j++];
    for (int i = l, k = 0; i <= r; i++, k++)
        q[i] = tmp[k];
}
```

## ���ֲ���

```cpp
void bsearch(int q[], int l, int r, int x)
{
    if (l >= r)
        return;
    while (l < r)
    {
        int mid = l + r >> 1; //��˵�
        if (q[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (q[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
}
```

## �߾���

```cpp
# include <vector>
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A);
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size();i++)
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t)
    C.push_back(t);
    return C;
}
```

## ǰ׺��

```cpp
int S[N][N];
for (int i = 0;i < n;i++)
    for(int j = 0;j < m;j++)
    scanf("%d",&S[i][j]);
for (int i = 0;i < n;i++)
    for(int j = 0;j < m;j++)
    s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
```

## ���

```cpp

int a[N][N],b[N][N];

void insert(int x1,int y1,int x2,int y2,c)
{
    b[x1][y1] += c;
    b[x2+1][y1] -= c;
    b[x1][y2 +1] -= c;
    b[x2+1][y2+1] += c;
}

```

�������ǰ׺�;���ԭ����

## ˫ָ��

��O(n?)�Ż���O(n)

```cpp

for (int i = 0,j = 0;i < n;i++)
{
    if(check(j,i))j++;
    //�����߼��������
}

```

## ��ɢ��

��Ҫ��������Χ���ǽ�ϡ�������
����: �� dom A ӳ������Ȼ����
��������  
>  
�ٶ���һ�����޳������ᣬ������ÿ�������ϵ������� 0��

���ڣ��������Ƚ��� n �β�����ÿ�β�����ĳһλ�� x �ϵ����� c��

������������ m ��ѯ�ʣ�ÿ��ѯ�ʰ����������� l �� r������Ҫ��������� [l,r] ֮����������ĺ͡�
>

```cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

vector<PII> add,query;
vector<int> alls;

int a[N],s[N];
int n,m;

int find(int x)
{
    int l = 0,r = alls.size() - 1;
    while(l < r)
    {
        int mid = l+r >>1;
        if(alls[mid] >= x)r = mid;
        else l = mid + 1;
    }
    return r + 1; //Ϊ�˷�����ǰ׺��,����ʹӳ�䵽��������
}

int main ()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
    {
        int x,c;
        scanf("%d%d",%x,%c);
        add.push_back({x,c});
        alls.push_back(x);
    }//�����������
    for(int i = 0;i < m;i++)
    {
        int l ,r;
        scanf("%d%d",&l,&r);
        query.push_back({l,r});
        
        alls.push_back(l);//����ڵ� ��ֹ����������
        alls.push_back(r);
    }//�����������
    
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    //����ȥ��

    for(auto item : add)
    {
        int x = find(item.first);//�õ�ӳ��
        a[x] += item.second;//��ӳ�伯��ֵ
    }
    for (int i = 0;i < alls.size();i++)
        s[i] = s[i - 1] + a[i];//��ǰ׺��
    for(auto item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        cout <<s[r] - s[l-1] << endl
    }
    return 0;
}

```

## ����ϲ�

������̰��

``` cpp

void merge (vector<PII> &A)
{
    vector<PII> & res;

    sort(A.begin(),A.end());

    int l = -2e9,r = -2e9;

    for(auto a : A)
    {
        if(r < a.first)//�ұ߽������������
        {    
            res.push_back({l,r});
            l = a.first;
            r = a.second;
        }
        else 
            r = max(r,a.second);
    }
    if(l != -2e9)
        res.push_back({l,r});
    
    a = res;//��������
}
