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

��O(n^2)�Ż���O(n)

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
>�ٶ���һ�����޳������ᣬ������ÿ�������ϵ������� 0��
>���ڣ��������Ƚ��� n �β�����ÿ�β�����ĳһλ�� x �ϵ����� c��
>������������ m ��ѯ�ʣ�ÿ��ѯ�ʰ����������� l �� r������Ҫ��������� [l,r] ֮����������ĺ͡�

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

## ����ģ������

```cpp

int val[N],ne[N],idx,head;

void init()
{
    idx = 0;
    head = -1;
}
void insert(int k ,int x)
{
    val[idx] = x;
    ne[idx] = ne[k]; 
    ne[k] = idx++;
}
void add_to_head(int x)
{
    val[idx] = x;
    ne[idx] = head;
    head = idx ++;
}
void remove (int k)
{
    ne[k] = ne[ne[k]];
}

```

˫����ͬ��

```cpp

int val[N],l[N],r[N],idx;

r[0] = 1;l[1] = 0;//��ʼ�ڵ�

void insert(int a,int x)
{
    val[idx] = x;
    l[idx] = a;
    r[idx] = r[a];
    l[r[a]] = idx;
    r[a] = idx ++;
}

void remove (int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

```

## ģ��ջ

```cpp

int stk[N],tt = 0;

void push(int x)
{
    stk[++tt] = x;
}
void pop()
{
    tt--;
}
bool empty()
{
    return tt != 0;
}
void query()
{
    cout <<stk[tt] <<endl;
}

```

ջ��Ӧ�þ���
>����һ�����ʽ����������������� +,-,*,/���� �� �� �����������ܰ������ţ�����������ʽ������ֵ��

```cpp

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int>num;
satck<char>op;

void eval()
{
    auto b = num.top();num.pop();
    auto a = num.top();num.pop();
    auto c = op.top();op.pop();

    if(c == '(')return;
    int x;
    if(c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else if(c == '/')
        x = a / b;

    num.push(x);
}

int main()
{
    unordered_map<char,int>pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

    //to be complete
    /*����˼·��
    1.��������������ֱ����
    2.̰�ĵ�˼��,ÿ�ζ����ֻҪ�ܼ���ͼ���
}

```

## ģ�����

```cpp

int q[N],hh,tt = -1;


void push (int x)
{
    q[++tt] = x;
}
void pop()
{
    hh++;
}
bool empty()
{
    return hh > tt;
}
bool query()
{
    return q[hh];
}

```

## ����ջ�Լ���������

����:ֻ�浥����Ԫ��

```cpp

int stk[N],tt;

int main()
{
    for(int i = 0;i < n;i ++)//Ӧ���ڱ�����
    {
        int x;cin >> x;
        while(tt && stk[tt] >= x)
            tt--;
        if(!tt)
            printf("-1");
        else
        printf("%d",stk[tt]);//�����һ����xС����
        stk[++tt] = x; 
    }
    return 0;
}

```

��������

```cpp

int a[N],q[N];

int hh = 0,tt = -1;
for(int i = 0;i < n;i++>)
{
    if(hh <= tt && i - k + 1 > q[hh])//���q[hh]�Ƿ񻬳�
        hh++;
    while(hh <= tt && a[q[tt]] >= a[i])//�ҵ�һ��������������
        tt--;
    q[++tt] = i;//����
    if(i >= k - 1)
        printf("%d"),a[q[hh]];
}

```

## kmp�㷨

Ӧ�ó���:ģʽƥ��
>����һ���ַ��� S���Լ�һ��ģʽ�� P�������ַ�����ֻ������СдӢ����ĸ�Լ����������֡�
>ģʽ�� P ���ַ��� S �ж����Ϊ�Ӵ����֡�
>���ģʽ�� P ���ַ��� S �����г��ֵ�λ�õ���ʼ�±ꡣ

```cpp

int n,m;
int ne[N];//��next[ j ] ����p[ 1, j ]����ǰ׺�ͺ�׺��ͬ����󳤶ȣ�����ƥ��ֵ��
char s[M],p[N];

int main()
{
    cin >> n>> p+1>> m >> s+1;

    for(int i = 2,j = 0;i <= n;i++)
    {
        while(j && p[i] != p[j+1])
            j = ne[j];
        if(p[i] == p[j+1])
            j++;
        ne[i] = j;
    }//���ne����

    for(int i = 1,j = 0;i <= m;i++)
    {
        while(j && s[i] != p[j+1])
            j = ne[j];
        if(s[i] == p[j+1])
            j++;
        if(j == n)
        //ƥ����Ͽ������
        printf("%d",i-n);
    } 
    return 0;
}

```
