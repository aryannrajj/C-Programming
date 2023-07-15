#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n;
    float a,b,c;
      int x,y;
    printf("Choose \n  1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n 5.division(remainder)\n 6.Square\n 7. cube\n 8.log value\n 9.square root\n");                          
    printf("Enter Your choice\n");
     scanf("%d",&n);
     switch (n)
    {
    case 1  :
        printf("Enter two numbers for addition\n");
        scanf("%f %f",&a,&b);
        c=a+b;
        printf(" The required output is %f\n",c);
        break;
    case 2:
        printf("Enter two numbers for subtraction\n");
        scanf("%f %f",&a,&b);
        c=a-b;
        printf(" The required output is %f\n",c);
        break;
    case 3:
        printf("Enter two numbers for multiplication\n");
        scanf("%f %f",&a,&b);
        c=a*b;
        printf(" The required output is %f\n",c);
        break;
   case 4:
        printf("Enter two numbers for division\n");
        scanf("%f %f",&a,&b);
        c=a/b;
        printf(" The required output is %f\n",c);
        break;
   case 5:  
        printf("Enter two numbers for division(remainder)\n");
        scanf("%d %d",&x,&y);
        c=x%y;
        printf(" The required output is %f\n",c);
        break;
   case 6:
        printf("Enter a number for its square value\n");
        scanf("%f",&a);
        c = pow(a,2);
        printf(" The required output is %f",c);
        break;
   case 7:
        printf("Enter a number for cube\n");
        scanf("%f ",&a);
        c=pow(a,3);
        printf(" The required output is %f",c);
        break;
   case 8:
        printf("Enter a number for its log value\n");
        scanf("%f ",&a);
        c=log(a);
        printf(" The required output is %f",c);
        break;
   case 9:
        printf("Enter a number for square root \n");
        scanf("%f ",&a);
        c=sqrt(a);
        printf(" The required output is %f",c );
        break;
    default:
    printf(" Input error\n");
        break;
    }
    return 0;
}