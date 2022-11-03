#include <iostream>

#define N 100010

using namespace std;
void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r + 1 >> 1;
    merge_sort(q, mid, r);
    merge_sort(q, l, mid - 1);

    int i = l, j = mid;
    int cnt = 0;
    int tmp[r - l + 1];

    while (i <= mid - 1 && j <= r)
    {
        if (q[i] <= q[j])
            tmp[cnt++] = q[i++];
        else
            tmp[cnt++] = q[j++];
    }
    while (i <= mid - 1)
        tmp[cnt++] = q[i++];
    while (j <= r)
        tmp[cnt++] = q[j++];
    for (int i = l, k = 0; i <= r; k++, i++)
        q[i] = tmp[k];
}

int main()
{
    int n;
    scanf("%d", &n);
    int q[N];
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
}