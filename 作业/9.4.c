#include <stdio.h>
void Swap(int* x,int* y);
int main()
{
    int A[10]; 
    for(int i = 0;i < 10;i++)scanf("%d",&A[i]);
    int max = A[0] ;int min = A[0];int pos1 = 0;int pos2 = 0;
    for(int j = 0;j < 10;j++)
    {
        if(A[j] > max){
            max = A[j];
            pos1 = j;
            }
        if(A[j] < min){
            min = A[j];
            pos2 = j;
            }
    }
    printf("%d  %d\n",max,min);
    Swap(&A[pos1],&A[pos2]);
    for(int i = 0;i < 10;i++)printf("%d ",A[i]);
}
void Swap(int* x,int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}