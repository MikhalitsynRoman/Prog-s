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
		rMin = 0;  // имнимальный радиус в итерации
		for (int i = 0; i < n; i++)
		{
			if ((fabs(r[i])) >= eps)
			{
				t++;               // если больше 0 то не ишем до других
				continue;
			}
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;            // ищем до всех окржностей кроме себя
				}
				R = dist(x, y, i, j, r);
			//	printf("%lf\n", R);
				if ((R < rMin ) || ((fabs(rMin)) <= eps))
				{
					rMin = R;              // в рмин записываем минимальное расстояние потом презаписываем если что
					iMin = i;        // два ближайщих круга на текущей итерации
					jMin = j;
				}
			}
		}
		if (t == n)
		{
			return;  // если все не 0 заканчиваем
		}
		if (fabs(r[jMin]) <= eps)
		{
			r[jMin] = rMin / 2.0;      // если 0 то делим на 2 тк растут оба 
		}
		r[iMin] = rMin / 2.0;
	}
}

