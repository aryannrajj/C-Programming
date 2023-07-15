#include <stdio.h>
int main()
{
  int a[5];
  int i,p,n;
  for(i=0;i<5;i++)
    scanf("%d",&a[i]);
    
  printf("\n batao bhai kaha insert kare kya insert kare");
  scanf("%d %d",&p,&n);
     a[p-1] = n;

    

     for(i=0;i<5;i++)
     printf(" %d ",a[i]);
return 0;
}