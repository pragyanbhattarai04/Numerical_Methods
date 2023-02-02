/**************************************************************************
 Author : Pragyan Bhattarai
 Roll   : THA077BEI030
 Title  : Newton Raphson Method
 Qsn no.: 2
 Problem: x*x-3*x+2=0
**************************************************************************/

#include<stdio.h>
#include<math.h>
#define f(x) x*x-3*x+2
#define df(x) 2*x-3

void main(){
    float x0, x1, f0, f1, e, df0;
    int step = 1, N;

    /**************************INPUT**********************************/
    printf("\nEnter initial value of x0:\t");
    scanf("%f",&x0);
    printf("\nEnter value of tolerable error:\t");
    scanf("%f",&e);
    printf("\nNumber of iterations N:\t");
    scanf("%d",&N);

    /**************Implementation of Newton Raphson method************/
    printf("\nSteps\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do{
        f0 = f(x0);
        df0 = df(x0);
        if (df0==0.0){
            printf("Mathematical error.");
            exit(0);
        }
        x1 = x0 - f0/df0;
        printf("\n  %d\t  %f\t  %f\t  %f\t  %f\n", step, x0, f0, x1, f1);
        x0 = x1;
        step = step +1;
        if (step>N){
            printf("Result is not convergent.\n");
            exit(0);
        }
        f1 = f(x1);
    }while(fabs(f1)>e);
    
    printf("\nRequired root is: %f",x1);
}
