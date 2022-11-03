#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
        {
            if (A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    int cnt = 0;
    int temp1 = 0;
    for (int i = 0; i < N; i++)
    {
        if (temp1 == A[i] && temp1 != 0)
        {
            continue;
        }
        else
        {
            cnt++;
            temp1 = A[i];
        }
    }
    printf("%d\n", cnt);
    int temp2 = 0;
    for (int i = 0; i < N; i++)
    {
        if (temp2 == A[i] && temp2 != 0)
        {
            continue;
        }
        else
        {
            printf("%d ", A[i]);
            cnt++;
            temp2 = A[i];
        }
    }
    return 0;
}