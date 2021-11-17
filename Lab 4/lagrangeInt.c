#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{

    int i, j, n;
    float x[100], y[100];
    float Xp, Yp = 0, p;

    int loop = 1;
    int isOk = 0;
    float temp;

    do
    {
        int userInput;
        printf("What would you like to do?\n\n1. Insert a data\n2. Calculate a point\n3. Exit\n>");
        scanf("%d", &userInput);

        switch (userInput)
        {
        case 1:
            printf("Enter number of data: ");
            scanf("%d", &n);

            printf("\nEnter data:\n\n");

            for (i = 1; i <= n; i++)
            {
                printf("x[%d] = ", i);
                scanf("%f", &x[i - 1]);
                printf("y[%d] = ", i);
                scanf("%f", &y[i - 1]);
                isOk = 1;

            }
            break;
        case 2:
            if (isOk == 1)
            {
                printf("\nEnter interpolation point: ");
                scanf("%f", &Xp);

                while (Xp < x[0])
                {
                    printf("Invalid Point");
                    printf("\nEnter interpolation point: ");
                    scanf("%f", &Xp);
                }

                //Apply the formula to calculate the interpolation point

                for (i = 1; i <= n; i++)
                {
                    p = 1;
                    for (j = 1; j <= n; j++)
                    {
                        if (i != j)
                            p = p * (Xp - x[j - 1]) / (x[i - 1] - x[j - 1]);
                    }
                    Yp = Yp + p * y[i - 1];
                }
                printf("Valid point\n");
                printf("Interpolated value at %d is %.3f\n\n", (int)Xp, Yp);
                Yp = 0;
            }
            else
            {
                printf("\nCan't calculate a point.. Please create a Data first\n\n");
            }
            break;
        case 3:
            loop = 0;
            break;
        default:
            printf("\nInvalid Choice, Please Try Again\n\n");
            break;
        }

    } while (loop != 0);

    return 0;
}