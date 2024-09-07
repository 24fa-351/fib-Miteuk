#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fibonacci Functions
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

   //Fibonacci number #1 is 0 so start at 3 instead of 2. F(1)= 0, F(2) = 1
   for(int i = 3; i <= n; ++i)
   {
      next = a + b;
      a = b;
      b = next;
   }
   return b;
}

int main(int argc, char *argv[]) 
{

   int number = atoi(argv[1]);
   FILE *file = fopen(argv[3], "r");

   int fileNum;

   fscanf(file, "%d", &fileNum);
   fclose(file);

   int N = number + fileNum;
   int fibNumber;

   if(strcmp(argv[2],"r") == 0) //recursive 
   {
      fibNumber = recursive(N);
   }
   else if(strcmp(argv[2], "i") == 0 ) //iterative
   {
      fibNumber = iterative(N);
   }

   printf("%d\n", fibNumber);
   

return 0;
}
