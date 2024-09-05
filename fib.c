#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   if(info != 'r' || info != 'i')
      {
         printf("Invalid input.");
         return 1;
      }

   if(info == 'r')
      {
         file = fopen(fileName, "r");
         printf("File '%s' opened for reading.\n", fileName);
         fclose(file);
      }
   else if(info == 'i')
      {
         printf("You entered the number: %d\n", number);
      }

   int fileNum;

   fscanf(file, "%d", &fileNum);
   fclose(file);

   int N = number + fileNum;

   if(info == 'r') //recursive 
   {

   }
   else if(info == 'i') //iterative
   {

   }


return 0;
}
