// Title    : Runge-Kutta method of fourth order 
// Author   : Pragyan Bhattarai
// Roll     ; THA077BEI030
// Lab      : 8.3

#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x,y) (x*y+y*y)

int main(){
    int i, n;  // n is number of steps
    float x0, y0, xn, yn, h, k1, k2, k3, k4, k;

    /*INPUT SECTION*/
    printf("Enter the value of x0, y0, n: ");
    scanf("%f%f%d", &x0, &y0, &n);
    printf("Enter the value of xn at which we estimate the value of yn: ");
    scanf("%f", &xn);

    /*Compute h*/
    h = (xn - x0)/n;

    printf("\nx0\t\ty0\t\tyn\n");
    for (i=0; i<n; i++){
        k1 = h * (f(x0,y0));
        k2 = h * (f((x0+h/2),(y0+k1/2)));
        k3 = h * (f((x0+h/2),(y0+k2/2)));
        k4 = h * (f((x0+h),(y0+k3)));
        k = (k1 + 2*k2 + 2* k3 + k4)/6;
        yn = y0 + k;
        printf("%6.6f\t%6.6f\t%6.6f\n", x0, y0, yn);
        x0 = x0 + h;
        y0 = yn;
    }    

    printf("The approximate value of y at x = %f is y = %f.", xn, yn);
    getch();
    return 0;
}
