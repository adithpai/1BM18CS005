#include<stdio.h>
 
int fib(int);
 
int main()
{
  int n, i = 0, c;
  printf("Enter the nth term");
  scanf("%d", &n);
 
  printf("Fibonacci series terms are:\n");
 
  for (c = 1; c <= n; c++)
  {
    printf("%d\n", fib(i));
    i++;
  }
 
  return 0;
}
 
int fib(int n)
{
  if (n == 0 || n == 1)
    return n;
  else
    return (fib(n-1) + fib(n-2));
}

