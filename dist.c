#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 1e-12

double dist(double* x, double* y, int i, int j, double* r)
{
	double R = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	R -= r[j];  //�� 0 ���� ���������� �� ���� - �������� ����
	if ((fabs(r[j]) >= eps))
	{
		R *= 2;
	}
	return R;
}
             //������ ������ 2 ������� ����� �������� 2 ������ ��� �� �� 0 �� �� ���� ������ 1 
