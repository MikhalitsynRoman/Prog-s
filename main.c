#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include.h"

int main(void)
{
	point *array, o;
	FILE *file;
	char file_name[40];
	int n = 0, res;
	int i;


	printf("Enter the name of your file: \n");
	scanf("%s", file_name);

	if ( (file = fopen(file_name, "r") ) == NULL ){

		printf("This file cannot be open \n"); return -1;}

	fscanf(file, "%d", &n);
	array =(point *)malloc (n*sizeof(point));
	for (i = 0; i < n; ++i)
	{
		fscanf(file, "%lf %lf", &(array[i].x), &(array[i].y)); 		
	}	
	printf("Enter coordinates of point: \n");
        scanf("%lf %lf", &(o.x), &(o.y));
	res = isinside(array, n, o);
	if (res==1)  printf("point is inside: \n");
	if (res==2)  printf("point is outside: \n");
	if (res==3)  printf("point is on the edge: \n");



return 0;	

}