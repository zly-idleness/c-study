#include <stdio.h>
int main(void)
{
    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        int N;
        scanf("%d", &N);
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            int temp;
            scanf("%d", &temp);
            int flag = 0;
            for (int k = 2; k <= temp / 2; k++)
                if (temp % k == 0)
                    flag = 1;
            if (temp == 1)
                flag = 1;
            if (!flag)
                sum += temp;
        }
        printf("%d\n", sum);
    }
    return 0;
}