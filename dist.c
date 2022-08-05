#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 1e-12

double dist(double* x, double* y, int i, int j, double* r)
{
	double R = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	R -= r[j];  //от 0 ишем расстояние до всех - выросший круг
	if ((fabs(r[j]) >= eps))
	{
		R *= 2;
	}
	return R;
}
             //иногда растут 2 расстут тогда умножаем 2 иногда нет тк от 0 до не нуля только 1 
