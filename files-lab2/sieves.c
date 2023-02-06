#include <stdio.h>
#include <math.h>
#define COLUMNS 6

int count = 0;
void print_number(int n)
{
  if (count == COLUMNS)
  {
    printf("\n");
    count = 0;
  }
  count++;

  printf("%10d", n);
}



void print_sieves(int n)
{
  int arr[n];

  // Set all values in arr to 1
  for (int i = 0; i < n; i++)
  {
    arr[i] = 1;
  }

  for (int i = 2; i < sqrt(n); i++)
  {
    if (arr[i] == 1)
    {
      for (int j = i * i; j <= n; j += i)
      {
        arr[j] = 0;
      }
    }
  }

  for (int i = 2; i < n; i++)
  {
    if (arr[i] == 1)
    {
      print_number(i);
    }
  }
}

int main(void)
{
  print_sieves(1000000);

  return 0;
}