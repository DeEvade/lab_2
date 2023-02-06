/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/

#include <stdio.h>

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


int main()
{

  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
  
}
