#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define N 5

int factorial(int n);
void calcSeries(double angle);
int main(int argc, char* argv[]) {

	//Local Variables
	char inp;
	double approx, angle;
	int loop = 1;

	

	printf("Lab 11 - Maclurin Series Expansion\n\n");
	//loops, until the user decided to exit
	do {
		//Ask for the value of x
		printf("Enter your approx. relative bound: ");
		scanf("%lf", &approx);
		//Ask for the numbers of terms : Default 10
		printf("Enter your angle in radian: ");
		scanf("%lf", &angle);



		//Call the functions to calculate the maclurin expansion
		calcSeries(angle);

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

void calcSeries(double angle) {
	int i;
	double m = 0.0;
	double approx = 1;
	double exactVal = cos(angle);
	double temp = 1.0;
	
	
	printf("\n\n%s%20s%25s%19s%20s\n", "N.Terms", "Exact", "Approximate Value", "Absolute Error", "%Relative Error");
	/*
	for (i = 1; (exactVal - approx) <= (exactVal - approx) * 100 / exactVal || (approx - exactVal) <= (approx - exactVal) * 100 / exactVal; i++) {
		temp *= pow((-1), i) * pow(angle, (double)2 * i) / (factorial(2 * i));
		approxVal += temp;

		if ((exactVal - approx) > 0)
			printf("%d%9.6f%25.6f%19.6f%20.6f", i, exactVal, approxVal, 0.0, 0.0);
		else
			printf("%d%9.6f%25.6f%19.6f%20.6f", i, exactVal, approxVal, 0.0, 0.0);

	}*/
	double aError = 0.0;
	double relError = 0.0;
	double relError2 = 0.0;
	
	do {

		aError = (exactVal - approx) * 100 / exactVal;
		relError = (exactVal - approx);
		relError2 = (approx - exactVal);

		i = 1;
		double a = pow((-1), i) * pow(angle, 2 * (double)i);
		double b = factorial(2 * (double)i);
		
		temp = a / b;
		approx += temp;

		

		if (relError > 0)
			printf("%d%20.6f%25.6f%19.6f%20.6f\n", i, exactVal, approx, relError, aError);
		else 
			printf("%d%20.6f%25.6f%19.6f%20.6f\n", i, exactVal, approx,  relError2, aError);

		i++;

	} while (relError >= aError || relError2 >= aError);
}

int factorial(int n) {
	int i;
	int fact = 0;

	for (i = 1; i <= n; ++i) {
		fact *= i;
	}
	return fact;
}