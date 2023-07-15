#include<stdio.h>
#include<stdlib.h>

int main()
{
   int a[2][2]= {2,3,4,5};
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][1] = 4;
    a[1][2] = 5;








       for(int i=0;i<2;i++)
       {
                
            for(int j=1; j<=2; j++)
             printf("%d",a[i][j]);
       }

    return 0;
    
}