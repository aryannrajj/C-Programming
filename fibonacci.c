
// C code to illustrate
// the use of log function
 
#include <stdio.h>
#include <math.h>
 
int main ()
{
   int n,a=0,b=1,x;
   printf("Enter the no. of terms...");
   scanf("%d", &n);
   printf ("%d %d ",a,b);
   while(n != 2)
   {
      x=a+b;
      a=b; b=x;
      printf("%d ",x);
      n--;
   }

    
   return(0);
}