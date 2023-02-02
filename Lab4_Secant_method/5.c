#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) exp(x)-x*x*x+cos(25 *x)

int main(){
    float x0, x1, x2, f1, f2, f0, e;
    int Iterations=1, N;

    /****************INPUT SECTION**********************/
    printf("Enter values of initial guesses x0 and x1:");
    scanf("%f%f",&x0,&x1);
    printf("Enter absolute value of tolerable error e:");
    scanf("%f",&e);
    printf("Enter maximum number of iterations N:");
    scanf("%d",&N);

    /*******************Apply Secant Method****************/
    printf("______________________________________________________________________\n");
    printf("Iterations\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    printf("______________________________________________________________________\n");
    do{
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1){
            printf("Mathematical error.\n");
            exit(0);
        }
        x2 = x1 - (x1-x0)*f1/(f1-f0);
        f2 = f(x2);
        printf("\n%d\t%f\t%f\t%f\t%f\n", Iterations, x0, x1, x2, f2);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        Iterations++;

        if (Iterations>N){
            printf("The solution doesnot converge.\n");
            exit(0);
        }

    } while(fabs(f2)>e);
    printf("______________________________________________________________________\n");
    printf("The approximate root is: %0.9f", x2);
    return 0;
}
