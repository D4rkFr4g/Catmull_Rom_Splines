/****************************************************** 
* Project:         CS 116A Homework #4
* File:            catmullRomSpline.h
* Purpose:         Implement a curve drawing algorithm
* Start date:      11/17/13 
* Programmer:      Zane Melcho 
* 
****************************************************** 
*/

#include "cvec.h"

using namespace std;

class catmullRomSpline
{
	// This class calculates the interpolation of a catmull rom spline

public:
	static Cvec3 interpolate(Cvec3 *splineArray, int index, float time);

private:
};
/*-----------------------------------------------*/
Cvec3 catmullRomSpline::interpolate(Cvec3 *splineArray, int index, float time)
{
	/* PURPOSE:		Calculates the position of an interpolated point between two catmull rom control points 
		RECEIVES:   splineArray - Array of Cvec3's that make up the spline
						index - Current position in the spline array
						time - Current time in interpolation
		RETURNS:    Cvec3 of current interpolated position
		REMARKS:		Precondition: Should not pass an index more than 2 from the end of the array
	*/

	Cvec3 pointBefore = splineArray[index - 1];
	Cvec3 point = splineArray[index];
	Cvec3 pointAfter = splineArray[index+1];
	Cvec3 pointPlusTwo = splineArray[index+2];

	Cvec3 d = ((pointAfter - pointBefore) * (1.0/6)) + point;
	Cvec3 e =  ((pointPlusTwo - point) * (-1.0/6)) + pointAfter;

	Cvec3 f = (point * (1 - time)) + (d * time);
	Cvec3 g = (d * (1 - time)) + (e * time);
	Cvec3 h = (e * (1 - time)) + (pointAfter * time);
	Cvec3 m = (f * (1 - time)) + (g * time);
	Cvec3 n = (g * (1 - time)) + (h * time);
	Cvec3 final = (m * (1 - time)) + (n * time);

	return final;
}
/*-----------------------------------------------*/