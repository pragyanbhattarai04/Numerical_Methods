#include<stdio.h>
#include<math.h>
#define e 0.001

float f(float x){
    return (pow(5,x)-3*x);
}

int main(){
    float x0, x1, x2, f1, f0, f2;
    int step = 1;
    GUESSES:
    printf("Enter initial guesses:");
    scanf("%f %f",&x0, &x1);
        f0 = f(x0);
        f1 = f(x1);
    if ((f0 * f1)>0){
        printf("Incorrect initial guesses.");
        goto GUESSES;
    }

    do
    {
        f0 = f(x0);
        f1 = f(x1);
        x2 = (x0 + x1)/2;
        f2 = f(x2);
        if ((f0 * f2)<0){
            x1 = x2;
        }
        else {
            x0 = x2;
        }
        printf("No. of iteration= %i    x0=%f        x1=%f       x2=%f       f0=%f       f1=%f       f2=%f\n", step, x0, x1, x2, f0, f1, f2);
        step++;
    } while (fabs(f2)>e);
    printf("%f is the root.", x2);
    return 0;
}
