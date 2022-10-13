# include <stdio.h>
# include <stdlib.h>
int main ()
{   
   char a[60],b[60],c[60],d[60];
   scanf("%s %s %s %s",a,b,c,d);
   char DAY [7][5]={"MON","TUES","WED","THU","FRI","SAT","SUN",};
   int i,k;
   int step=0;
   for(i=0;i<60;i++)
   {
      if(a[i]==b[i])
      {
         if(a[i]>='A'&&a[i]<='G'&&step==0)
         {
            printf("%s ",DAY[a[i]-'A']);
            step++;
            continue;
         }
         if(step)
         {
           if(a[i]<='9'){
            printf("0%d :",a[i]);
            break;
           } else if(a[i]>='A'&&a[i]<='N')
           {
            printf("%d :",a[i]-'A'+10);
            break;
           }

     
         }
      }
   }
   for(k=0;k<60;k++)
   {
      if(c[k]==d[k])
      { 
         if (c[k]>='A'&&c[k]<='z')
         {
         if(k<10){
            printf("0%d\n",k);
            break;   
         }else {
            printf("%d\n",k);
            break;
         }
        
         }
      }
   }
   return 0;
}