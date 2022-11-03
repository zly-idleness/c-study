#include <stdio.h>
int year,month;
int IsRun(int year)
{
    if(( year%4 == 0 && year%100 != 0 ) || year%400 == 0)return 1;
    else return 0;
}
int f (int Mon)
{
    if (Mon == 0)return 0;
    if (Mon == 1)return 31;
    if (Mon == 2 && IsRun(year) == 1)return 29 +f(1);
    if (Mon == 2 && IsRun(year) == 0)return 28 +f(1);
    if (Mon == 4 || Mon == 9 || Mon == 6 || Mon == 11)return 30 + f(Mon-1);
    else return 31 + f(Mon-1);
}
int Ds(int Mon)
{
    if (Mon == 0)return 0;
    if (Mon == 1)return 31;
    if (Mon == 2 && IsRun(year) == 1)return 29;
    if (Mon == 2 && IsRun(year) == 0)return 28;
    if (Mon == 4 || Mon == 9 || Mon == 6 || Mon == 11)return 30;
    else return 31;
}
void calendar(int year,int month)
{
    int days = (year - 1900) * 365  + (year-1900) / 4;
    int Day1 = 1 + days;
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    Day1 += f(month-1);if(IsRun(year))Day1--;
    Day1 = Day1 % 7;
    for (int i = 0;i < Day1;i++)printf("\t");
    int D = Ds(month);
    for (int i = 1;i <= D;i++)
    {
        if (Day1 == 6)
        {
            printf("%d\t\n",i);
            Day1 = 0;
        }
        else { printf("%d\t",i); Day1 ++; }
    }
    
}
int main ()
{
    scanf("%d %d",&year,&month);
    calendar(year,month);
}
