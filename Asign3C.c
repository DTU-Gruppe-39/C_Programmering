#include <stdio.h>
#include <stdlib.h>


struct Node
{
    char data;
    int num;
    struct Node *next;
    struct Node *prev;
}; typedef struct Node NODE;


int main() {

  NODE *current, *first = NULL, *temp = NULL;

char str[100], c;
FILE *infile, *outfile;
int i = 0;

infile = fopen("NECKLACE.DAT", "r");

    if (infile == NULL) {
        printf("Couldn't open .DAT file\n");
        exit(0);
    }

outfile = fopen("NECKLACE.SOL", "w");

    if(outfile == NULL) {
        printf("Couldn't find .SOL file \n" );
        exit(0);
    }
    //
    // while ((fscanf(infile, "%[^\n]", str)) != EOF)
    // {
    //   c = fgetc(infile);
    //   printf("%c\n", c);
    // }


do {
for(int j = 0; j < 100; j++){
      c = getc(infile);

      current = (NODE*) malloc(sizeof(NODE));
           current-> data = c;
           current->next = NULL;
           // current->prev = NULL;
           printf("%c", current->data);
           putc(current->data, outfile);

           if(first != NULL) {
             temp->next = current;
             temp = current;
               }
           else {
               first = temp = current;
           }
       fflush(stdin);

      if(c == '\n'){
        printf("%d\n", j);
        //make doubly list
        //check what breakpoint is the max pearls
        break;
      }
    }
      } while (c != EOF); {
}


fclose(infile);
fclose(outfile);
return 0;

//-----------------------------------------------------------------------------

}
