/***********************************************************
File Name: ass2.c
Version: 1.0
Student Name: Prince Adrianne Felix
Author/Student Number: 040933287
Assignment Number: 2
Course name and number: 21W_CST8233_300 Numerical Computing
Lab Section: 301
Professor's name: Hala Own
Due Date: March 19, 2021
Submission Date: March 14, 2021
Purpose: This program calculate the extrapolation point
header files:
***********************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*Fixed Size of Array*/
#define SIZE 15

//Functions definition
void menu(int m);
void readFile(int* days, int* progIndex);
void dataSummary(int* progIndex, int n);
void linearRegressionFit(int* days, int* progIndex);
double calcMean(int n, int* y);
double calcMedian(int n, int* y);
double calcRange(int n, int* y);
double calcMode(int n, int* y);
double calcStanDeviation(int n, int* y);
void extrapolate(int* x, int* y, int days, int n, int check);
void bubbleSort(int n, int* y);

/*Global Variable*/
double a = 0.0, b = 0.0;

/***********************************************************
Function Name: main
Purpose: Main function, Calculate different interpolation points
Function in parameters: none
Function out parameter: return 0 for successful
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
int main(int argc, char* argv[]) {

	//Variables
	int i = 0, loop = 1;
	int* days = (int*)malloc(sizeof(int) * SIZE);
	int* progIndex = (int*)malloc(sizeof(int) * SIZE);

	//Do while, it will stay until the user decided to exit
	do {
		int userCoice;
		menu(1);
		

		if (scanf("%d", &userCoice) == 1) {
			switch (userCoice) {
			case 1:
				//Case 1 will call the readFile calculate everything
				readFile(days, progIndex);
				break;
			case 2:
				loop = 0;
				break;
			default:
				printf("Invalid selection, please trey again\n\n");
				break;
			}
		}
		else {
			printf("Invalid Choice, please try again\n\n");
			break;
		}
		

		

	} while (loop != 0);

	return 0;
}

/***********************************************************
Function Name: menu
Purpose: Menu of the program
Function in parameters: 
	m represents the condition of the menu
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
void menu(int m) {

	//If m is 1 then print the main menu, else print the sub menu
	if (m == 1) {
		printf("LEAST_SQUARES LINEAR REGRESSION\n\nMENU\n 1. Exponential Fit\n 2. Quit\n> ");
	}
	else {
		printf("\nMENU\n 1. Extrapolation Fit\n 2. Main Menu\n> ");
	}
}

/***********************************************************
Function Name: readFile
Purpose: Read and open the file and store them in the array
Function in parameters: 
	days represents the array x values
	progIndex represents the array y values
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
void readFile(int* days, int* progIndex) {
	//Variables
	char fileName[20];
	char title1[100];
	char title2[100];
	int loop2 = 1;
	int i = 0;

	//File
	FILE* fptr;

	printf("Please enter the name of the file top open: ");
	scanf("%s", fileName);

	//Open the file for reading
	fptr = fopen(fileName, "r");


	//If null, terminate the program
	if (!fptr) {
		printf("\nFile could not be open\n");
		exit(1);

	}

	//Skip the first line, store the words in other variable
	if (fscanf(fptr, "%s", title1) != 1) {
		printf("FIle read failed\n");
		exit(1);
	}
	if (fscanf(fptr, "%s", title2) != 1) {
		printf("FIle read failed\n");
		exit(1);
	}

	//While true, store the x vaues in days and y value in progIndex
	while (1) {
		if (fscanf(fptr, "%d", &days[i]) == EOF)
			break;
		if (fscanf(fptr, "%d", &progIndex[i]) == EOF)
			break;
		i++;
	}
	
	//Printing what's in the file
	printf("%s\t%s\n", title1, title2);
	for (i = 0; i < SIZE; i++) {
		printf("%d\t%d\n", days[i], progIndex[i]);
	}
	printf("There are %d records.\n\n", i);

	//Call the data summary to print the data summary
	dataSummary(progIndex, SIZE);
	//Call the linear regression  function to print the formula
	linearRegressionFit(days, progIndex);


	//In a do while,  thi will enter the sub menu and keeps on going until the user decided to exit
	do {
		int userChoice = 0, ePoint = 0;
		menu(2);
		

		if (scanf("%d", &userChoice)) {
			switch (userChoice) {
			case 1:
				//Ask the use to enter the days to extrapolate
				printf("\nPlease enter the days to extrapolate: ");
				scanf("%d", &ePoint);
				extrapolate(days, progIndex, ePoint, SIZE, 1);
				break;
			case 2:
				loop2 = 0;
				break;
			default:
				printf("Invalid Input, please try again\n");
			}
		}
		else {
			printf("Invalid Input, please try again\n");
			break;
		}
		

	} while (loop2 == 1);

	//Close the file
	fclose(fptr);

}

/***********************************************************
Function Name: dataSummary
Purpose: Print the data summary by calling all the functions to calculate the missing value
Function in parameters:
	progIndex represents the array y values
	n represents the length
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
void dataSummary(int* progIndex, int n) {
	printf("Data Summary (Prognostic index):\n");
	printf("Mean = %.2f\nMedian = %.2f\nRange = %.2f\nMode = %.f\nStandard Devidation = %.2f\n", calcMean(n, progIndex), calcMedian(n, progIndex), calcRange(n, progIndex), calcMode(n, progIndex), calcStanDeviation(n, progIndex));

}

/***********************************************************
Function Name: linearRegressionFit
Purpose: Calculate the linear regression fit formula
Function in parameters:
	days represents the array x values
	progIndex represents the array y values
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
void linearRegressionFit(int* days, int* progIndex) {
	//Variables
	int i;
	double yFitted[SIZE];
	double yFittedTotal = 0.0, sse = 0.0;

	//Call the extrepolate function to get the a and b values
	extrapolate(days, progIndex, 0, SIZE, 0);
	printf("\n\nLinear Regression Fitm: Prognostc_index = %.2f exp %.3f days\n", a, b);

	//Calculate SSE by applying the formula
	for (i = 0; i < SIZE; i++) {
		yFitted[i] = (a * exp(b * days[i]));
		yFittedTotal += yFitted[i];
		sse += pow((yFitted[i] - progIndex[i]), 2);
	}

	//Calculate the standard error by applying the formula
	double stdErr = sqrt(sse / (double)(SIZE - 2));

	printf("Standard Error = %.2f\n", stdErr);
}

/***********************************************************
Function Name: calcMean
Purpose: Calcyulate the mean of the array
Function in parameters:
	n represents the length
	y represents the array
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
double calcMean(int n, int* y) {
	//Variables
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

/***********************************************************
Function Name: calcMedian
Purpose: Calculate the median of the array
Function in parameters:
	n represents the length
	y represents the array
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
double calcMedian(int n, int* y) {

	double median = 0.0;
	int i;
	int yptr[SIZE];
	//In for loops, copy the original array to a copy array
	for (i = 0; i < n; i++)
		yptr[i] = y[i];
	//Sort the array
	bubbleSort(n, yptr);


	//Check if n is even
	if ((n % 2) == 0) {
		//Assigning these values, will be use for index of array
		int x2 = (n / 2);
		int x1 = (n / 2) - 1;

		//Get the middle array
		median = ((double)yptr[(int)x1] + (double)yptr[(int)x2]) / 2;
		return median;
	}
	else {
		//Assign n as index of array
		n = (n / 2);

		//retrun indexx of n
		return yptr[(int)n];
	}


}

/***********************************************************
Function Name: calcRange
Purpose: Calculate the range of the y values
Function in parameters:
	n represents the length
	y represents the array
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
double calcRange(int n, int* y) {
	//Variables
	int i = 0;
	int yptr[SIZE];

	//In for loops, copy the original array to a copy array
	for (i = 0; i < n; i++)
		yptr[i] = y[i];
	//Sort the copy array
	bubbleSort(n, yptr);
	//Store the max and min
	int min = yptr[0];
	int max = yptr[14];

	//Return the range value by subtracting max to min
	return ((double)max - (double)min);

}

/***********************************************************
Function Name: calcMode
Purpose: Calculate the mode of the y values
Function in parameters:
	n represents the length
	y represents the array
Function out parameter:none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
double calcMode(int n, int* y) {
	//Variables
	int i, j, mode = 0, maxCount = 0;
	
	//In nested loops, we increment a counter if there's a match value
	for (i = 0; i < n; i++) {
		int count = 0;
		for (j = 0; j < n; j++) {
			if (y[j] == y[i]) {
				count++;
			}
		}
		//Then set that number to be the mode
		if (count > maxCount) {
			maxCount = count;
			mode = y[i];
		}
	}

	//Return the number with the highes appearance
	return mode;

}

/***********************************************************
Function Name: calcStanDeviation
Purpose: Calculate the standard Deviation of the given graph
Function in parameters:
	n represents the length
	y represents the array
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
double calcStanDeviation(int n, int* y) {

	//Variables
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

/***********************************************************
Function Name: extrapolate
Purpose: Calculate the estimated value using extrapolation
Function in parameters:
	x represents the x value in the array
	y represents the y value in the array
	days represents the days to extrapolate
	n represents the length
	check represents the checker
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
void extrapolate(int* x, int* y, int days, int n, int check) {

	//Variables
	int i;
	double a1 = 0.0, a0 = 0.0, xTotal = 0.0, yTotal = 0.0, xSquareTotal = 0.0, lnYTotal = 0.0, xlnRTotal = 0.0;
	double xSquare[SIZE];
	double lnY[SIZE];
	double xlnR[SIZE];


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


	//Calc the data
	for (i = 0; i < n; i++) {
		lnY[i] = log(y[i]);
		lnYTotal += lnY[i];
		xlnR[i] = (x[i] * lnY[i]);
		xlnRTotal += xlnR[i];
	}

	//Calculating the a1 by plugging the values
	double temp1 = (n * xlnRTotal) - (xTotal * lnYTotal);
	double temp2 = (n * xSquareTotal) - pow(xTotal, 2);
	a1 = (temp1 / temp2);

	//Calculating the a0 by plugging the values
	a0 = (lnYTotal / n) - (a1) * (xTotal / n);

	//Assign the a and b values, to be use as in applying to formula
	a = exp(a0);
	b = a1;

	//Calculate the estimated extrapolate value
	double progIndexTotal = (a * exp(b * days));

	//Print if true
	if (check == 1)
		printf("Days = %d\nPrognostic_index = %.1f\n", days, progIndexTotal);


}



/***********************************************************
Function Name: bubbleSort
Purpose: This sort algorithm is called bubble sort, it's use to sort an array
Function in parameters: n represents the length of the array, y represents the array
Function out parameter: none
Version: 1.0
Author: Prince Adrianne Felix
***********************************************************/
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