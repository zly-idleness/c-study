#include <stdio.h>
void  LCM (int a,int b)
{
    for (int i = 0;i >= 0 ;i++)  { if (i == a*b)   {  printf("%d\n",i) ; break ;}  }
}
int main (void)
{
    int a,b ;
    printf("please input two numbers :\n");
    scanf ("%d%d",&a,&b);
    LCM (a,b);
    return 0;    
}