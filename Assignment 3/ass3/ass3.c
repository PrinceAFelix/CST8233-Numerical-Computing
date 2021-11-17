/***********************************************************
File Name: ass3.c
Version: 1.0
Student Name: Prince Adrianne Felix
Author/Student Number: 040933287
Assignment Number: 3
Course name and number: 21W_CST8233_300 Numerical Computing
Lab Section: 301
Professor's name: Hala Own
Due Date: April 9, 2021
Submission Date: April 6, 2021 
Purpose: This program evaluate a series at a given terms and range
header files:
***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Function Declaration*/
void evalSeries(int terms, double tRange);


/***********************************************************
Function Name: main
Purpose: The purpose of this is to ask the user for an input and calculate a series with those inputs
Function in parameters: argc, argv[]
Function out parameter: return 0 for successful
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
int main(int argc, char* argv[]) {

    //Variables
    int userChoice;
    int terms = 0;
    double tRange = 0.0;


    do {
        printf("Evaluate the Maclaurin Series approximation to D(t) = exp(t)*cos(t)\n\n1: Evaluate the series\n2: quit\n\n>");
        scanf("%d", &userChoice);

        switch (userChoice) {
        case 1:
            printf("Evaluating the series\n");
            /*Ask the user for the number of terms*/
            do { /*Keep asking until it meet the reuqirements*/
                printf("\nPlease enter the number of (non-zero) terms in the series (1, 2, 3, 4, 5 or 6): ");
                scanf("%d", &terms);
            } while (terms != 1 && terms != 2 && terms != 3 && terms != 4 && terms != 5 && terms != 6);
            
            /*Ask the user for the rangee to evaluate*/
            do { /*Keep asking until it meet the reuqirements*/
                printf("\nPlease enter the range of t to evaluate in 10 increments (0.0 < t < +4.0): ");
                scanf("%lf", &tRange);
            } while (tRange < 0.0 || tRange > 4.0);
           
            /*Call the function to evauate series*/
            evalSeries(terms, tRange);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (1);

    return 0;
}


/***********************************************************
Function Name: evalSeries
Purpose: Evaluate the series
Function in parameters:
    terms repreents the number of terms
    tRange represents the range 
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
void evalSeries(int terms, double tRange) {
    
    /*VAriables used*/
    int i,j;
    double calcSeries[7];
    double series, exact = 0.0, RExactE = 0.0, RSerE = 0.0, trunc = 0.0;
    double t = 0.0;

    printf("\nMACLAURIN SERIES\n%3s%26s%19s%18s%18s", "t", "D(t) Series", "D(t) Exact", "%RExactE", "%RSerE");

    /*For loops 10 times*/
    for (i = 0; i <= 10; i++) {

        /*7 Trancuation error for 6 terms and store them in a pointer*/
        series = 0.0;
        calcSeries[0] = 1.0;
        calcSeries[1] = t;
        calcSeries[2] = (-1 * t * t * t) / 3;
        calcSeries[3] = (-1 * t * t * t * t) / 6;
        calcSeries[4] = (-1 * t * t * t * t * t) / 30;
        calcSeries[5] = (t * t * t * t * t * t * t) / 630;
        calcSeries[6] = (t * t * t * t * t * t * t * t) / 2520;

        /*Calculate the Series*/
        for (j = 0; j < terms; j++)
            series += calcSeries[j];

        /*Get the trancuation*/
        trunc = calcSeries[terms];

        /*Calculate the approximation using the given formula*/
        exact = exp(t) * cos(t);

        /*Relative error in two ways*/
        RExactE = 100 * (exact - series) / exact;
        RSerE = 100 * (trunc / series);

        /*Output the calculated series and relative error*/
        printf("\n%.3e%20.5e%20.5e%20.5e%20.5e", t, series, exact, RExactE, RSerE);
        t += (tRange/10);
    }

    printf("\n\n");
}