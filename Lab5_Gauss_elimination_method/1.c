// Title    : Gauss Elimination method for the system of linear equations
// Author   : Pragyan Bhattarai
// Roll     : THA077BEI030

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// #include<math.h>

int main()
{
    int n, i, j, k;
    float a[30][30], x[30], Ratio = 0, sum = 0;

    /*****************INPUT SECTION****************/
    printf("\nEnter the number of unknowns n:");
    scanf("%d", &n);
    printf("Enter the elements a[i][j] of the augmented matrix of given matrix of the coefficient matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /*****************Apply Gauss Elimination method to the augmented matrix******************/
    for (i = 1; i <= (n - 1); i++)
    {
        if (a[i][i] == 0)
        {
            printf("Mathematical Error\n");
            exit(0);
        }
    }

    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (i > j)
            {
                Ratio = a[i][j] / a[j][j];
                for (k = 1; k <= (n + 1); k++)
                {
                    a[i][k] = a[i][k] - Ratio * a[j][k];
                }
            }
        }
    }

    /**************Obtain solution by backward substitution******************/
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

    /**********************Compute unique solution***************************/
    x[n] = a[n][n + 1] / a[n][n];
    for (i = (n - 1); i >= 1; i--)
    {
        sum = 0;
        for (j = (i + 1); j <= n; j++)
        {
            sum = sum + a[i][j] * x[j];
        }
        x[i] = (a[i][n + 1] - sum) / a[i][i];
    }

    /*************Display solution***************/
    printf("The system is consistent.\nThe approximate roots are: \n");
    for (i = 1; i <= n; i++)
    {
        printf("\t\t\t\tx[%d]= %f\n", i, x[i]);
    }
    getch();
    return 0;
}
