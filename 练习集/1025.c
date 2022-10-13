#include <stdio.h>
int main ()
{   
    typedef struct 
    {
       int Address;
       int Data;
       int Next; 
    }S;
    int i;
    int addr,N,K;//初始化
    S origin[100001],outp[100001];//创建初始链表&输出链表
    scanf("%d %d %d",&addr,&N,&K);//读入首行数据
     for(i = 0;i < N; i++) 
     { 
         S temp;
         scanf("%d %d %d",&temp.Address,&temp.Data,&temp.Next);
         origin[temp.Address] = temp;
     }//遍历赋值 读入节点
     for(i = 0;i < N; i++)
     {
      outp[i] = origin[addr];
      addr=outp[i].Next;
      if(addr==-1)
      {
         N = i+1;
         break;
      }
     }//链接节点
     for (i = 0;i < N/K; i++)
     {
      for(int j = 0;j < K/2; j++)//反转
      {
         S temp;
         temp = outp[j+i*K];
         outp[j+i*K] = outp[i*K+K-1-j];
         outp[i*K+K-1-j] = temp;

      }
     }
      for(i = 0;i < N; i++)
      {
         if(i != N-1)
         {
         outp[i].Next = outp[i+1].Address;//重新链接
         printf("%05d %d %05d\n",outp[i].Address,outp[i].Data,outp[i].Next);
         } else 
         {
            printf("%05d %d %d\n",outp[i].Address,outp[i].Data,outp[i].Next);
         }
      }//输出
   return 0;
}
