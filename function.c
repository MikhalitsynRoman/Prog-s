#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include.h"
#define eps 1e-15

double Det (double , double , double , double );
double Det (double a, double b, double c, double d) 
{
	return a * d - b * c;
}

int equal (double , double );        
int equal (double a, double b) {return fabs(a-b) <= eps * fmax(fabs(a), fabs(b));}

int eq  (point , point );
int eq  (point A, point B) {return (equal(A.x, B.x) && equal(A.y, B.y));}






int intersect (point , point , point , point , point *);
int intersect (point a, point b, point c, point d, point *res)
{

 double A1, B1, C1, A2, B2, C2, zn, X, Y;
 A1=b.y-a.y;                                             //cмотрим на луч справа и слева по его уравнению обычной прямой 
 B1=a.x-b.x;
 C1=-(B1*a.y) - A1*a.x;
 A2=d.y-c.y;
 B2=c.x-d.x;
 C2=-(B2*c.y) - A2*c.x;
 zn = Det(A1, B1, A2, B2); 
 if(fabs(zn) < eps && fabs(Det(A1, C1, A2, C2)) < eps && fabs(Det(B1, C1, B2, C2)) < eps) return -1;
 else if (fabs(zn) < eps) return 0;
 X = -Det(C1, B1, C2, B2)/zn;
 Y = -Det(A1, C1, A2, C2)/zn;
 res->x=X;
 res->y=Y;
 return 1;
}


int isinside (point * pts, int n, point o)
{
 int i, bol, i1=0, i2=0, flg=0, j;
 point t, res;
 t.x = o.x + 1;     //сдивагаем вправо чтоб не совпадало
 t.y = o.y ;
 for(i=0; i<n-1; ++i)
 {
        j = i+1;
 	bol = intersect(pts[i], pts[j], t, o, &res);  // посмотрим на значения
	if(bol == 1)
	{
		if(res.x > o.x)     //cмотрим на пересечине справа
		{
			if((eq(pts[i], res) && pts[j].y<o.y) || (eq(pts[j], res) && pts[i].y<o.y)) ++i1;     // по y лежит выше 
			else if ( !eq(pts[i], res) && (((fabs((res.x-pts[i].x) / (pts[j].x-pts[i].x)) < 1) && (fabs((res.x-pts[j].x) / (pts[j].x-pts[i].x)) < 1)) || ((fabs((res.y-pts[i].y) / (pts[j].y-pts[i].y)) < 1) && (fabs((res.y-pts[j].y) / (pts[j].y-pts[i].y)) < 1))))  ++i1;
		}
		else if(res.x < o.x)    //cмотрим на пересечине слева
		{
                	if((eq(pts[i], res) && pts[j].y<o.y) || (eq(pts[j], res) && pts[i].y<o.y)) ++i2;    //cмотрим опять на y все тоже самое что и выше

			else if ( !eq(pts[i], res) && (((fabs((res.x-pts[i].x) / (pts[j].x-pts[i].x)) < 1) && (fabs((res.x-pts[j].x) / (pts[j].x-pts[i].x)) < 1)) || ((fabs((res.y-pts[i].y) / (pts[j].y-pts[i].y)) < 1) && (fabs((res.y-pts[j].y) / (pts[j].y-pts[i].y)) < 1))))  ++i2;

		}
	         // лежит на продолжении ребра это все равно вне а не на
		if(eq(res, o) && (eq(o, pts[i]) || eq(o, pts[j]) || (o.x > pts[i].x && o.x < pts[j].x) || (o.x > pts[j].x && o.x < pts[i].x) || (o.y > pts[i].y && o.y < pts[j].y) || (o.y > pts[j].y && o.y < pts[i].y ))) ++flg;	
	}

		//если на ребре
	if(bol==-1)
	{
			if(eq(o, pts[i]) || eq(o, pts[j]) || (o.x > pts[i].x && o.x < pts[j].x) || (o.x > pts[j].x && o.x < pts[i].x)) ++flg;  //условие на то что лежит строго на ребре а не на продолжении
	}	
 }
 if(flg) return 3;                           // на ребре
 if(i1 % 2 == 1 && i2 % 2 == 1) return 1;     //внутри
 if(i1 % 2 == 0 && i2 % 2 == 0) return 2;   // снаружи
 return 0;
}   