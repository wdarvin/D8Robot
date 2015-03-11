#include <math.h>
#define RADTODEG 57.2957795
double getAngle(double fx, double fy)	{
	double sx, sy, distance, angle, dx, dy, radicand;
	
	
	sx = RPS.X();
	sy = RPS.Y();
	dx = fx-sx;
	dy = fy-sy;
	
	radicand = pow(dx,2) + pow(dy, 2);
	distance = sqrt(radicand);
	
	if (dy >= 0)	{
		angle = acos(dx/distance) * RADTODEG;
	} else if (dy < 0  && dx < 0)	{
		angle = (360 - acos(dx/distance))*RADTODEG;
	} else if (dy < 0 && dx >= 0)	{
		angle = -acos(dx/distance)*RADTODEG;
	}
	
	return (angle+90)%360;
}
	
	
	