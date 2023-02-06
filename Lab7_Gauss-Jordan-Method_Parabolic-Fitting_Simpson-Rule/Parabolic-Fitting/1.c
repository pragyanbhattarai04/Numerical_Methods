// Title    : Parabolic fit by Least squares
// Author   : Pragyan Bhattarai
// Roll     : THA077BEI030
// Lab      : 7.2

#include<stdio.h>

int main(){
    float augm[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    float t, a, b,c, x, y, xsq;
    int i, j, k, n;
    printf("Enter the number of pairs of observed values: ");
    scanf("%d", &n);

    augm[0][0] = n;
    for (i=0; i<n; i++){
        printf("Pair no. %d\n", i+1);
        scanf("%f%f", &x, &y);
        xsq = x * x;
        augm[0][1] += x;
        augm[0][2] += xsq;
        augm[0][3] += y;
        augm[1][2] += x*xsq;
        augm[1][3] += x*y;
        augm[2][2] += xsq*xsq;
        augm[2][3] += xsq*y;
    }
    augm[1][0] = augm[0][1];
    augm[1][1] = augm[0][2];
    augm[2][0] = augm[1][1];
    augm[2][1] = augm[1][2];

    printf("\nThe augmented matrix is:-\n");
    for (i=0; i<3; i++){
        for (j=0; j<4; j++){
            printf("%9.3f", augm[i][j]);
        }
        printf("\n");
    }

    /*Now solving for a, b, c by Gauss Jordan Method*/
    for (j=0; j<3; j++){
        for(i=0; i<3; i++){
            if (i!=j){
                t = augm[i][j]/augm[j][j];
                for (k=0; k<4; k++){
                    augm[i][k] -= augm[j][k]*t;
                }
            }
        }
    }
    a = augm[0][3]/augm[0][0];
    b = augm[1][3]/augm[1][1];
    c = augm[2][3]/augm[2][2];
    printf("a = %8.3f\nb = %8.3f\nc = %8.3f\n", a, b, c);
    printf("\nThe parabola of best fit is : y = %.2f + (%.2f)x + (%.2f)x^2", a, b, c);
    return 0;
}