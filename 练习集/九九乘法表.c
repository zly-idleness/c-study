#include <stdio.h>
int main ()
{
    int n=9;
    int i=1;

    printf ("1\t2\t3\t4\t5\t6\t7\t8\t9\n");
    printf ("-\t-\t-\t-\t-\t-\t-\t-\t-\t\n");

    while(i<=n)
    {
        int j=1;
        while(j<=i){
            printf ("%d\t",j*i);
            j++;
        }i++;
        printf("\n");
    }
    return 0;
}