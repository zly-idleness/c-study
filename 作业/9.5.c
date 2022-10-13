#include <stdio.h>

int DayofYear (int year,int month,int day);
void MonthDay(int year,int yearday);
int IsRun(int year);
int f (int year,int Mon);

int main()
{
    printf("1.year/month/day->yearDay\n2.yearDay->year/month/day\n3.EXIT\n");
    printf("Please enter your choice: \n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                int year, month, day;
                scanf("%d/%d/%d",&year,&month,&day);
                printf("%d\n",DayofYear (year,month,day));
                break;
            }
        case 2:
            {
                int year;int yearday;
                scanf("%d%d",&year,&yearday);
                MonthDay(year,yearday);
                break;
            }
        case 3:break;
    }
    return 0;
}
int IsRun(int year)
{
    if(( year%4 == 0 && year%100 != 0 ) || year%400 == 0)return 1;
    else return 0;
}
int f (int year,int Mon)
{
    if (Mon == 0)return 0;
    if (Mon == 1)return 31;
    if (Mon == 2 && IsRun(year) == 1)return 29 +f(year,1);
    if (Mon == 2 && IsRun(year) == 0)return 28 +f(year,1);
    if (Mon == 4 || Mon == 9 || Mon == 6 || Mon == 11)return 30 + f(year,Mon-1);
    else return 31 + f(year,Mon-1);
}
int DayofYear (int year,int month,int day)
{
   int ret = f( year, month-1);
   ret += day;
   return ret;
}
void MonthDay(int year,int yearday)
{
    int mon = 0;int day = 0;
    for (int i = 1; i <= 12; i++)
    {
            if(yearday < f(year,i))
        {
            mon = i-1;break;
        }
    }
    day = yearday - f(year,mon);
    printf("%d/%d/%d",year,mon,day);
}