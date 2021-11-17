#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


void taylorSeries(double x, int n);
double factorial(int n);
int main(int argc, char* argv[]) {

	//Local Variables
	char inp;
	double x;
	int n, loop = 1;

	printf("Lab 10 - Taylor Series Expansion\n\n");
	//loops, until the user decided to exit
	do {
		//Ask for the value of x
		printf("Enter the value of x: ");
		scanf("%lf", &x);
		//Ask for the numbers of terms : Default 10
		printf("Enter the number of terms: ");
		scanf("%d", &n);

		//Call the functions to calculate the taylor expansion
		taylorSeries(x, n);

		//Ask the user if continue or not
		printf("\n\nContinue?(y/n): ");
		scanf(" %c", &inp);
		if (inp == 'y' || inp == 'Y') {
			printf("\n");
			continue;
		}
		else
			loop = 0;

	} while (loop == 1);
	

	return 0;
}

void taylorSeries(double x, int n) {
	//Variables
	int i;
	double trueVal = 0.0, appVal = 0.0, aError = 0.0, rError = 0.0;
	double te = x - 1.0;

	//paply the formula
	for (i = 1; i <= n; i++)
	{	
		appVal += pow(-1, (double)i - 1) * (pow((x - 1), i)) / i;
	}

	//Calculate the values
	trueVal = log(x);
	aError = fabs(trueVal - appVal);
	rError = aError / trueVal;

	//Print the result
	printf("\nTrue value = %.6f", trueVal);
	printf("\nApproximate value = %.6f", appVal);
	printf("\nAbsolute error = %.8f", aError);
	printf("\nRelative error = %.8f", rError);
}
