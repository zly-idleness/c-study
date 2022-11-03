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
