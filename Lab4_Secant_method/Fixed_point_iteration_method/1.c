// Lab 4    : Fixed Point Iteration Method
// Author   : Pragyan Bhattarai
// Roll     : THA077BEI030

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) x*x*x+x*x-1
#define phi(x) 1/(pow((1+x),0.5))

int main(){
    int iterations=1, N;
    float x0, x1, e;

    /*********Input Section*********/
    printf("Enter initial guess x0: ");
    scanf("%f",&x0);
    printf("Enter tolerable error e: ");
    scanf("%f", &e);
    printf("Enter maximum number of iterations N: ");
    scanf("%d", &N);

    /**********Applying fixed point iteration method**********/
    printf("__________________________________________________\n");
    printf("Iterations\tx0\t\tphi(x)\n");
    printf("__________________________________________________\n");
    do{
        x1 = phi(x0);
        printf("%d\t\t%f\t%f\n",iterations, x0, x1);
        iterations++;
        if(iterations>N){
            printf("Solution is not convergent.\n");
            exit(0);
        }
        x0 = x1;
    } while(fabs(f(x1))>e);
    printf("__________________________________________________\n");
    printf("Approximate real root is: %f",x1);
    return 0;
}