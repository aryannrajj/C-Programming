#include<stdio.h>
#include<conio.h>
int main()
{
    int n=5,ch, queue[n], fr=0,rr=0,i,j=1,x;
    x=n;
    while(1)
    {
    printf("\n 1. insert in queue. \n2. deletion in queue. \n3. exit.\n");
      scanf("%d",&ch);
      switch(ch){
         case 1:  //insertion
        if(rr == x)
            printf("queue is full.\n");
        else
        {
            printf("\n queue element no: %d :", j++);
            scanf("%d", &queue[rr++]);
        }
        break;
         case 2: //deletion
          if (fr == rr)
             printf("queue is empty.\n");
          else
          {
            printf("deleted element is: %d ", queue[fr++]);
            x++;
          }
          break;
          case 3: exit(0);
      }
       
    }
}