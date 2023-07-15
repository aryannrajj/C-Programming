#include <stdio.h>
int main ()
{
    forward_slash ();
    backward_slash ();
    forward_slash ();
    backward_slash ();
    forward_slash ();
    backward_slash ();
    forward_slash ();
    backward_slash ();
    forward_slash ();
    backward_slash ();
    return 0;
}
void forward_slash ()
{
    int n=5,i,j,k;
    for (i=0;i<n;i++)
    {
        for (j=i;j<n;j++)
        {
            printf (" ");
        }
        for (k=1;k<2;k++)
        {
        printf ("*");
        }
        printf ("\n");
    }
}
void backward_slash ()
{
    int n=5,i,j,k;
    for (i=0;i<n;i++)
    {
        for (j=0;j<i;j++)
        {
            printf (" ");
        }
        for (k=1;k<2;k++)
        {
        printf ("*");
        }
        printf ("\n");
    }
}