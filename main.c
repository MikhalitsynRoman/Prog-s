#include "include.h"

int main(void)
{
	double* x, * y, * r;
	int n;
	scanf("%d", &n);
	x = (double*)malloc(n * sizeof(double));
	y = (double*)malloc(n * sizeof(double));
	r = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &x[i]);
		scanf("%lf", &y[i]);
		r[i] = 0;
	}
	if (!chek(x, y, n))
	{
		growBall(x, y, r, n);
		for (int i = 0; i < n; i++)
		{
			printf("%lf\n", r[i]);
		}
	}
	free(x);
	free(y);
	free(r);
	return 0;
}