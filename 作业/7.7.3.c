#include <stdio.h>
int  GCD (int a,int b)
{
    if (a > b){return GCD (a - b,b);}
    else if (a < b){return GCD (a,b-a);}
    else return a ;
}
int main (void)
{
    int a,b ;
    int result ;
    printf("please input two numbers :\n");
    scanf ("%d%d",&a,&b);
     result = GCD (a,b);
     printf ("%d\n",result);
    return 0;    
}