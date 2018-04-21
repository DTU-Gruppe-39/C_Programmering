#include <stdio.h>
#include <stdlib.h>

//#define overlaps
struct segment {
  int x1, y1, x2, y2;
  int water;
};



int main(void) {
    int x1, y1, x2, y2;
    int segNum;
    int checker = 0;

    printf("%s", "Insert the amount of roofs \n" );
    scanf("%d", &segNum);
    if(!(1 <= segNum && segNum <=40000)){
        printf("%s\n", "There can be between 1 - 40000 segments" );
        return 0;
    }

    struct segment array[segNum];

    printf("%s", "Insert the values x1, y1, x2, y2 \n" );
    for(int i = 0; i < segNum; i++){

      checker = 0 ;
      while (checker == 0){
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

      if(x1 <= x2 && y1 != y2     && x1 >= 0  && y1 >= 0  && x2 >= 0  & y2 >= 0   && x1 <= 1000000  && y1 <= 1000000  && x2 <= 1000000  & y2 <= 1000000){
        array[i].x1 = x1;
        array[i].y1 = y1;
        array[i].x2 = x2;
        array[i].y2 = y2;
        checker = 1;
      }
    else {
      printf("%s\n", "Invalid input, try again");
      return 0;
    }
      //Check if the values are correct x1 < x2 & y1 != y2
    }

    //------------------------------------------------------------------------------

    printf("\n");
    }

    for(int i = 0; i < segNum; i++){
      array[i].water = array[i].x2 - array[i].x1;
    }

    for(int i = 0; i < segNum; i++){
      for(int j = 0; j < segNum; j++){
          if (i != j) {
              if(overlaps(i, j, array[i], array[j]) ) {
                  array[i].water = array[i].water - overlaps(i, j, array[i], array[j]);
              }
          }
      }
      printf("%s %d\n", "Segment", i );
      printf("%d %d %d %d\n", array[i].x1, array[i].y1, array[i].x2, array[i].y2);      //Puts the values in the struct variables on the array
      printf("%d \n", array[i].water);
    }
    return 0;
}

int overlaps(int i, int j, struct segment current, struct segment other) {
    int overlap = 0;

    if(current.x1 > other.x2 || current.x2 < other.x1) {
       return overlap;
    } else {
          if(current.y1 > other.y1 || current.y2 > other.y2){   //Make a better check
              return overlap;
          } else {

              //j   ---
              //i -------
              if(current.x1 < other.x1 && current.x2 > other.x2) {
                  overlap = (-other.water);      //Since it doesn't matter what side the water falls
                  return overlap;
              } else if(current.x1 > other.x1 && current.x2 < other.x2){
                  //j --------
                  //i    --
                    overlap = current.water;
                    return overlap;
              } else if(current.x1 > other.x1 && current.x2 > other.x2){
                  //j ------
                  //i     ------
                      if (other.y1 > other.y2) {
                        overlap = (-other.water);
                      }
                        overlap =  overlap + (other.x2 - current.x1);
                      return overlap;
              } else {
                  //j    ------
                  //i ------
                      if (other.y1 < other.y2) {
                        overlap = (-other.water);
                      }
                        overlap = overlap + (current.x2 - other.x1);
                      return overlap;
              }
          }
      }
}



/*
Givet opgave
Roof 6
13 7 15 6
3 8 7 7
1 7 5 6
5 5 9 3
6 3 8 2
9 6 12 8


Ekstra input
Roof 5
2 5 3 6
4 7 7 6
4 5 6 6
0 4 5 5
2 3 4 4

*/
