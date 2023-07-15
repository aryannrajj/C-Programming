
#include <stdio.h>
#include <math.h>
 
int main ()
{
     int a[5],i;
      int x,y;
      printf("enter positive numbers");
    for(int i=0;i<5;i++)
        scanf("%d",&a[i]);      
     x=a[0];
     y= -2147483648;
    for(i=0;i<5;i++)
    {
      
       if (x<a[i])
          x=a[i];  
          
    }
    for(i=0;i<5;i++)
    {
        if(y < a[i] && a[i]!=x)
          y= a[i];
    
    }

     printf("%d", y);
  return 0;

}
