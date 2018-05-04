#include <stdio.h>
#include <memory.h>

int checkBack(char input[], int index);
int checkForward(char input[], int index);
char readFile();

int main() {
    //Define the files to be opened.
    FILE *fp;
    FILE *outFile;

    //Make a buffer array to contain stuff from the file i'm readign from
    char input[255];

    //Open the file with the necklace data in it.
    fp = fopen("NECKLACE.DAT", "r");

    //Open the file to output to.
    outFile = fopen("NECKLACE.SOL", "a");


    //Iterate through the lines in the file
    while (fgets(input, sizeof(input), fp) != NULL){
        //Define the current file
        input[strlen(input)] = '\0';

        //Print the current data to the outputfile
        fprintf(outFile, "%s\n", input);

        //Define variables to be used
        int highest = 0;
        int indexAtHighest = 0;
        int temp = 0;
        int sizeOnArray = 0;
        //Loop through the char array, and check forward and backwards
        for (int i = 0; i < strlen(input); ++i) {
            //Get the count backwards and forward
            temp = checkBack(input, i) + checkForward(input, i);

            //Check if it is now the highest count
            if (temp > highest){
                highest = temp;
                indexAtHighest = i;
            }
            sizeOnArray++;

        }
             printf("%d ", sizeOnArray-1);
        //Append the output text to the outfile
        fprintf(outFile, "%d between %d and %d\n", highest, indexAtHighest+1, indexAtHighest+2);

    }


    //Close the files
    fclose(fp);
    fclose(outFile);


    return 0;
}


//A method to check backwards and return the count backwards
int checkBack(char input[], int index){
    char original = input[index];
    int count = 1;
    char w = 'w';

    while (1){
        index--;
        if (index < 0){
            index = strlen(input)-1;
        }
        if ((input[index] == original) == 1){
            count++;
        } else {
            if((input[index] == w) == 1){
                count++;
            } else {
                break;
            }
        }
    }

    return count;
}

//A method to check forward and return the count
int checkForward(char input[], int index){
    index++;
    char original = input[index];
    char w = 'w';
    int count = 1;

    while (1){
        index++;
        if (index >= strlen(input)){
            index = 0;
            // count++;
        }
        if ((input[index] == original) == 1){
            count++;
        } else {
            if((input[index] == w) == 1){
                count++;

            } else {
                break;
            }
        }
    }

    return count;
}
