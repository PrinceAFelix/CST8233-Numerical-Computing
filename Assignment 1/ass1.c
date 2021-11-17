/***********************************************************
File Name: ass1.c
Version: 1.0
Student Name: Prince Adrianne Felix
Author/Student Number: 040933287
Assignment Number: 1
Course name and number: 21W_CST8233_300 Numerical Computing
Lab Section: 301
Professor's name: Hala Own
Due Date: February 7 2021
Submission Date: February 7 2021
Purpose: This programs prints 41 column table with interpolation calculation
header files:
***********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>


/*Function prototype*/
void functionA(int n);
void functionB(int n);
double lagrange(int n, double x, double* xk, double* fk);

/***********************************************************
Function Name: main
Purpose: Main function, Calculate different interpolation points
Function in parameters: none
Function out parameter: return 0 for successful
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
int main()
{
    /*Local Variables*/
    int loop = 1;
    int n;

    /*In do loop, it will keep on going until the user decided to exit*/
    do
    {
        /*Ask the user what he/she wants to do*/
        int userInput;
        printf("MENU\n1. Function A\n2. Function B\n3. Quit\n>");
        scanf("%d", &userInput);


        switch (userInput)
        {
        case 1:
            /*Should ask the user for the order number the calls the function*/
            printf("WHEN n = ");
            scanf("%d", &n);
            functionA(n);
            break;
        case 2:
            /*Should ask the user for the order number the calls the function*/
            printf("WHEN n = ");
            scanf("%d", &n);
            functionB(n);
            break;
        case 3:
            /*Should exit the program*/
            loop = 0;
            break;
        default:
            /*If the input was not on the list, it should print the error message and ask the user again*/
            printf("\nInvalid Choice, Please Try Again\n\n");
            break;
        }

    } while (loop != 0);

    return 0;
}

/***********************************************************
Function Name: functionA
Purpose: Calcuclate the interpolation using the formula provided for functionA
Function in parameters: int n, represents the number of order
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
void functionA(int n) {

    /*Variables*/
    int i, j, k;
    double Xk[41], x[41], y[41], f[41], p = 0.0, absoluteError[41], trueVal;

    printf("%s%15s%15s%20s%20s\n", "K", "Xk", "P", "TRUE VALUE", "ABSOLUTE VALUE");
    for (i = 0; i < 41; i++) {
        /*Calculate the 41 Xk values by applying the formula*/
        Xk[i] = -1.0 + ((2.0 * (double)(i)) / 40.0);
        /*Calculate the true value*/
        trueVal = sqrt(1.0 + (pow(Xk[i], 2.0)));
        /*pass the true value*/
        f[i] = trueVal;

    }

    /*In for loops it Create the 6 points of the table*/
    for (i = 0; i < n + 1; i++) {
        x[i] = -1.0 + ((2.0 * (double)(i)) / n);
        y[i] = sqrt(1.0 + (pow(x[i], 2.0)));
    }


    /*In for loops it calls the lagrange function to calculate the interpolation*/
    for (i = 0; i < 41; i++) {
        /*Calls the function*/
        p = lagrange(n + 1, Xk[i], x, y);
        /*Solve the absolute error by getting the difference of interpoaltion and the true value*/
        absoluteError[i] = p - f[i];
        /*Prints out the table*/
        printf("%d%15f%15.7f%20.8f%20.2E\n", i, Xk[i], p, f[i], absoluteError[i]);
    }
}


/***********************************************************
Function Name: functionB
Purpose: Calcuclate the interpolation using the formula provided for functionA
Function in parameters: int n, represents the number of order
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
void functionB(int n) {

    /*Variables*/
    int i, j, k;
    double Xk[41], x[41], y[41], f[41], p = 0.0, absoluteError[41], trueVal;

    printf("%s%15s%15s%20s%20s\n", "K", "Xk", "P", "TRUE VALUE", "ABSOLUTE VALUE");
    for (i = 0; i < 41; i++) {
        /*Calculate the 41 Xk values by applying the formula*/
        Xk[i] = -1.0 + ((2.0 * (double)(i)) / 40.0);
        /*Calculate the true value*/
        trueVal = 1 / (1 + 25 * pow(Xk[i], 2));
        /*pass the true value*/
        f[i] = trueVal;

    }

    /*In for loops it Create the 6 points of the table*/
    for (i = 0; i < n + 1; i++) {
        x[i] = -1.0 + ((2.0 * (double)(i)) / n);
        y[i] = 1 / (1 + 25 * pow(x[i], 2));
    }

    /*In for loops it calls the lagrange function to calculate the interpolation*/
    for (i = 0; i < 41; i++) {
        /*Calls the function*/
        p = lagrange(n + 1, Xk[i], x, y);
        /*Solve the absolute error by getting the difference of interpoaltion and the true value*/
        absoluteError[i] = p - f[i];

        /*Prints out the table*/
        printf("%d%15f%15.7f%20.8f%20.2E\n", i, Xk[i], p, f[i], absoluteError[i]);


    }
}

/***********************************************************
Function Name: lagrange
Purpose: Calcuclate the interpolation using the formula  of lagrange interpolation
Function in parameters: int n, represents the number of order
                        double x, represents the x values
                        double xk, fk, represents the interpolation points
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
double lagrange(int n, double x, double* xk, double* fk) {

    /*Variables*/
    int i, k;
    double p, lk;
    p = 0.0;

    /*Apply the lagrange interpolation formula to calculate the missing y values*/
    for (k = 0; k < n; k++)
    {
        lk = 1.0;
        for (i = 0; i < n; i++)
        {
            if (i != k)
                lk = lk * (x - xk[i]) / (xk[k] - xk[i]);
        }
        p += lk * fk[k];
    }

    return p;


}