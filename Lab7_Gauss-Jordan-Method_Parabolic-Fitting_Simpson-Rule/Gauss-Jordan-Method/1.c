// Title    : Gauss Jordan Method
// Author   : Pragyan Bhattarai
// Roll     : THA077BEI030
// Lab      : 7.1

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int i, j, k, n;
    float a[10][10], x[10], ratio;

    /*INPUT SECTION*/
    printf("Enter number of unknown variables: ");
    scanf("%d", &n);
    printf("Enter the coefficients of Augmented Matrix:\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=(n+1); j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /*Apply Gauss Jordon Elimination*/
    for(j=1; j<=n; j++){
        if (a[j][j]==0.0)
        {
            printf("Mathematical Error.");
            exit(0);
        }
        for(i=1; i<=n; i++){
            if (i!=j){
                ratio = a[i][j] / a[j][j];
                for ( k = 1; k <= n+1; k++)
                {
                    a[i][k] = a[i][k] - ratio*a[j][k];
                }
                
            }
        }
    }


    if (a[n][n] == 0 && a[n][n + 1] == 0)
    {
        printf("The system is consistent and it has infinite solution.\n");
        exit(0);
    }

    if (a[n][n] == 0 && a[n][n + 1] != 0)
    {
        printf("The system is inconsistent and it has no solution.\n");
        exit(0);
    }

    /*Obtaining Solution*/
    for(i=1;i<=n;i++){
        x[i] = a[i][n+1]/a[i][i];
    }

    /*Displaying Solution*/
    printf("The system is consistent.\nThe approximate roots are: \n");
    for (i=1; i<=n; i++){
        printf("\t\t\tx[%d] = %0.3f\n", i, x[i]);
    }

    getch();
    return 0;
}