#include<stdio.h>
#include<math.h>

int main(){
    int n, i;
    float x[20], y[20], Y[20], sumx = 0, sumy = 0, sumxy = 0, sumx2 =0, a, b, A;
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
        Y[i]= log(y[i]);
    }

    /**************COMPUTE SUM********************/
    for(i=1;i<=n;i++){
        sumx = sumx + x[i];
        sumx2 = sumx2 + x[i]*x[i];
        sumy = sumy + Y[i];
        sumxy = sumxy + Y[i]*x[i];
    }

    /************COMPUTE VALUES OF a AND b*************/
    b = (n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    A = (sumy - b*sumx)/n;
    a = exp(A);

    printf("The values of a and b are: a = %0.4f and b = %0.4f\n",a ,b);
    printf("The estimated regression line is: y = %0.4f e^(%0.4fx)\n",a,b);
    return 0;
}