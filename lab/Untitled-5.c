#include<stdio.h>
#include<math.h>
int main()
{
    int h,m=0;
    double ans=0;
    printf("Please input time\n");
    scanf("%dh%dm",&h,&m);
    if(h >= 0 && h <= 12 && m >= 0 && h <= 60)
    {
        double d1 = h*30.0 + 0.5*m;
        double d2 = 6.0 * m;
        ans=fabs(d1-d2);
        if(ans > 180)   ans = 360-ans;
        if(m == 0)printf("At %2d:00 the angle is %.1lf degrees.\n",h,ans);
        else{
            printf("At %d:%02d the angle is %.1lf degrees.\n",h,m,ans);
        }
    }
}