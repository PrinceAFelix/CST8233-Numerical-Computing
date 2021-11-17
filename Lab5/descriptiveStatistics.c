#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

//Function Declaration
void bubbleSort(int n, int* y);
double calcMean(int n, int* y);
double calcMedian(int n, int* y);
double calcStanDeviation(int n, int* y);

//Main
int main() {


    //Variables
    int userChoice, i, n, j;
    int loop = 1;
    int x[100], y[100];

    //Ask how many points
    printf("How many Students woud you like to calculate? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Student [%d] Grade: ", (i + 1));
        scanf("%d", &y[i]);
        x[i] = (i + 1);
    }

    while (loop == 1) {
        printf("\n\What would you like to do?\n\n1)Mean\n2)Median\n3)Standard Deviation\n4)Exit\n> ");
        scanf("%d", &userChoice);

        switch (userChoice) {
        case 1:
            //Call and print function to calculate mean
            printf("The mean is %.1f", calcMean(n, y));
            break;
        case 2:
            //Sort thee array
            bubbleSort(n, y);
            //Call and print a function to calculate median
            printf("The median is %.1f", calcMedian(n, y));
            break;
        case 3:
            //Call and print a function to calculate standard deviation
            printf("The standard deviation is %.10f", calcStanDeviation(n, y));
            break;
        case 4:
            printf("Exiting...");
            loop = 0;
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }

    return 0;
}


double calcMean(int n, int* y) {
    double mean = 0.0;
    int i;

    /*Add all the numbers in the array*/
    for (i = 0; i < n; i++) {
        mean += y[i];
    }
    //Devide by n(10)
    mean /= n;

    //Return the calculated number
    return mean;
}

double calcMedian(int n, int* y) {
    double median = 0.0;
    int i;

    //Check if n is even
    if ((n % 2) == 0) {
        //Assigning these values, will be use for index of array
        int x2 = (n / 2);
        int x1 = (n / 2) - 1;

        //Get the middle array
        median = ((double)y[(int)x1] + (double)y[(int)x2]) / 2;
        return median;
    }
    else {
        //Assign n as index of array
        n = (n / 2);

        //retrun indexx of n
        return y[(int)n];
    }


}


double calcStanDeviation(int n, int* y) {
    int i;
    double variance = 0.0, mean = 0.0, deviation = 0.0;
    //Get the mean by calling the calcMean function
    mean = calcMean(n, y);

    //Apply the formula to get the variance
    for (i = 0; i < n; i++) {
        variance += pow((y[i] - mean), 2);
    }

    //Divide variab=nce  by n-1
    variance /= ((double)n - 1);
    
    //return the sqyare root of the calculated variance
    return sqrt(variance);

}

//This sort algorithm is called bubble sort, it's use to sort an array, wil be called when calculating median
void bubbleSort(int n, int* y) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (y[j] > y[j + 1]) {
                int temp = y[j];
                y[j] = y[j + 1];
                y[j + 1] = temp;
            }
        }
    }
}

