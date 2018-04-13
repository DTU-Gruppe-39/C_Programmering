#include <stdio.h>
#include <stdlib.h>

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
if(1 <= segNum && segNum <=40000){


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


 // water < 0 = 0
 // += i j
printf("\n");
}
int tempWater = 0;
for(int i = 0; i < segNum; i++){
  array[i].water = array[i].x2 - array[i].x1;
  for(int j = 0; j < segNum; j++){
      if(array[i].y1 < array[j].y1 || array[i].y2 < array[j].y2){     //if there is a roof above

        int g = 0;
        int count = 0;
        int n = array[i].x2 - array[i].x1;
        int checker[n];

        for(int k = array[i].x1; k <= array[i].x2; i++){
          for(int l = array[j].x1; l <= array[j].x2; l++){
            if (k == l){
              checker[g] = 1;
            }
            g++;
          }
        }
        for(int h = 0; )
        if(checker[g] == 1){
          count++;
          tempWater = array[i].water - count;
          array[i].water = tempWater;
        }
      }
    }
//j    --
//i --------
//         if(array[i].x1 < array[j].x1 && array[i].x2 > array[j].x2){
//           tempWater = (array[i].x2 - array[i].x1) - (array[j].x2 - array[j].x1);
//           if(tempWater < array[i].water){
//             array[i].water = tempWater;
//         }
//       }
// //j --------
// //i    --
//         if(array[i].x1 > array[j].x1 && array[i].x2 < array[j].x2){
//           tempWater = 0;
//           if(tempWater < array[i].water){
//             array[i].water = tempWater;
//           }
//         }
// //j ------
// //i     ------
//         if(array[i].x1 > array[j].x1 && array[i].x2 > array[j].x2){
//           tempWater = array[j].x2 - array[i].x1;
//           if(tempWater < array[i].water){
//             array[i].water += tempWater;
//         }
//       }
//  //check with <=
//
//  //j    ------
//  //i ------
//       if(array[i].x1 < array[j].x1 && array[i].x2 < array[j].x2){
//         tempWater = array[j].x1 - array[i].x1;
//         if(tempWater < array[i].water){
//           array[i].water += tempWater;
//         }
//       }
//
//     }
// }


  printf("%s %d\n", "Segment", i );
  printf("%d %d %d %d\n", array[i].x1, array[i].y1, array[i].x2, array[i].y2);      //Puts the values in the struct variables on the array
  printf("%d \n", array[i].water);

}


return 0;

}
else {
  printf("%s\n", "There can be between 1 - 40000 segments" );
}

int findWater (int x1, int y1, int x2, int y2){
}


}
