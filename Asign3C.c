#include <stdio.h>
#include <memory.h>
#include <string.h>

int Backward(char pearls[], int index);
int Forward(char pearls[], int index);
char readFile();

int main() {
    //Define the files to be opened.
    FILE *infile, *outFile;

    //Make a buffer array to contain stuff from the file i'm reading from
    char pearls[100];

    //Read necklace and write it to our output file.
    infile = fopen("NECKLACE.DAT", "r");
    outFile = fopen("NECKLACE.SOL", "w");

    //Iterate through the lines in the file
    while (fgets(pearls, sizeof(pearls), infile) != NULL){
        //Define the current file
  //      pearls[strlen(pearls)] = '\0';

        //Print the current data to the outputfile
        fprintf(outFile, "%s", pearls);

        //Define variables to be used
        int highest = 0, HighestIndex = 0, checkedPearl = 0, sizeOnArray = 0;
        //Loop through the char array, and check forward and backwards
        for (int i = 0; i < strlen(pearls); ++i) {
            //Get the count backwards and forward
            checkedPearl = Backward(pearls, i) + Forward(pearls, i);

            //Check if it is now the highest count
            if (checkedPearl > highest){
                highest = checkedPearl;
                HighestIndex = i;
            }
            sizeOnArray++;

        }
             printf("%d ", sizeOnArray-1);
        //Append the output text to the outfile
        fprintf(outFile, "%d between %d and %d + %d\n\n", highest, HighestIndex+1, HighestIndex+2, strlen(pearls));
    }

    //Close the files
    fclose(infile);
    fclose(outFile);


    return 0;
}


//A method to check backwards and return the count backwards
int Backward(char pearls[], int index){
    char original = pearls[index];
    int count = 1;

    while (1){
        index--;
        if (pearls[index] == original){
            count++;
        } else {
            if(pearls[index] == 'w'){
                count++;
            } else {
                break;
            }
        }
    }

    return count;
}

//A method to check forward and return the count
int Forward(char pearls[], int index){
    index++;
    char original = pearls[index];
    int count = 1;

    while (1) {
        index++;
        if (index >= strlen(pearls) - 1){
            index = 0;
            // count++;
        }
        if (pearls[index] == original){
            count++;
        } else {
            if(pearls[index] == 'w'){
                count++;

            } else {
                break;
            }
        }
    }

    return count;
}
