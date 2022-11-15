# 算法复习用

- [算法复习用](#算法复习用)
  - [基础算法](#基础算法)
    - [快排](#快排)
    - [归并](#归并)
    - [二分查找](#二分查找)
    - [高精度](#高精度)
    - [前缀和](#前缀和)
    - [差分](#差分)
    - [双指针](#双指针)
    - [离散化](#离散化)
    - [区间合并](#区间合并)
  - [数据结构](#数据结构)
    - [数组模拟链表](#数组模拟链表)
    - [模拟栈](#模拟栈)
    - [模拟队列](#模拟队列)
    - [单调栈以及单调队列](#单调栈以及单调队列)
    - [kmp算法](#kmp算法)
    - [trie树](#trie树)
    - [并查集](#并查集)
    - [模拟堆](#模拟堆)
    - [模拟散列表](#模拟散列表)
    - [字符串哈希](#字符串哈希)

## 基础算法

### 快排

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

### 归并

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

### 二分查找

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

### 高精度

```cpp
#include <vector>
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

### 前缀和

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

### 差分

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

### 双指针

将O(n^2)优化至O(n)

```cpp

for (int i = 0,j = 0;i < n;i++)
{
    if(check(j,i))j++;
    //具体逻辑因题而异
}

```

### 离散化

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

### 区间合并

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
```

## 数据结构

### 数组模拟链表

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

### 模拟栈

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

### 模拟队列

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

### 单调栈以及单调队列

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

### kmp算法

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

### trie树

```cpp
使用son数组实现
数组元素储存当前节点的子节点的索引

int son[N][M],idx,cnt [N];
char str[N];

void insert (char* str)
{
    int p = 0;
    for(int i = 0 ;str[i];i++)
    {
        int u = str[i] - 'a';//因题而异
        if(!son[p][u])
            son[p][u] == ++idx;//不存在则创建新节点
        p = son[p][u];//搜索下一层
    }
    cnt[p]++;//到最后记录节点被搜索到的次数
} 
int query (char *str)
{
    int p = 0;
    for(int i = 0;str[i];i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];/返回节点被输入的次数
}
```  

应用案例

>在给定的 N 个整数 A1，A2……AN 中选出两个进行 xor（异或）运算，得到的结果最大是多少？

```cpp
int  n,idx;
int a[N],son[M][2];//二进制表示后下一位只能是0或1

void insert (int x)
{
    int p = 0;
    for(int i = 30;i >= 0;i--)//从最高位开始存储
    {
        int &s = son[p][x >> i &1];//提取当前位并映射到树上
        if(!s)//无该子节点
            s = ++idx;
        p = s;
    }
}

int search (int x)//贪心
{
    int p = 0;
    int res = 0;
    for(int i = 30;i >= 0;i--)
    {
        int u = x >>i & 1;
        if(son[p][!u])//存在异或结果
        {
            p = son[p][!u];
            res += 1 << i;
        }
        else p = son[p][u]//无奈之举
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

```

### 并查集

核心是find函数
每个集合有唯一的祖宗节点
ancester数组储存祖宗节点的索引

```cpp

int an[N];
int find (int x)
{
    if(an[x] != x)//祖宗节点的祖宗就是自己
        an[x] = find(an[x]);
    return an[x];
}
void merge (int a, int b)
{
    an[find(a)] = find(b);//将a的祖宗节点连接至b的祖宗节点
}
```

应用举例
>动物王国中有三类动物 A,B,C，这三类动物的食物链构成了有趣的环形。A 吃 B，B 吃 C，C 吃 A。
>现有 N 个动物，以 1∼N 编号。
>每个动物都是 A,B,C 中的一种，但是我们并不知道它到底是哪一种。
>有人用两种说法对这 N 个动物所构成的食物链关系进行描述：
>第一种说法是 1 X Y，表示 X 和 Y 是同类。第二种说法是 2 X Y，表示 X 吃 Y。
>此人对 N 个动物，用上述两种说法，一句接一句地说出 K 句话，这 K 句话有的是真的，有的是假的。
>当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
>当前的话与前面的某些真的话冲突，就是假话；当前的话中 X 或 Y 比 N 大，就是假话；当前的话表示 X 吃 X，就是假话。
>你的任务是根据给定的 N 和 K 句话，输出假话的总数。

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;

int p[N],d[N];//parent数组储存祖宗节点(该食物链顶端),distence数组储存到食物链顶端的距离

int find(int x)
{
    if(p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        p[i] = i;
    int cnt = 0;
    while(k--)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(x > n ||y > n)cnt++;
        else 
        {
            int px = find(x),py = find(y);
            if(t == 1)
            {
                if(p[x] == p[y] && (d[x] - d[y]) & 3)cnt++;//在一条食物链上且不是同类
                else if(px != py)//不在一条食物链上
                {
                    p[p[x]] = p[y];//合并食物链
                    d[p[x]] = d[y] - d[x];//更新到食物链顶端距离
                }
            }
            else if(t == 2)
            {
                if(px == py && (d[x] - d[y] -1) % 3)cnt++;//在一条食物链上且不是被吃关系
                else if(px != py)
                {
                    p[px] = p[y];//合并食物链
                    d[px] = d[y] - d[x] + 1;//更新距离
                }
            }
        }
    }
    cout << cnt <<endl;
    return 0;
}
```

### 模拟堆

构建二叉树
节点n的子节点是n*2和n*2+1
父节点总是比子节点 小or大

```cpp
int h[N],cnt;

void down(int x)
{
    int s = x;
    if(x * 2 <= cnt && h[x*2] < h[s])
        s = x * 2;
    if(x * 2 + 1 <= cnt && h[x * 2 + 1] < h[s])
        s = x * 2 + 1;
    if(x != s)
    {
        swap(h[x],h[s]);
        down(s);
    }
}
void up(int x)
{
    int s =x / 2;
    if(h[s] > h[x])
    {
        swap(h[x],h[s]);
        x /= 2;
        up(x);
    }
}
```

应用举例
>维护一个集合，初始时集合为空，支持如下几种操作：
>I x，插入一个数 x；
>PM，输出当前集合中的最小值；
>DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
>D k，删除第 k 个插入的数；
>C k x，修改第 k 个插入的数，将其变为 x；

```cpp
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
const int N = 100010;

int n;
int h[N],ph[N],hp[N];//pointer heap数组储存第k个数对应的节点序号,heap pointer数组储存第m个节点对应的插入序号
int cnt,idx;

void heap_swap(int x,int y)//传入节点序号
{
    swap(ph[hp[x]],ph[hp[y]]);
    swap(hp[x],hp[y]);
    swap(h[x],h[y]);
}

void down(int x)
{
    int s = x;
    if(x * 2 <= cnt && h[x*2] < h[s])
        s = x * 2;
    if(x * 2 + 1 <= cnt && h[x * 2 + 1] < h[s])
        s = x * 2 + 1;
    if(x != s)
    {
        heap_swap(h[x],h[s]);
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
    cin >> n;
    while(n--)
    {
        char op[5];
        int k,x;
        scanf("%s",op);
        if(!strcmp(op,"I"))
        {
            scanf("%d",&x);
            cnt++;idx++;
            ph[idx] = cnt;
            hp[cnt] = idx;
            h[cnt] = x;
            up(cnt);
        }
        else if(!strcmp(op,"PM"))
            printf("%d\n",h[1]);
        else if(!strcmp(op,"DM"))
        {
            heap_swap(1,cnt);
            cnt--;
            down(1);
        }
        else if(!strcmp(op,"D"))
        {
            scanf("%d",&k);
            k = ph[k];
            heap_swap(k,cnt);
            cnt--;
            up(k);
            down(k);//只会执行一种
        }
        else if(!strcmp(op,"C"))
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
```

### 模拟散列表

拉链法

```cpp

#include <iostream>
#include <cstring>

using namespace std;
const int N = 100003;

int h[N];
int e[N],ne[N],idx;

void insert(int x)
{
    int t (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[t];
    h[t] = idx;
}
bool find(int x)
{
    int t = (x % N + N) % N;
    for(int i h[t];i != -1;i = ne[i])
        if(e[i] == x)
            return true;
    return false;
}

int main()
{
    int n;scanf("%d",&n);
    memset (h,-1,sizeof h);

    while(n--)
    {
        char op [2];
        int x;
        scanf("%s%d",op,&x);

        if(*op == 'I')
            insert(x);
        else
        {
            if(find(x))
                puts("Yes");
            else puts("no");
        }        
    }
        return 0;
}
```

开放寻址法

```cpp
const int N= 200003;//开两到三倍,保证坑位充足
const int null = 0x3f3f3f3f;

int h[N];

int find(int x)//返回应该插入的坑位序号
{
    int t = (x % N + N) % N;

    while(h[t] != null && h[t] != x)//当前坑位有人且不是自己
    {
        t++;
        if(t == N)//到尾部就从头找坑
            t = 0;
    }
    return t;
}
void insert (int x)
{
    h[find(x)] = x;
}

```

### 字符串哈希

kmp的一种替代

>给定一个长度为 n 的字符串，再给定 m 个询问，每个询问包含四个整数 l1,r1,l2,r2，请你判断 [l1,r1] 和 [l2,r2] 这两个区间所包含的字符串子串是否完全相同。

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, P = 131;

typedef unsigned long long ULL;

char str[N];
ULL h[N] ,p[N];//hash数组储存1-i的子串转换成P进制的数,p数组储存p的幂
ULL get(int l,int r)
{
    return h[r] - h[l-1] * p[r - l + 1];//,提取p进制下第l-r位数字,等价于提取l-r的子串
}

int main ()
{
    scanf("%d%d%",&n,&m);
    sacnf("%s",str + 1);
    p[0] = 1;
    for(int i = 0;i < n;i++)
    {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i-1] * P;
    }
    while(m--)
    {
        int l1, l2, r1, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (get(l1, r1) == get(l2, r2))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

```
