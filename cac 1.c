#include <stdio.h>
#include <conio.h>
void findNumber(int[], int);

int main()
{
    int n, i, num[6];
    printf("\n Enter 6 elements in array: ");
    for (i = 0; i < 6; i++)
        scanf("%d", &num[i]);
    printf("\n Enter element to be searched: ");
    scanf("%d", &n);
    findNumber(num, n);
    return 0;
}

void findNumber(int num[], int n)
{
    int i, count = 0;
    for (i = 0; i < 6; i++)
    {
        if (num[i] == n)
        {
            count += 1;
            printf("\n Element %d present at position %d ", n, i + 1);
        }
    }
    if (count > 0)
        printf("\n Element found %d times ", count);
    else
       printf("\n Element not found");
}