#include <stdio.h>
#include <string.h>

//Declare the methods to the compiler
int left(char pearls[], int i);
int right(char pearls[], int i);

int main() {
  //We define infile and outfile to the type FILE and array with type char that contains 100 indices
  FILE *infile, *outFile;
  char pearls[100];

  //Read and write to our DAT and SOL.
  infile = fopen("NECKLACE.DAT", "r");
  outFile = fopen("NECKLACE.SOL", "w");

  //Reads lines in infile until null
  while (fgets(pearls, sizeof(pearls), infile) != NULL){

    //Prints pearl color to outfile
    fprintf(outFile, "%s", pearls);

    //Defines int type variables
    int highestColor = 0, highestColorIndex = 0, checkedPearl = 0;
    //loops from 0 to the length of the string/pearls in the neclace
    for (int i = 0; i < strlen(pearls); ++i) {
      //
      checkedPearl = left(pearls, i) + right(pearls, i);

        //Check if it is now the highest color
        if (checkedPearl > highestColor){
          highestColor = checkedPearl;
          highestColorIndex = i;
        }
    }
  //Append the output text to the outfile
  fprintf(outFile, "%d between %d and %d \n\n", highestColor, highestColorIndex + 1, highestColorIndex + 2);
  }
fclose(infile);
fclose(outFile);
return 0;
}

/*******************************************************************************
Below are the methods for going to the left and right of the necklace.DAT file.
They check if the pearl-color to the right and left is similar to the original
or if it is 'w'
*******************************************************************************/
int left(char pearls[], int i){
  char original = pearls[i];
  int color = 1;

  while (1){
    i--;
    // if (i < 0){
    //   i = strlen(pearls) - 1;
    // }
    if (pearls[i] == original){
      color++;
    } else if(pearls[i] == 'w'){
        color++;
      } else {
            break;
        }
    }
    return color;
}

int right(char pearls[], int i){
  i++;
  char original = pearls[i];
  int color = 1;

  while (1) {
      // i++;
      if (i >= strlen(pearls) - 1){
        i = 0;
      }
      if (pearls[i] == original){
        color++;
      } else if (pearls[i] == 'w'){
          color++;
        } else {
            break;
        }
    }
  return color;
}
