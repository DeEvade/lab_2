/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/

#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

int SPACES_BETWEEN_NUMBERS = 8;

void calculate_amount_of_spaces(int prime_number)
{ // Probably not a good way to do this but i dont know what else to do
  int spaceCounter = SPACES_BETWEEN_NUMBERS;
  double number = prime_number;
  while (number >= 10)
  {
    number = number / 10;
    spaceCounter--;
  }

  while (spaceCounter > 0)
  {
    spaceCounter--;

    printf(" ");
  }
}

int is_prime(int n)
{

  for (int i = n - 1; i > 1; i--)
  { // Iterates through all positive numbers smaller than n
    if (n % i == 0)
    {           // Checks if n is dividable by i with no rest
      return 0; // n was dividable by i, hence n cannot be a prime number
    }
  }
  return 1;
}

void print_number(int n)
{
  calculate_amount_of_spaces(n);
  printf("%d", n);
}

void print_primes(int n)
{
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS

  /*  printf("%10d ", 2);
    printf("%10d ", 3);
    printf("%10d ", 5);
    printf("%10d ", 7);
    printf("%10d ", 11);
    printf("%10d ", 13);
    printf("\n");
    printf("%10d ", 17);
    printf("%10d ", 19);

    printf("\n");*/

  int COUNTER = 0; // The amount of primen numbers that have been counted

  for (int i = 2; i <= n; i++)
  {
    if (is_prime(i))
    {
      COUNTER++;
      print_number(i);
    }

    if (COUNTER == COLUMNS)
    {
      COUNTER = 0;
      printf("\n");
    }
  }
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[])
{
  if (argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}
