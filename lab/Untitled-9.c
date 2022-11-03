#include <stdio.h>

int n;

int Mean(int *x);
int Median(int *x);
int Mode(int *x);
int main()
{
    scanf("%d", &n);
    int A[40];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            if (A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }

    int mean, median, mode;
    int *x = &A[0];
    mean = Mean(x);
    median = Median(x);
    mode = Mode(x);
    printf("Mean=%d\nMedian=%d\nMode=%d\n", mean, median, mode);
    return 0;
}
int Mean(int *x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *x;
        x++;
    }
    return sum / n;
}
int Median(int *x)
{
    int ret = 0;
    if (n % 2 == 0)
    {
        return (*(x + n / 2) + *(x + n / 2 - 1)) / 2;
    }
    else
        return *(x + n / 2);
}
int Mode(int *x)
{
    int grade[11] = {0};
    int mode = 0;
    for (int i = 0; i < n; i++)
    {
        int a = *(x + i);
        grade[a]++;
    }
    for (int k = 1; k <= 10; k++)
    {
        if (grade[k] > grade[k - 1])
        {
            mode = k;
        }
    }
    return mode;
}