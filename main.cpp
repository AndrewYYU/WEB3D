// CircleRet.cpp : 定義主控台應用程式的進入點。
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>  // for atof
#include <math.h>
#include "GraphicsGems.h"

boolean Check_Intersect(Box2 *R, Point2 *C, double Rad)
{
	double Rad2;

	Rad2 = Rad * Rad;
	/* Translate coordinates, placing C at the origin. */
	R->max.x -= C->x;  R->max.y -= C->y;
	R->min.x -= C->x;  R->min.y -= C->y;

	if (R->max.x < 0) 			/* R to left of circle center */
		if (R->max.y < 0) 		/* R in lower left corner */
			return ((R->max.x * R->max.x + R->max.y * R->max.y) < Rad2);
		else if (R->min.y > 0) 	/* R in upper left corner */
			return ((R->max.x * R->max.x + R->min.y * R->min.y) < Rad2);
		else 					/* R due West of circle */
			return(ABS(R->max.x) < Rad);
	else if (R->min.x > 0)  	/* R to right of circle center */
		if (R->max.y < 0) 	/* R in lower right corner */
			return ((R->min.x * R->min.x + R->max.y * R->max.y) < Rad2);
		else if (R->min.y > 0)  	/* R in upper right corner */
			return ((R->min.x * R->min.x + R->min.y * R->min.y) < Rad2);
		else 				/* R due East of circle */
			return (R->min.x < Rad);
	else				/* R on circle vertical centerline */
		if (R->max.y < 0) 	/* R due South of circle */
			return (ABS(R->max.y) < Rad);
		else if (R->min.y > 0)  	/* R due North of circle */
			return (R->min.y < Rad);
		else 				/* R contains circle centerpoint */
			return(TRUE);
}
int main(int argc, char *argv[])
{
	if (argc != 8) {
		printf("%d", 0);
		exit(1);
	}
	else {
		//double x1, y1, x2, y2, cx, cy, rr;
		double x1 = atof(argv[1]);
		double y1 = atof(argv[2]);
		double x2 = atof(argv[3]);
		double y2 = atof(argv[4]);
		double cx = atof(argv[5]);
		double cy = atof(argv[6]);
		double rr = atof(argv[7]);
		//printf("%lf %lf %lf %lf %lf %lf %lf\n", x1, y1, x2, y2, cx, cy, rr);
		Point2 min_Rect, max_Rect, Circ;
		Box2 Rect;
		min_Rect.x = x1;
		min_Rect.y = y1;
		max_Rect.x = x2;
		max_Rect.y = y2;
		Circ.x = cx;
		Circ.y = cy;
		Rect.min = min_Rect;
		Rect.max = max_Rect;
		boolean react = Check_Intersect(&Rect, &Circ, rr);
		printf("out %d", react);
	}
	exit(0);
}

