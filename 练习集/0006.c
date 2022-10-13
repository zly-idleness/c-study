#include <stdio.h>

int main ()
{
    char x [100005];
    char y [100005];//x表示范文 y表示输入

    x[0] = '\n';y[0] = '\n';//初始化
    char ch ;//储存读入
    ch = getchar ();
    int i = 0;int j = 0;
    while (ch != 'F')//判断是否结束
    {
        if (ch == '<')//退格
        {
            if (x[i] != '\n')//换行
            {
                i --;
            }
        ch = getchar ();//重新读入
        continue;
        }
        x[++i] = ch;//赋值并移至下一位
        ch = getchar ();
    }
    //范文读入完毕
    while((ch < 'a' || ch > 'z') && ch != '.' && ch!=' ')
    {
        ch = getchar();
    }
    //排除无用字符

    while(ch != 'F')
    {
        if(ch == '<')
        {
            if(y[j] != '\n')
            {
              j--;
            }
            ch = getchar();
            continue;
        }
        y[++j] = ch;
        ch = getchar();
    }
    //同上,输入读取完毕

    double right = 0;
    int m;
    int n;

    i -=3;j -=3;
    for ( m = 1, n = 1;m <= i+1 && n <= j+1;)
    {
        if(x[m] == y[n] && x[m] != 10)//正确的
        {
            right++;//正确输入的字符数量++
        }
        if(x[m] == 10)//如果范文需要换行
        {
            while(y[n] != 10)//使读入的字符也跳到换行符
            {
                n++;
            }
            n++;
            m++;
            continue;
        }
        if(y[n] == 10)//同理
        {
            while(x[m] != 10)
            {
                m++;
            }
            n++;
            m++;
            continue;
        }
        m++;
        n++;
    }

    double T;  scanf ("%lf",&T);
    double ans = right / T;
    printf ("%.0f\n", 60 *ans);
    //输出

    return 0;//结束
}