#include <stdio.h>
#include <stdlib.h>

FILE *infile;

char c;

int main(){


  infile = fopen("NECKLACE.DAT", "rw");

      if (infile == NULL) {
          printf("Couldn't open .DAT file\n");
          exit(0);
      }

while (c != EOF) {

  for(int j = 0; j < 100; j++){
    c = getc(infile);
    printf("%s", &c);

      if(c == '\n'){
    for(int i = 0; i <10; i++ ){
          char array[10];
          array[i] = c;
          printf("%c", array[i]);

          if (i == j){
            i = 0;
          }
        }
      }
    }
  }
  return 0;
}
