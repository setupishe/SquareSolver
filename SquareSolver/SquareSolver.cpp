#include <math.h>
#include <stdio.h>
#include "core.h"

// #define SS_INF_ROOTS 3

int main()
{
    printf("#Square equation solver\n"
        "#(c)Vasily Sokolov, 2021\n\n");


    printf("Testing...\n\n");
    SquareTest(0, 0, 0, NAN, NAN, SS_INF_ROOTS);
    SquareTest(1, 1, 1, NAN, NAN, 0);
    SquareTest(1, 0, 0, 0, NAN, 1);
    SquareTest(0, 1, 0, 0, NAN, 1);
    SquareTest(0, 0, 1, NAN, NAN, 0);
    SquareTest(0, 1, 1, -1, NAN, 1);
    SquareTest(1, 1, 0, 0, -1, 2);
    SquareTest(1, 0, 1, NAN, NAN, 0);
    SquareTest(1, 2, 1, -1, NAN, 1);
    SquareTest(1, -5, 6, 2, 3, 2);

    printf("# Enter a, b, c: ");

    double a = NAN, b = NAN, c = NAN;
    if (scanf("%lg %lg %lg", &a, &b, &c) != 3) {
        printf("Incorrect input\n");
        return 1;
    }

    double x1 = NAN, x2 = NAN;
    int nRoots = SolveEquation(a, b, c, &x1, &x2);



    switch (nRoots)
    {
    case 0: printf("No roots\n");
        break;
    case 1: printf("x = % lg\n", x1);
        break;
    case 2: printf("x1 = % lg, x2 = % lg\n", x1, x2);
        break;
    case SS_INF_ROOTS: printf("Any number");
        break;
    default: printf("main() : ERROR : nRoots = % d\n",
        nRoots);
        return 1;
    }
    return 0;
}

