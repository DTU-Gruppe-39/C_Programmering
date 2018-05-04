#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

char ch[6];
   FILE *fp;
   int len;
   char fileName[39];
   time_t rawtime;
   struct tm * timeinfo;
   char buffer [80];

   /****************************************************************************
   Create file if not exits
   ****************************************************************************/

   //%B month
   //%Y year
   time (&rawtime);
   timeinfo = localtime (&rawtime);
   strftime (buffer,80,"%Y%B",timeinfo);
   printf(buffer);
   printf("\n");

   sprintf(fileName, "C_Programmering/log%s.txt", buffer);
   printf(fileName);

   fp = fopen(fileName, "ab+");

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   len = ftell(fp);
   printf("\n%d\n", len);
   //ch = fgetc(fp);
   if (len == 0) {
     fputc('0', fp);
   }

   fclose(fp);


   /****************************************************************************
   Edit the first line of the file, aka the number of activities
   ****************************************************************************/

   fp = fopen("C_programmering/log2018April.txt", "r+"); // read and write mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   fgets(ch, 6, fp);
   sprintf(ch, "%d", (atoi(ch) + 1));
   fseek(fp, 0, SEEK_SET);
   fputs(ch, fp);

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

   time (&rawtime);
   timeinfo = localtime (&rawtime);

   strftime (buffer,80,"%F %X\n",timeinfo);
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
