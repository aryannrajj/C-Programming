#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#define max 50

int Linearsearch(int a[], int no, int x);
int binarySearchIteration(int a[], int x, int low, int high);
int binarySearchRecursion(int a[], int x, int low, int high);
int main()
{
    int i, n, x, ch, ch1, a[max];
    system("CLS");
    printf("\n welcome to searching arena..!!\n");
    printf("\n Enter the size of array (upto 50): ");
    scanf("%d", &n);
    if (n > max)
    {
        printf("\n Please enter a number less than 20");
        exit(1);
    }
    time_t t1;
    srand((unsigned)time(&t1));
    printf("\n The random %d elements are:", n);
    for (i = 0; i < n; i++)
    {
        a[i] = (rand() % 100) + 1;
        printf(" %d ", a[i]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if (isdigit(a[i]) != 0)
    //     {
    //         printf("Only integers are allowed.");
    //         exit(0);
    //     }
    // }
    printf("\n Enter the element to be found.: ");
    scanf("%d", &x);
    loop1:
    printf("\n\n");
    printf("1. Linear Search.\n2. Binary Search.\n Enter your choice..!!\n\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        int result = Linearsearch(a, n, x);
        (result == -1) ? printf("Element not found") : printf("Element found at index: %d & position: %d", result, result + 1);
        break;

    case 2:
        printf("1. Binary search using iteration.\n2. Binary search using recursion.\n Enter your choice..!!\n\n");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1:
            int res = binarySearchIteration(a, x, 0, n - 1);
            (res == -1) ? printf("Element not found") : printf("Element found at index: %d & position: %d", res, res + 1);
            break;

        case 2:
            int resul = binarySearchRecursion(a, x, 0, n - 1);
            (resul == -1) ? printf("Element not found") : printf("Element found at index: %d & position: %d", resul, resul + 1);
            break;

        default:
            printf("Incorrect input");
            goto loop1;
        }
        break;
    default:
        printf("Incorrect input");
    }
    return 0;
}

int Linearsearch(int a[], int no, int x){
    for (int i = 0; i < no; i++)
        if (a[i] == x)
            return i;
    return -1;
}

int binarySearchIteration(int a[], int x, int low, int high){
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchRecursion(int a[], int x, int low, int high){
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return binarySearchRecursion(a, x, low, mid - 1);
        return binarySearchRecursion(a, x, mid + 1, high);
    }
    return -1;
}