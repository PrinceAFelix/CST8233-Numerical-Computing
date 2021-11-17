#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double calcTrap(double n);
int main(int argc, char* argv[]) {

	//Variable
	int i;
	int n = 0;
	int temp = 0;
	double t = 0.0;

	//Calculate the exact value
	double trueVal = 2.0 / 3.0;
	printf("%5s%20s%25s", "n", "Trapezoid", "Absolute Error");
	
	//Loop until n = 2^9
	for(i = 2; i <= 512; i+=n){
		n = pow(2, ++temp);
		//Clal the calc method
		t = calcTrap(n);

		//Get the absolute error
		double aErr = (trueVal - t);
		printf("\n%5d%20.6f%25.6f", n, t, aErr);

	}
	return 0;
}

//THis method will calculate the intgerals using the trapezoid rule
double calcTrap(double n) {
	int i;
	double h = 1 / n;

	//Apply the formula
	double s = sqrt(1) + sqrt(0);
	for (i = 1; i < n; i++)
	{
		s += 2 * sqrt(i * h);
	}
	//Return the calculated value
	return (h / 2) * s;
}