#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursive(int n);
int iterative(int n);

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
   int fibNumber;

   if(info == 'r') //recursive 
   {
      fibNumber = recursive(N);
   }
   else if(info == 'i') //iterative
   {
      fibNumber = iterative(N);
   }

   printf("the %dth Fibonacci number is: %d\n", N, fibNumber);

return 0;
}

int recursive(int n)
{
   if (n == 1)
      return 0;
   if (n == 2)
      return 1;
   return recursive(n-1) + recursive(n-2); 
}

int iterative(int n)
{
    if (n == 1)
      return 0;
   if (n == 2)
      return 1;
   
   int a = 0;
   int b = 1;
   int next;

   //Fibonacci number #1 is 0 so start at 3 instead of 2.
   for( int i = 3; i <= n; i++)
   {
      next = a + b;
      a = b;
      b = next;
   }
   return b;
}