#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "core.h"

double Linear (double b, double c)
{
	assert (isfinite(b));
	assert (isfinite(c));

	if (c == 0) return 0;
	else return -c/b;
}

int SolveEquation (double a, double b, double c, double* x1, double* x2)
{
	assert (isfinite(a));
	assert (isfinite(b));
	assert (isfinite(c));

	assert (x1 != NULL);
	assert (x2 != NULL);
	assert (x1 != x2);

	if (fabs(a) <= EPS)
	{
		if (fabs(b) <= EPS)
		{
			return (fabs(c) <= EPS) ? SS_INF_ROOTS : 0;
		}
		else
		{
			*x1 = Linear(b, c);
			return 1;
		}
	}
	else if (fabs(c) <= EPS)
	{
		if (fabs(b) >= EPS) {
			*x1 = 0;
			*x2 = Linear(a, b);
			return 2;
		}
		else {
			*x1 = 0;
			return 1;
		}
	}
	else
	{
		double d = b * b - 4 * a * c;
		if (fabs(d) <= EPS)
		{
			*x1 = -b / (2 * a);
			return 1;
		}
		else if (d >= EPS)
		{
			double sqrt_d = sqrt(d);
			*x1 = (-b - sqrt_d) / (2 * a);
			*x2 = (-b + sqrt_d) / (2 * a);
			return 2;
		}
		else {
			return 0;
		}
	}
}
int roots_equal(double a, double b) {
	
	if (isnan(a) == isnan(b)) {
		if (isnan(a) && isnan(b)) {
			return 1;
		}
		else if (a == b) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}
void SquareTest(double a, double b, double c, double x1, double x2, int n) 
{
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	printf("Testing with a = %lg, b = %lg, c = %lg \n", a, b, c);
	printf("Expected roots are: x1 = %lg, x2 = %lg \n", x1, x1);
	printf("Expected number of roots is: n = %d\n", n);

	double xx1 = NAN, xx2 = NAN;
	int m = SolveEquation(a, b, c, &xx1, &xx2);

	//Сравниваем полученное с тем, что должно быть
	int correct = 0;
	if (n != m) {
		printf("Error! Wrong number of roots. Expected: %d. Obtained: %d\n", n, m);
		correct++;
	}
	if (!roots_equal(x1, xx1)) {
		printf("Error! Wrong root n1. Expected: %lg. Obtained: %lg\n", x1, xx1);
		correct++;
	}
	if (!roots_equal(x2, xx2)) {
		printf("Error! Wrong root n2. Expected: %lg. Obtained: %lg\n", x2, xx2);
		correct++;
	}
	if (correct == 0) printf("Test successful\n\n");
	else printf("Test Failed");

}