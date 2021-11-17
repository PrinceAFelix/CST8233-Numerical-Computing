#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int factorial(int n);
void calcSeries(float approx, float angle);
int main()
{
    //Variables
    float appError;
    float angle;
  
    char userInput;
    int loop = 1;

    cout << "Lab 11 Maclaurin Series Expansion\n" << endl ;

    do {

        //Ask the user for approx relative bound
        cout << "Enter your approx. relative bound: " << endl;
        cin >> appError;

        //Ask for the angle
        cout << "Enter your angle in radian: " << endl;
        cin >> angle;

        //Call the functions that will calcukate the maclaruin
        calcSeries(appError, angle);

        cout << endl << "Continue?(Y/n): ";
        cin >> userInput;

        cout << endl;

        if (userInput == 'Y' || userInput == 'y')
            continue;
        else
            loop = 0;

    } while (loop == 1);

   

    return 0;
}

/*
This method calculates the Maclaurin Series Expansion of cos x
*/
void calcSeries(float approx, float angle) {

    //Variables
    int n = 5;
    float exact, relErr1 = 0.0, relErr2, aError1, aError2, temp = 1, approxVal = 1;

    //Calculate the cos in radians using the built in function
    exact = cos(angle);

    //Print the header
    cout << "N.terms\t\tExact\t\tApproximate Value\t\tAbsolute Error\t\t%Relative Error" << endl;

    int i = 1;

    do {
       
        temp *= pow((-1), i) * pow(angle, 2 * i) / factorial(2 * i);
        approxVal += temp;
    
        aError1 = (exact - approxVal);
       
        relErr1 = (aError1 / exact) * 100.0;

        cout << i << "\t\t" << exact << "\t\t" << approxVal << "\t\t" << fixed << setprecision(6) << aError1 << "\t\t" << relErr1 << endl;

    } while (relErr1 > approx);

    /*
    //Calculate in for loops
    for (int i = 1; i < n; i++)
    {
        //Calculate using the formula f(x) = cos x
        temp *= (-1) * angle * angle / (2 * i * (2 * i - 1));
        approxVal += temp;

        aError1 = (exact - approxVal);
        aError2 = (approxVal - exact);
        relErr1 = aError1 * 100.0 / exact;
        relErr2 = aError2 * 100.0 / exact;


        //Print the calculated value
        if (aError1 > 0)
            cout << i << "\t\t" << exact << "\t\t" << approxVal << "\t\t" << fixed << setprecision(6) << aError1 << "\t\t" << relErr1 << endl;
        else if (aError2 > 0) 
            cout << i << "\t\t" << exact << "\t\t" << approxVal << "\t\t" << fixed << setprecision(6) << aError2 << "\t\t" << relErr2 << endl;
           
     
        // stop when relative error falls below a certain pre-specified relative error
        if (relErr1 >= aError1 && relErr2 >= aError2)
            break;
        else
            n++;
            
    }*/
}

int factorial(int n) {
    int i;
    int fact = 0;

    for (i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}