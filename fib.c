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

   printf("Enter an integer: ");
   scanf("%d", &number);

   printf("Enter r or i: ");
   scanf(" %c", &info);

   printf("Enter a filename: ");
   scanf("%s", file);

   int fileNum;

   file = fopen(fileName,"r");
   fscanf(file, "%d", &fileNum);
   fclose(file);

   int N = number + fileNum;


   if(info == 'r') //recursive 
   {
      recursive(N);
      printf("Fibonacci number is: ", N);
   }
   else if(info == 'i') //iterative
   {
      iterative(N);
      printf("Fibonacci number is: ", N);
   }


return 0;
}

int recursive(int n)
{
   if (n <= 1)
      return n;
   return recursive(n-1) + recursive(n-2); 
}

int iterative(int n)
{
   if (n <= 1)
      return n;
   
   int a = 0;
   int b = 1;
   int next;

   for( int i = 2; i <= n; i++)
   {
      next = a + b;
      a = b;
      b = next;
   }
   return b;
}