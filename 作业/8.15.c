#include <stdio.h>

int * insert (int* S,int x,int n)
{
    int pos = 0;
    while (pos <= n && x > S[pos] )pos ++;
    memmove(S + pos + 1, S + pos, (n - pos) * sizeof(int));
    S[pos] = x;
}
void print(int S[], int n) {
    for (int i = 0; i < n; i++)
        printf("%3d", S[i]);
    printf("\n");
}
int main (void)
{
    int S[10] = {-1,0,2,3,4,4,5,6,};
    int x;scanf ("%d",&x);
    insert(S,x,10);
    print (S,10);
}