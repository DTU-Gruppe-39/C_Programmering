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
    while(!(1 <= segNum && segNum <=40000)){
        printf("%s\n", "There can be between 1 - 40000 segments" );
        scanf("%d", &segNum);
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
    }
      //Check if the values are correct x1 < x2 & y1 != y2
    }

    //------------------------------------------------------------------------------

     // water < 0 = 0
     // += i j
    printf("\n");
    }

    for(int i = 0; i < segNum; i++){
      array[i].water = array[i].x2 - array[i].x1;
    }

    for(int i = 0; i < segNum; i++){
      // array[i].water = array[i].x2 - array[i].x1;       //Look above
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


//##############################################################################
//# I think the problem is that not all roofs have a value yet when trying to transfer the water
//# Maybe initialize alle water values before trying to transfer
//#
//#
//# Segment 3
//# 5 5 9 3
//# Water is 13
//# Is off by 2
//#
//#
//#
//#
//# Roof 1 7 5 6 is transfered before it has it own overlap calculated, so it
//# transfers to much water
//#
//#
//# Check if for water transfer whether it should be < or <= if x align
//#
//#
//#
//#
//# Also needs to make sure that a partially covered roof only transfers water equal to the uncovered part
//# Maybe change order roofs are processed from top to buttom, instead of first to last input
//##############################################################################


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
                  // overlap = other.water;
                  overlap = 0;                      //@@@Since it doesn't matter what side the water falls
                  return overlap;
              } else if(current.x1 > other.x1 && current.x2 < other.x2){
                  //j --------
                  //i    --
                    overlap = current.water;
                    return overlap;
              } else if(current.x1 > other.x1 && current.x2 > other.x2){
                  //j ------
                  //i     ------
                      // overlap = other.x2 - current.x1;
                      if (other.y1 > other.y2) {    //@@@
                        printf("%s%d%s%d\n", "Current water er: ", current.water, " other water er: ", other.water );
                        overlap = (-other.water);
                      } else {
                        overlap = other.x2 - current.x1;
                      }
                      return overlap;
              } else {
                  //j    ------
                  //i ------
                      // overlap = current.x2 - other.x1;
                      if (other.y1 < other.y2) {
                        overlap = (-other.water);
                      } else {
                        overlap = current.x2 - other.x1;
                      }
                      return overlap;
              }
          }
      }
}
