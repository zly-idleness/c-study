#include <stdio.h>
int hour,minute,second;
void Update()
{
    second++;
    if(second == 60){second = 0;minute++;}
    if(minute == 60){minute = 0;hour++;}
    if(hour == 24){hour = 0;}
}
void Display()
{printf ("%d :%d :%d\n",hour,minute,second);}
void Delay (){for (int t = 0;t < 1000000000;t++);}
int main (void)
{
    for(int i = 0;i < 1000000;i++)
    {Update();Display();Delay();}
}