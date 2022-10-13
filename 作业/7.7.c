#include <stdio.h>
void  GCD (int a,int b)
{
    for (int i = a;i >= 1;i--)
    if(a%i == 0 && b%i == 0) {  printf("%d\n",i); break ;  }  
}
int main (void)
{
    int a,b ;
    printf("please input two numbers :\n");
    scanf ("%d%d",&a,&b);
    GCD (a,b);
    return 0;    
}