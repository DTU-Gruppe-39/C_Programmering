#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

char ch;
   FILE *fp;

   /****************************************************************************
   Edit the first line of the file, aka the number of activities
   ****************************************************************************/

   fp = fopen("C_programmering/log2018April.txt", "r+"); // read and write mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   printf("The contents of the file are:\n");

   ch = fgetc(fp);
   fseek(fp, 0, SEEK_SET);
   fputc((ch + 1), fp);
   //printf("%c", ch);


   fclose(fp);



   /****************************************************************************
   Add the new lines
   ****************************************************************************/

   fp = fopen("C_programmering/log2018April.txt", "a"); // Append mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   printf("The contents of the file are:\n");

   time_t rawtime;
   struct tm * timeinfo;
   char buffer [80];

   time (&rawtime);
   timeinfo = localtime (&rawtime);

   strftime (buffer,80,"%F %X",timeinfo);
   fputs(buffer, fp);

   fclose(fp);



   // /****************************************************************************
   // Read file - print to console
   // ****************************************************************************/
   //
   // fp = fopen("C_programmering/log2018April.txt", "r"); // read mode
   //
   // if (fp == NULL)
   // {
   //    perror("Error while opening the file.\n");
   //    exit(EXIT_FAILURE);
   // }
   //
   // printf("The contents of the file are:\n");
   //
   // while((ch = fgetc(fp)) != EOF)
   //    printf("%c", ch);
   //
   // fclose(fp);


  return 0;
}
