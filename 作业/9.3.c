#include <stdio.h>
void Swap(int* x,int* y);
int main()
{
    int A[10];  int B[10];
    for(int i = 0;i < 10;i++)
    {
        A[i] = i;   B[i] = 10 - i;
    }
    int* x = A ;  int* y = B;
    for(int j = 0;j < 10;j++)
    {
        Swap(x,y);
        printf("%d  %d\n",*x,*y);
        x++;y++;
    }
}
void Swap(int* x,int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}