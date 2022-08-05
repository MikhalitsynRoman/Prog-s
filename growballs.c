#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include.h"
#define eps 1e-12


void growBall(double* x, double* y, double* r, int n)
{
	int iMin, jMin, t;
	double rMin, R;
	for (int k = 0; k < n; k++)    // 
	{
		t = 0;
		rMin = 0;  // ����������� ������ � ��������
		for (int i = 0; i < n; i++)
		{
			if ((fabs(r[i])) >= eps)
			{
				t++;               // ���� ������ 0 �� �� ���� �� ������
				continue;
			}
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;            // ���� �� ���� ���������� ����� ����
				}
				R = dist(x, y, i, j, r);
			//	printf("%lf\n", R);
				if ((R < rMin ) || ((fabs(rMin)) <= eps))
				{
					rMin = R;              // � ���� ���������� ����������� ���������� ����� ������������� ���� ���
					iMin = i;        // ��� ��������� ����� �� ������� ��������
					jMin = j;
				}
			}
		}
		if (t == n)
		{
			return;  // ���� ��� �� 0 �����������
		}
		if (fabs(r[jMin]) <= eps)
		{
			r[jMin] = rMin / 2.0;      // ���� 0 �� ����� �� 2 �� ������ ��� 
		}
		r[iMin] = rMin / 2.0;
	}
}

