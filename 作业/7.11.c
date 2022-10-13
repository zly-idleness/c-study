#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define sum 30

int type (int i)
{
    if (i % 3 == 1)return 1;
    if (i % 3 == 2)return 2;
    else return rand ()%2 + 1;
}

int main (void)
{
    printf ("游戏开始!\n");
    int domi ;//支配者
    int left = sum; //剩余量
    srand ( time(NULL) );
    int det ;
    det = rand ()%2;//决定顺序
    if (det == 0) domi = 1;else domi = 0;
    while(left >= 3)
    {
        if (domi == 0)
        {
            int choose = type (left);
            if (choose == 1){  printf("Robot : %d  ",sum - left + 1) ; left-- ; }
            if (choose == 2){  printf("Robot : %d  %d  ",sum - left +1, sum - left + 2) ; left -= 2 ;  }
            domi = 1;
        }
        if (domi == 1)
        {
            int n,a,b ;    printf ("您要报几个数字?\n") ;
            scanf ("%d",&n); printf("请输入您要报的数字\n") ;
            if (n == 1){  scanf ("%d",&a) ;  printf("player : %d  ",a) ; left-- ; }
            if (n == 2){  scanf ("%d",&a) ;  printf("player : %d  ",a) ; left-- ;
                          scanf ("%d",&b) ;  printf("player : %d  ",b) ; left-- ;  }
            domi = 0; 
        }
    }
    if (left < 3)
    {
        if  ( !domi )
        {
            if (left == 1)printf ("Robot : %d  ",sum - left + 1);
            else printf("Robot : %d  %d  ",sum - left +1, sum - left + 2);
        }
        printf ("游戏结束 赢家是:  ");
        if (domi) printf ("Player\n");
        else printf ("Robot\n");
        return 0;
    }
}