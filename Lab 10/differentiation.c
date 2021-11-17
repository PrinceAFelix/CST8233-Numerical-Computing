#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[]) {

	double x = 0;
	double y, ed, cntr, frwrd,bwrd;
	double h = 0.25;
	printf("%s%10s%25s%15s%15s%13s", "x", "y", "Exact derivative", "Centered", "forward", "backward");

	for (x = 0; x <= 4.0; x += h) {

		//Calculate the y using the formula
		y = x * sin(pow(x, 2)) + 1;

		//Calculate the Exact Derivative by applying the formula
			//f'(x) = sin(x^2) + 2x^2cos(x^2)
		ed = sin(pow(x, 2)) + 2 * pow(x, 2) * cos(pow(x, 2));	

		//Calculate the Centered finite difference by applying the forumula and the y formula
		cntr = (((x + h) * sin(pow(x + h, 2)) + 1) - ((x - h) * sin(pow(x - h, 2)) + 1)) / (2 * h);

		//Calculate the forward finite difference by applying the forumula and the y formula
		frwrd = (((x + h) * sin(pow(x + h, 2)) + 1) - (x * sin(pow(x, 2)) + 1)) / h;

		//Calculate the backward finite difference by applying the forumula and the y formula
		bwrd = ((x * sin(pow(x, 2)) + 1) - ((x - h) * sin(pow(x - h, 2)) + 1)) / h;
		
		//Print the calculated answer
		if (x == 0)//We can't compute the centered and backward if x == 0, because there's no backward
			printf("\n%.2f%10.4f%17.5f%20.4s%15.5f%13.5s", x, y, ed, "-", frwrd, "-");
		else if (x == 4)//We can't compute the centered and forward because there's no forward
			printf("\n%.2f%10.4f%17.5f%20.4s%15.5s%13.5f", x, y, ed, "-", "-", bwrd);
		else
			printf("\n%.2f%10.4f%17.5f%20.4f%15.5f%13.5f", x, y, ed, cntr, frwrd, bwrd);
	}

	return 0;
}
