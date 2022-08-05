#include "include.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define eps 1e-12

int chek(double* x, double* y, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ((fabs(x[i] - x[j]) <= eps) && (fabs(y[i] - y[j]) <= eps)  )  
			{
				printf("circles with numbers %d and %d have the same coordinates\n", i, j);
				return 1;
			}
		}
	}
	return 0;
}

