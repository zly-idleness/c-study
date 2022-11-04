# 算法复习用

## 快排

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

## 归并

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

## 二分查找

```cpp
void bsearch(int q[], int l, int r, int x)
{
    if (l >= r)
        return;
    while (l < r)
    {
        int mid = l + r >> 1; //左端点
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

## 高精度

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

## 前缀和

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

## 差分

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

差分数组前缀和就是原数组

## 双指针

将O(n^2)优化至O(n)

```cpp

for (int i = 0,j = 0;i < n;i++)
{
    if(check(j,i))j++;
    //具体逻辑因题而异
}

```

## 离散化

主要用来处理范围大但是较稀疏的数据
核心: 将 dom A 映射至自然数集
例题如下  
>假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。
>现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c。
>接下来，进行 m 次询问，每个询问包含两个整数 l 和 r，你需要求出在区间 [l,r] 之间的所有数的和。

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
    return r + 1; //为了方便求前缀和,这里使映射到正整数集
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
    }//读入待查数据
    for(int i = 0;i < m;i++)
    {
        int l ,r;
        scanf("%d%d",&l,&r);
        query.push_back({l,r});
        
        alls.push_back(l);//读入节点 防止读不到数据
        alls.push_back(r);
    }//储存待查区间
    
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    //数据去重

    for(auto item : add)
    {
        int x = find(item.first);//得到映射
        a[x] += item.second;//对映射集赋值
    }
    for (int i = 0;i < alls.size();i++)
        s[i] = s[i - 1] + a[i];//求前缀和
    for(auto item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        cout <<s[r] - s[l-1] << endl
    }
    return 0;
}

```

## 区间合并

类似于贪心

``` cpp

void merge (vector<PII> &A)
{
    vector<PII> & res;

    sort(A.begin(),A.end());

    int l = -2e9,r = -2e9;

    for(auto a : A)
    {
        if(r < a.first)//右边界在现区间左边
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
    
    a = res;//交换容器
}

## 数组模拟链表

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

双链表同理

```cpp

int val[N],l[N],r[N],idx;

r[0] = 1;l[1] = 0;//初始节点

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

## 模拟栈

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

栈的应用举例
>给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

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
    /*核心思路是
    1.将数字与运算符分别读入
    2.贪心的思想,每次读入后只要能计算就计算
}

```

## 模拟队列

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

## 单调栈以及单调队列

核心:只存单调的元素

```cpp

int stk[N],tt;

int main()
{
    for(int i = 0;i < n;i ++)//应用在遍历中
    {
        int x;cin >> x;
        while(tt && stk[tt] >= x)
            tt--;
        if(!tt)
            printf("-1");
        else
        printf("%d",stk[tt]);//输出第一个比x小的数
        stk[++tt] = x; 
    }
    return 0;
}

```

滑动窗口

```cpp

int a[N],q[N];

int hh = 0,tt = -1;
for(int i = 0;i < n;i++>)
{
    if(hh <= tt && i - k + 1 > q[hh])//检查q[hh]是否滑出
        hh++;
    while(hh <= tt && a[q[tt]] >= a[i])//找第一个符合条件的数
        tt--;
    q[++tt] = i;//存入
    if(i >= k - 1)
        printf("%d"),a[q[hh]];
}

```

## kmp算法

应用场景:模式匹配
>给定一个字符串 S，以及一个模式串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。
>模式串 P 在字符串 S 中多次作为子串出现。
>求出模式串 P 在字符串 S 中所有出现的位置的起始下标。

```cpp

int n,m;
int ne[N];//对next[ j ] ，是p[ 1, j ]串中前缀和后缀相同的最大长度（部分匹配值）
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
    }//求出ne数组

    for(int i = 1,j = 0;i <= m;i++)
    {
        while(j && s[i] != p[j+1])
            j = ne[j];
        if(s[i] == p[j+1])
            j++;
        if(j == n)
        //匹配完毕可以输出
        printf("%d",i-n);
    } 
    return 0;
}

```
