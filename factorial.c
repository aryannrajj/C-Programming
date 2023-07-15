#include <stdio.h>
#include <math.h>
 
int main ()
{
   int f=1, n;
   printf("Enter a number:- ");
   scanf(" %d",&n);

   for(int i=1; i<=n; i++)
       f=f*i;
   printf(" %d ", f);
    return 0;
}