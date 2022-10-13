#include <stdio.h>
#include <math.h>
int main ()
{
   double a,b,c;
   scanf ("%lf %lf %lf",&a,&b,&c) ;
   if (b*b > 4*a*c )
   {
   printf("%f\n",(-b-sqrt(b*b-4*a*c))/2*a);
   printf("%f\n",(-b+sqrt(b*b-4*a*c))/2*a);
   }
   else 
   printf ("error\n");
   return 0;
}