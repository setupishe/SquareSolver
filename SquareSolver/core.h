#pragma once

const int SS_INF_ROOTS = 3;
const double EPS = 0.0000001;

//документация
double Linear(double b, double c);
//документация
int SolveEquation(double a, double b, double c, double* x1, double* x2);
//документация
int roots_equal(double a, double b);
//документация
void SquareTest(double a, double b, double c, double x1, double x2, int n);