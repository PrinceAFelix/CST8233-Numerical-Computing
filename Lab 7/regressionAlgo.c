#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


void calcData(double* x, double* y, int n);
void simpleLR();
int main(int argc, char* argv[]) {

    //Variables
    int userChoice, i, n, j;
    int loop = 1;
    

    //Ask how many points
    while (loop == 1) {
        printf("\n\What would you like to do?\n\n1)Simple Linear Regression\n2)Exit\n> ");
        scanf("%d", &userChoice);

        switch (userChoice) {
        case 1: 
            simpleLR();
            
            break;
        case 2:
            loop = 0;
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }

    return 0;
}

//
void simpleLR() {
    int n, i;
    double* x = (double*)malloc(sizeof(double) * 20);
    double* y = (double*)malloc(sizeof(double) * 20);



    printf("\nEnter the no. of data pairs to be entered:\n>");
    scanf("%d", &n);

    printf("\nEnter the x-axis vaues:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]); 
    }
    printf("\nEnter the y-axis vaues:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    calcData(x, y, n);
}

void calcData(double *x, double *y, int n) {
    int i;
    double a1 = 0, a0 = 0, xTotal = 0, yTotal = 0, xSquareTotal = 0, xyTotal = 0;
    double * xSquare = (double*)malloc(sizeof(double) * 20);
    double * xy = (double*)malloc(sizeof(double) * 20);
    double * yFitted = (double*)malloc(sizeof(double) * 20);

    //Calc the total value of X
    for (i = 0; i < n; i++) {
        xTotal += x[i];
    }

    //Calc the total value of Y
    for (i = 0; i < n; i++) {
        yTotal += y[i];
    }

    //Calc the x^2 and store it
    for (i = 0; i < n; i++) {
        xSquare[i] = pow(x[i], 2);
        xSquareTotal += xSquare[i];
    }
   
    //Calc the xy and store it
    for (i = 0; i < n; i++) {
        xy[i] = x[i] * y[i];
        xyTotal += xy[i];
    }

    double xTotalTemp = pow(xTotal, 2);
    double temp1 = (n * xyTotal) - (xTotal * yTotal);
    double temp2 = (n * (xSquareTotal)-(xTotalTemp));
    a1 = temp1 / temp2;
    
    double xMean = xTotal / n;
    double yMean = yTotal / n;

    a0 = yMean - (a1 * xMean);

    
    printf("\n\n%s%9s%18s%19s\n", "S.no", "x", "y(observed)", "y(fitted)");
    for (i = 0; i < 50; i++)
        printf("-");
    for (i = 0; i < n; i++) {
        yFitted[i] = (a1 * x[i]) + a0;
        printf("\n%d.%12.1f%12.f%19.3f", (i + 1), x[i], y[i], yFitted[i]);
    }

    printf("\n\nThe linear fit line is of the form:\n\ny = %.5fx + %.3f\n\n", a1, a0);

}

