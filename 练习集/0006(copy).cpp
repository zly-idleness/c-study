#include <cstdio>
#define reg register
using namespace std;
char s1[200007],s2[200007],ch;//s1表示范文，s2表示打字练习输入的字符
int cnt1,cnt2;
int ans;
int t;//最后读入的时间
int main()
{
    s1[0] = 10;s2[0] = 10;//ASCII码的10就等于'\n'表示换行符
    ch = getchar();//使用getchar加快速度
    while(ch != 'F')//读到'F'的时候就是结束符EOF的最后一位了，所以应该跳出循环
    {
        if(ch == '<')//判断是否读入了退格符
        {
            if(s1[cnt1] != 10)//如果退格符前面不是换行符
            {
                cnt1--;//刚刚读入的字符需要删去,把当前序号--
            }
            ch = getchar();//重新读入一个字符
            continue;//继续
        }
        s1[++cnt1] = ch;//如果不是换行符，那么就存入s1数组
        ch = getchar();//继续读入
    }
    //范文读取完毕
    while((ch < 'a' || ch > 'z') && ch != '.')
    {
        ch = getchar();
    }
    //为了防止读入无用字符，我们需要先把范文和实际输入之间的这些字符读取掉
    while(ch != 'F')//同上，将实际输入存入s2数组
    {
        if(ch == '<')
        {
            if(s2[cnt2] != 10)
            {
                cnt2--;
            }
            ch = getchar();
            continue;
        }
        s2[++cnt2] = ch;
        ch = getchar();
    }
    cnt1 -= 3;
    cnt2 -= 3;//由于我们刚刚读入时把"EOF"也同时存入了s1和s2数组，因此我们需要抛弃它们。所以cnt1和cnt2都要--
    for(reg int i = 1,j = 1;i <= cnt1 && j <= cnt2;)//开始对比s1和s2
    {
        if(s1[i] == s2[j] && s1[i] != 10)//如果s1和s2的这个字母相同并且s1的这个字符不是换行符
        {
            ans++;//正确输入的字符数量++
        }
        if(s1[i] == 10)//如果范文需要换行
        {
            while(s2[j] != 10)//我们需要使读入的字符也跳到换行符
            {
                j++;
            }
            i++;//继续对比下一行
            j++;
            continue;
        }
        if(s2[j] == 10)//同理，读入串需要换行也要都跳到下一行
        {
            while(s1[i] != 10)
            {
                i++;
            }
            i++;
            j++;
            continue;
        }
        i++;
        j++;
    }
    scanf("%d",&t);//读入耗费的时间
    printf("%.0lf",(double)ans / (double)t * 60);//题目要求四舍五入，所以使用printf%.0lf这样就会自动输出四舍五入的数字
    return 0;//Byebye程序 qwq
}
