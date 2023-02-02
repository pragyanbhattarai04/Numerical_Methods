// Title   : Lagrange Interpolation
// Author  : Pragyan Bhattarai
// Roll    : THA077BEI030

#include<stdio.h>
#include<conio.h>

int main(){
    int n, i, j, L=1;
    float x[30], y[30], yp=0, xp, p;

    /******************Input Section*********************/
    printf("\n\t\t\t\tLagrange's Interpolation\n");
    printf("Enter the value of number of data points n: ");
    scanf("%d",&n);
    printf("Enter the respective values of x and y in pair: \n");
    for (i=1; i<=n; i++){
        scanf("%f%f", &x[i], &y[i]);
    }
    printf("\nThe table of the data you entered is as follows:\n");
    for (i=1; i<=n; i++){
        printf("%0.2f\t\t%0.2f", x[i], y[i]);
        printf("\n");
    }

    /*****************Apply Lagrange Interpolation***********************/
    while (L==1)
    {
        yp=0;
        printf("Enter the value of xp at which the value of yp(x) is to be estimated: ");
        scanf("%f", &xp);
        for (i=1; i<=n; i++){
            p = 1;
            for (j=1; j<=n; j++){
                if (i!=j){
                    p = p * (xp-x[j])/(x[i]-x[j]);
                }
            }
            yp = yp + p * y[i];
        }

        printf("The value of yp(x) at xp = %0.4f is yp(x) = %0.4f.\n", xp, yp);
        printf("\nIf you want to continue PRESS 1, otherwise press any key.");
        scanf("%d", &L);
    }
    getch();
    
}