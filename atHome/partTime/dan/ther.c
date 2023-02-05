#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int Convert(char *unit, int before);
int Srand(int firstLength, int secondLength);
int Scale(int First, int Second, int Third,double Height);

int main()

{
    printf("Welcome!\nThis is a program that calculates the height and area of a triangle from the valid input edge lengths, then print out a right-angle triangle.\n");
    printf("You need to input 2 edge lengths of a triangle.\n");
    printf("The information you enter needs to contain both value and units.\n The value should be greater than zero and the units should be cm or dm or m.\n\n");

    int a, b;        // a and b are the first and second edge length that user input respectively.
    int result_1, result_2; // //result_1 is the first edge length in centimeters,result_2 is the second edge length in centimeters.
    char unit_a[3], unit_b[3];

    do
    {
        printf("Please enter the first edge length of the triangle: \n ");
        scanf("%d %s", &a, &unit_a);
        printf("Please enter the second edge length of the triangle: \n ");
        scanf("%d %s", &b, &unit_b);

        if (a <= 0 || b <= 0)

        {
            printf("Error!! The value entered is less than 0!\n");
            printf("please enter again:\n");
            continue;
        }

        if ((strcmp(unit_a, "m") != 0 && strcmp(unit_a, "dm") != 0 && strcmp(unit_a, "cm") != 0) || (strcmp(unit_b, "m") != 0 && strcmp(unit_b, "dm") != 0 && strcmp(unit_b, "cm") != 0))

        {
            printf("Error!! The unit entered is not supported by the program!\n");
            printf("Please enter again:\n");
            continue;
        }
        else
        {

            if (strcmp(unit_a, "cm") != 0)
            {

                result_1 = Convert(unit_a, a); // call first external function
            }
            if (strcmp(unit_b, "cm") != 0)
            {

                result_2 = Convert(unit_b, b);
            }
            if (strcmp(unit_a, "cm") == 0)
            {

                result_1 = a;
            }
            if (strcmp(unit_b, "cm") == 0)
            {

                result_2 = b;
            }


            if (result_1 < 10 || result_2 < 10)
            {
                printf("Error!! The length is less than 10 cm!\n");
                printf("Enter the edge length again!\n");
                continue;
            }
            if (result_1 < 0.1 * result_2 || result_2 < 0.1 * result_1)
            {
                printf("Error!! One length is less than 10%% of the other\n");
                printf("Enter the edge length again!\n");
                continue;
            }

            int c;// the third edge length
            c = Srand(result_1, result_2); // call the second external function

            // calculate the area of the triangle
            float p, area;
            p = 1.0 / 2 * (result_1 + result_2 + c);
            area = sqrt(p * (p - result_1) * (p - result_2) * (p - c)); // use Heron's Formula to calculate the area of this triangle

            // calculate the height of the triangle

            int max;
            float Height;

            if (result_1 > result_2 && result_1 > c)
                max = result_1;
            else if (result_2 > c && result_2 > result_1)
                max = result_2;
            else
                max = c;

            Height = (2 * area) / max;

            printf("The area of triangle is %.2f cm2\n", area);
            printf("The height of triangle is %.2f cm\n", Height);
            Scale(result_1, result_2, c,Height); // call the third external function
        }

    } while ((a <= 0 || b <= 0) || (strcmp(unit_a, "m") != 0 && strcmp(unit_a, "dm") != 0 && strcmp(unit_a, "cm") != 0) || (strcmp(unit_b, "m") != 0 && strcmp(unit_b, "dm") != 0 && strcmp(unit_b, "cm") != 0));
    return 0;
}

// first external function
int Convert(char *unit, int before)
{
    int x; // x stands for edge length in centimeter.
    if (strcmp(unit, "dm") == 0)
        x = before * 10;
    else
        x = before * 100;

    return x;
}
// second external function
int Srand(int firstLength, int secondLength)
{
    int c; // the third edge length for the triangle

    int n, m; // m represents the smallest random number that can be generated, n represents the largest random number that can be generated.
    n = (firstLength + secondLength);
    m = abs(firstLength - secondLength);
    srand((unsigned int)time(NULL));
    c = rand() % (n - m + 1) + m;//The range of the generated random numbers is from m to n
    printf("Edge length 1 (input 1):%d cm\n", firstLength);
    printf("Edge length 2 (input 2):%d cm\n", secondLength);
    printf("Edge length 3 (rand):%d cm\n", c);
    return c;
}

// the third external function
int Scale(int First, int Second, int Third, double Height)
{
    // find the half value of the maximum edge length
    int maximumEdge,  beforeLength;
    double afterHeight;

    if (First>Second)
    {
        maximumEdge=First;
        if (maximumEdge<Third)
        {
            maximumEdge=Third;
        }
    }else{
        maximumEdge=Second;
        if (maximumEdge<Third)
        {
            maximumEdge=Third;
        }
    }
    beforeLength = maximumEdge / 2;

    // calculate the row number
    int row,column;
    if (beforeLength>10)
    {
       row=beforeLength;
        for (int i =0;row>10;i++)
        {
            row=row/10;
        }
    }else{
        row=beforeLength;
    }

    if ((int)Height>10)
    {
        column=Height;
        for (int i =0;column>10;i++)
        {
            column=column/10;
        }
    }else{
        column=Height;
    }




    int number;  // The number of symbols * in each line

    for (int i = 0; i <= row; i++)
    {
        number = column* i / row;//use equation 3

        if (number>0)
        {
            for (int s = 0; s < number; s++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}

