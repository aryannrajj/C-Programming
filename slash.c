#include <stdio.h>
int main()
{
    int n,i,j;
    printf ("enter no.");
    scanf ("%d",&n);
    for (i=0;i<n;i++)
    {
        for (j=i;j<n;j++)
        {
            printf (" ");                                           
                                     
        }
        printf ("*");
        
        printf ("\n");
    }
}