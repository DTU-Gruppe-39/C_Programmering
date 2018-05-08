#include <stdio.h>
#include <stdlib.h>


int main() {

  int count = 0;
  int num = 1, keep = 0;
  int even = 0, odd = 0;
  int totalEven = 0, totalOdd = 0;
  double avgEven = 0, avgOdd = 0;


  printf("Enter integers\n");
  printf("Enter '0' to exit\n" );

  while(num != 0){    //Exit with 0

    scanf("%d", &num);

    if (even == 0 && odd == 0){
      keep = num;
    }

    if (num != 0 && num %  2 == 0){    //Checks if it is even
      even++;
      totalEven += num;
  }

    else if (num % 2 == 1) {    //Checks if it is odd
      odd++;
      totalOdd += num;
      }
    }

  if(even != 0){      //Checks if input had any even numbers
    avgEven = totalEven/even;
    printf("Contains %d even numbers and the average of even numbers is: %.2f\n" , even, avgEven);
  }
  if (odd != 0){      //Checks if input had any odd numbers
    avgOdd = totalOdd /odd;
    printf("Contains %d odd numbers and the average of odd numbers is: %.2f\n" , odd, avgOdd);
  }

  printf("First number you entered was: %d\n",keep );


printf("\nNumber of nodes in the original list = %d\n", count);

printf("These values can't be the sum of two primes: \n");

	for(int i = 1; i < keep; i++){
		if (i < keep && i < 4){
      printf("%d ", i);
    }
		if (i % 2 != 0){
			for(int j = 2; j < i - 2; j++){
				if(((i - 2) % j) == 0){
					printf("%d ", i);
					break;
				}
			}
		}
	}
}
