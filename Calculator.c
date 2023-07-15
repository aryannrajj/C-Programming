#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
   int pp = 1;
    printf("\n\n----->>> !!..... Welcome To All In One Calculator.....!! <<-----");
     while(pp<10)
    {
       printf("\n\n Enter your choice...!!\n\n");
       printf("1. Addition... \n2. Substraction... \n3. Multiplication... \n4. Division(quotient)... \n");
       printf("5. Division(remainder)... \n6. Square... \n7. Cube... \n8. Log Value... \n9. Square-Root... \n10. Exit... \n ");
       float a,b;
       int n;
       scanf("%d",&n);

       switch(n)
       {
        case 1: 
             printf("enter two numbers :- ");
             scanf("%f %f",&a,&b);
             printf("sum = %f", a+b);
             break;
        case 2:
             printf("enter two numbers :- ");
             scanf("%f %f",&a,&b);
             printf("difference = %f", a-b);
             break;
        case 3:  
             printf("enter two numbers :- ");
             scanf("%f %f",&a,&b);
             printf("product = %f", a*b);
             break;
        case 4: 
             printf("enter two numbers :- ");
             scanf("%f %f",&a,&b);
             printf("quotient = %f", a/b);
             break;
        case 5: 
             printf("enter two numbers :- ");
             int l,m;
             scanf("%d %d",&l,&m);
             printf("remainder = %d",l%m);
             break;
        case 6: 
             printf("enter a number :- ");
             scanf("%f",&a);
             printf("square value = %f", pow(a,2));
             break;
        case 7: 
             printf("enter a number :- ");
             scanf("%f",&a);
             printf("cube value = %f", pow(a,3));
             break;
        case 8: 
             printf("enter a number :- ");
             scanf("%f",&a);
             printf("log value = %f", log(a));
             break;
        case 9: 
             printf("enter a number :- ");
             scanf("%f",&a);
             printf("square-root = %f", sqrt(a));
             break;
        case 10: exit(0);
             break;
         default : 
             printf ("\n \n enter a correct choice...!!");
      }
    }
    return 0;   
}
















