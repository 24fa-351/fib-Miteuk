#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fibonacci Functions
unsigned long long recursive(int n);
unsigned long long iterative(int n);

int main() 
{
   int number;
   char info; // for "r" or "i"
   char fileName[100];

   FILE *file;

   scanf("%d %c %s", &number, &info, fileName);

   int fileNum;

   file = fopen(fileName, "r");
   fscanf(file, "%d", &fileNum);
   fclose(file);

   int N = number + fileNum;
   unsigned long long fibNumber;

   //printf("N = %d", N);
   if(info == 'r') //recursive 
   {
      fibNumber = recursive(N);
   }
   else if(info == 'i') //iterative
   {
      fibNumber = iterative(N);
   }

   printf("the %dth Fibonacci number is: %llu\n", N, fibNumber);

return 0;
}

unsigned long long recursive(int n)
{
   if (n == 1)
      return 0;
   if (n == 2)
      return 1;
   return recursive(n-1) + recursive(n-2); 
}

unsigned long long iterative(int n)
{
    if (n == 1)
      return 0;
   if (n == 2)
      return 1;
   
   unsigned long long a = 0;
   unsigned long long b = 1;
   unsigned long long next;

   //Fibonacci number #1 is 0 so start at 3 instead of 2.
   for(int i = 3; i <= n; ++i)
   {
      next = a + b;
      //printf("Step %d: a = %llu, b = %llu, next = %llu\n", i, a, b, next);
      a = b;
      b = next;
   }
   return b;
}