#include <stdio.h>
void swap (int* a,int* b)
{
    int temp = *a;
    *a = *b;    *b = temp;
}
void BubbleSort (int * S,int n)
{
    int NotOrder = 1;
    while(NotOrder)
    {
        NotOrder = 0;
        for (int i = 1;i < n;i++)
        {
            if(S[i-1] > S[i])
            { swap(&S[i - 1],&S[i]);  NotOrder = 1;}
        }
    }
}
int main (void)
{
    int S[8] = {5,4,3,22,3,7,4,};
    BubbleSort(S,8);
    for (int i = 0;i < 8;i++)
    printf("%d ",S[i]);
    printf("\n");
    return 0;
}