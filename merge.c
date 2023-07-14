#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void merge(int a[], int lb, int mp, int ub)
{
    int i, j, k;
    int n1 = mp - lb + 1;
    int n2 = ub - mp;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = a[lb + i];
    } // create left helf temp array
    for (j = 0; j < n2; j++)
    {
        R[j] = a[mp + 1 + j];
    } // create right half temp array
    i = 0;
    j = 0;
    k = lb;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    { // if remaining in left half
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    { // if remaining in right half
        a[k] = R[j];
        j++;
        k++;
    }
    printf("Left half:");
    for (int x = 0; x < n1; x++)
        printf(" %d ", L[x]);
    printf("\n");
    printf("Right half:");
    for (int x = 0; x < n2; x++)
        printf(" %d ", R[x]);
    printf("\n");
}
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
        printf("Parent array:");
        for (int x = 0; x < 10; x++)
            printf(" %d ", a[x]);
        printf("\n\n");
    }
}
int main()
{
    int a[] = {9, 6, 5, 0, 8, 2, 7, 1, 3, 4};
    //    int a[10];
    //    printf("Enter 10 numbers of less than 10:");
    //    for(int i=0;i<10;i++){
    //        scanf("%d",&a[i]);
    //    }
    //    for(int i=0;i<10;i++){
    //        if(a[i]>=10){
    //            printf("Invalid input found. exiting"); return;}
    //    }
    printf("Valid original array:");
    for (int x = 0; x < 10; x++)
        printf(" %d ", a[x]);
    printf("\n");
    mergeSort(a, 0, 9);
    printf("Final sorted array:");
    for (int x = 0; x < 10; x++)
        printf(" %d ", a[x]);
    printf("\n");
    return 0;
}