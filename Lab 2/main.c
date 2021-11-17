#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void bin2Dec(int userInput);
void dec2Bin(int userInput);

int main() {

	int userChoice, i;
    int loop = 1;
    int binary;
    int decimal;

	printf("Lab 2 - Convertion\n");
	for (i = 0; i < 18; i++) { printf("*"); }

    while (loop == 1) {
        printf("\n\nConvert?\n\n1)Binary to Decimal\n2)Decimal to Binary\n3)Exit\n> ");
        scanf("%d", &userChoice);

        while (userChoice != 1 && userChoice != 2 && userChoice != 3){
            printf("\nInvalid Choices");
            printf("\n\nConvert?\n\n1)Binary to Decimal\n2)Decimal to Binary\n3)Exit\n> ");
            scanf("%d", &userChoice);
        } 

        switch (userChoice) {
        case 1:
            printf("Enter a binary: ");
            scanf("%d", &binary);
            bin2Dec(binary);
            break;
        case 2:
            printf("Enter a Decimal: ");
            scanf("%d", &decimal);
            dec2Bin(decimal);
            break;
        case 3:
            printf("Exiting...");
            loop = 0;
            break;
        default:
            loop = 0;
            break;
        }
    }

	return 0;
}


void bin2Dec(long int userInput) {

    /*Variables*/
    int bin, exp;
    long int cnvrt = 0;
    int num = 2;
    int i = 0;
    long int passUserInput;

    /*Created another variable to pass the data inside the userInput*/
    passUserInput = userInput;

    /*While Loops - until the value of userInput is 0*/
    while (userInput != 0) {

        bin = userInput % 10;
        exp = pow(num, i);
        userInput /= 10;
        cnvrt += bin * exp;
        ++i;

    }
    /*System output*/
    printf("The decimal number of %ld is %ld\n", passUserInput, cnvrt);

}

void dec2Bin(int userInput) {
    /*Variables*/
    int passUserInput;
    int cnvrt[40];
    int pos = 0;
    int rem;
    int i = 1;

    /*Created another variable to pass the data inside the userInput*/
    passUserInput = userInput;

    /*While Loops - until the value of userInput is 0*/
    while (userInput != 0) {
        rem = userInput % 2;
        userInput /= 2;
        cnvrt[pos] = rem;
        pos++;

    }

    /*System output*/
    printf("The binary number of %d is ", passUserInput);
    for (i = pos-1; i >= 0; i--) {
        printf("%d", cnvrt[i]);
    }
    
}