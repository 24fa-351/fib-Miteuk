#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fibonacci Functions
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

int main(int argc, char *argv[]) 
{

   int number = atoi(argv[1]);
   //char info = argv[2][0]; // for "r" or "i"
   FILE *file = fopen(argv[3], "r");

   int fileNum;

   fscanf(file, "%d", &fileNum);
   fclose(file);

   int N = number + fileNum;
   unsigned long long fibNumber;

   //printf("N = %d", N);
   if(strcmp(argv[2],"r") == 0) //recursive 
   {
      fibNumber = recursive(N);
   }
   else if(strcmp(argv[2], "i") == 0 ) //iterative
   {
      fibNumber = iterative(N);
   }

   printf("%llu\n", fibNumber);
   

return 0;
}
