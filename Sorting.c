#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define max 20
void bubblesort(int *a, int n);
void insertionSort(int *a, int n);
void selectionSort(int *a, int n);
void display(int *a, int n);
void sortedDisplay(int *a, int n);
int main()
{
  int i, n, ch, a[max];
  system("CLS");
  printf("\n Enter the size of array (upto 20): ");
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
    printf("\n\n");
    printf("1. Bubble sort\n2. Selection sort\n3. Insertion sort\n Enter your choice..!!\n\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      bubblesort(a, n);
      sortedDisplay(a, n);
      break;

    case 2:
      selectionSort(a, n);
      sortedDisplay(a, n);
      break;

    case 3:
      insertionSort(a, n);
      sortedDisplay(a, n);
      break;

    default:
      printf("Incorrect input");
    }
  return 0;
}

void display(int *a, int n)
{
  for (int x = 0; x < n; x++)
    printf(" %d ", a[x]);
  printf("\n");
}
void bubblesort(int *a, int n)
{
  int j, k = 1, temp, ef = 1;
  while ((k < n) && (ef))
  {
    ef = 0;
    for (j = 0; j < n - k; j++)
    {
      if (a[j] > a[j + 1])
      {
        ef = 1;
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
    k++;
    display(a, n);
  }
}

void sortedDisplay(int *a, int n)
{
  printf(" \n The sorted elements are: ");
  for (int i = 0; i < n; i++)
    printf(" %d ", a[i]);
  printf("\n");
}

void insertionSort(int *a, int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
    display(a, n);
  }
}

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int *a, int n)
{
  int i, j, mi;
  for (i = 0; i < n - 1; i++)
  {
    mi = i;
    for (j = i + 1; j < n; j++)
      if (a[j] < a[mi])
        mi = j;
    swap(&a[mi], &a[i]);
    display(a, n);
  }
}
