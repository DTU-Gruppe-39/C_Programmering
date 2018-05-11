#include <stdio.h>
int main(void){
        double a = 3.0;
        int runs = 0;
        const double pie = 3.141593;
        double b = 1;
        printf("Pi er: %f\n", pie );
        printf("Dette program beregner PI vha. en undelig serie.\n");
        while(pie < b*4) {
                b -= (1.0/a);
                a += 2.0;
              //  printf("Runs: %d\n", runs++ );
                b += (1.0/a);
                a += 2.0;
                printf("Pi er: %.11f\n", b*4 );
                //sleep(0,2);
                printf("------------------------");
        }
        printf("Den udregnede circa-værdi af pi er: %f\n", pie);
        return 1;
}
