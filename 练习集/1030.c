#include <stdio.h>
int main()
{
    int N,p;
    int i;
    int cnt=0,min;
    scanf("%d %d",&N,&p);
    int a[N];
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
   min=a[0];
    for(i=0;i<N;i++){
        if(min>=a[i]){
            min=a[i];
        }
    }
    for(i=0;i<N;i++){
        if(a[i]<=min*p){
            cnt++;
        }
    }
    printf("%d",cnt);

}