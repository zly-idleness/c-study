#include <stdio.h>
int main()
{
    int n;
    int t;
    int cnt=0;
    scanf("%d",&n);
    do{
        if(n%2==0){
            n/=2;
            cnt++;
        }else{
            t=n*3+1;
            n=t/2;
            cnt++;
        }
    }while(n!=1);
    printf("%d\n",cnt);
    return 0;
}