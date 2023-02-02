// Lab 4    : Regula Falsi Method
// Author   : Pragyan Bhattarai
// Roll     : THA077BEI030

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) x*x*x-2*x-5

int main(){
    float x0, x1, x2, f1, f2, f0, e;
    int Iterations=1, N;

    /****************INPUT SECTION**********************/
    printf("Enter values of initial guesses x0 and x1:");
    scanf("%f%f",&x0,&x1);
    printf("Enter absolute value of tolerable error e:");
    scanf("%f",&e);
    f0 = f(x0);
    f1 = f(x1);
    
    /*******************Apply False Position Method****************/
    printf("_________________________________________________________________________________________________________\n");
    printf("Iterations\tx0\t\tx1\t\tx2\t\tf(x0)\t\tf(x1)\t\tf(x2)\n");
    printf("_________________________________________________________________________________________________________\n");
    do{
        if (f0 == f1){
            printf("Mathematical error.\n");
            exit(0);
        }
        x2 = x0 - (x1-x0)*f0/(f1-f0);
        f2 = f(x2);
        printf("\n%d\t\t%f\t%f\t%f\t%f\t%f\t%f\n", Iterations, x0, x1, x2,f0, f1, f2);
        
        if (f0*f2<0){
            x1 = x2;
            f1 = f(x1);
        }
        else{
            x0 = x2;
            f0 = f(x0);
        }
        Iterations++;
    } while(fabs(f2)>e);

    printf("_________________________________________________________________________________________________________\n");
    printf("The approximate root is: %0.6f", x2);
    return 0;
} 