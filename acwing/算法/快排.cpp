
#include <iostream>
#define N 100010
using namespace std;

int q[N];
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int x = q[l + r >> 1];

    int i = l - 1, j = r + 1;
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
        else break;
    }
    quick_sort(q, j + 1, r);
    quick_sort(q, l, j );
}
int main()
{
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
}
