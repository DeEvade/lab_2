#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
  char *arr = (char *)malloc(n * sizeof(char));

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
  free(arr);
}

int main(void)
{
  clock_t start, end;
  start = time(NULL);
  print_sieves(100000000);
  end = time(NULL);
  double execution_time = (double)(end - start);

  printf("\n");
  printf("%lf", execution_time);

  return 0;
}