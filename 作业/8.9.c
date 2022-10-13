#include <stdio.h>

int main (void)
{
    int n; scanf("%d",&n);
    int matrix [n][n];
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            scanf ("%d",&matrix[i][j]);
    int diagonal = 0;
    int antidiagonal = 0;
    for (int i = 0;i < n;i++)
    {   diagonal += matrix[i][i] ; antidiagonal += matrix [i][n-i-1];  }
    printf ("%d %d\n",diagonal,antidiagonal);
    return 0;
}
