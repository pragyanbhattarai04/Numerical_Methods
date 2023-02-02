#include<stdio.h>

int main(){
    int n, i;
    float x[20], y[20], sumx = 0, sumy = 0, sumxy = 0, sumx2 =0, a, b;
    printf("Enter the number of data points n: ");
    scanf("%d",&n);
    
    /*****************INPUT**********************/
    printf("Enter the values of x:");
    for(i=1;i<=n;i++){
        scanf("%f",&x[i]);
    }

    printf("Enter the values of y:");
        for(i=1;i<=n;i++){
        scanf("%f",&y[i]);
    }

    /**************COMPUTE SUM********************/
    for(i=1;i<=n;i++){
        sumx = sumx + x[i];
        sumx2 = sumx2 + x[i]*x[i];
        sumy = sumy + y[i];
        sumxy = sumxy + y[i]*x[i];
    }

    /************COMPUTE VALUES OF a AND b*************/
    b = (n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    a = (sumy - b*sumx)/n;

    printf("The values of a and b are: a = %0.4f and b = %0.4f\n",a ,b);
    printf("The estimated regression line is: y = %0.4f + %0.4fx\n",a,b);

    printf("When t=7: N =%0.4f", a + b*7);
    
    return 0;
}