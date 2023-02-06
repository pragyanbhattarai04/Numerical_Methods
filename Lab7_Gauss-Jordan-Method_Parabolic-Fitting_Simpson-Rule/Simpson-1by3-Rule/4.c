// Title    : Simpson's 1/3 Rule
// Author   : Pragyan Bhattarai
// Roll     : THA077BEI030

#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x) atan(x)/x

int main(){
    int i, n;
    float x0, xn, I=0, h, k;

    /*INPUT SECTION*/
    printf("Enter the values of x0, xn, n: ");
    scanf("%f%f%d", &x0, &xn, &n);

    /*COMPUTE*/
    h = (xn-x0)/n;
    I = f(x0) + f(xn);

    /*Apply Simpson 1/3 Rule*/
    for (i=1; i<=(n-1); i++){
        k = x0 + i*h;
        if (i%2 == 0){
            I = I + 2*f(k);
        }
        else{
            I = I + 4*f(k);
        }
    }

    I = I * h *1/3;
    printf("The approximate value of integral is I = %0.6f.\n", I);
    getch();
    return 0;
}
