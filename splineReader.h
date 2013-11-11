/****************************************************** 
* Project:         CS 116A Homework #4
* File:            splineReader.h
* Purpose:         Implement a curve drawwing algorithm
* Start date:      11/10/13 
* Programmer:      Zane Melcho 
* 
****************************************************** 
*/
#include <iostream>
#include <fstream>
#include <string>
#include "cvec.h"

using namespace std;

// Forward declarations


class splineReader
{
	// This class reads a .txt file that contains spline points
	// in the folowing format:
	// x1-float,z1-float
	// x2-float,z2-float

public:
	static Cvec3f* parseSplineFile(string filename);

private:
	static Cvec3f parseCvec(string spline);
	static void printCvec(Cvec3f splinePoint);
};
/*-----------------------------------------------*/
Cvec3f* splineReader::parseSplineFile(string filename)
{
	/* 	PURPOSE:    	Reads file and assigns spline points to array of Cvec3's 
		RECEIVES:	filename - string address of file to be read location 
		RETURNS:    	Cvec3 array that holds all spline points read from file 
		REMARKS:    	Precondition: filename must be valid
				Precondition: first line is number of points
	*/
	Cvec3f *splineArray;
	ifstream splineFile (filename);
		
	//Process file
	string spline = "";
	if (splineFile.is_open())
	{
		// Setup array
		string numOfPoints = "";
		getline(splineFile, numOfPoints);
		int size = atoi(numOfPoints.c_str());
		splineArray = new Cvec3f[size];
			
		int index = 0;
		while (getline(splineFile, spline))
		{
			//cout << spline << endl; // Check spline is created correct
			splineArray[index] = parseCvec(spline);
			//printCvec(splineArray[index]); // Check Cvec is stored correct
			index++;
		}
		splineFile.close();
	}
	else
		cout << "Could not open " << filename << endl;

	return splineArray;
}
/*-----------------------------------------------*/
Cvec3f splineReader::parseCvec(string spline)
{
	/* 	PURPOSE:	Converts string into Cvec3 
		RECEIVES:   	spline - string that contains Cvec coordinates 
		RETURNS:    	Cvec3f that contains parsed points of the spline
		REMARKS:	Precondition:	string format must be x1-float,z1-float
	*/
		
	// Split into two tokens
	string delimiter = ",";
	int comma = spline.find(delimiter);
	string tokenX = spline.substr(0, comma);
	string tokenZ = spline.substr(comma);

	// Convert tokens to floats
	float x = atof(tokenX.c_str());
	float z = atof(tokenZ.c_str());

	return Cvec3f(x, 0, z);
}
/*-----------------------------------------------*/
void splineReader::printCvec(Cvec3f splinePoint)
{
	/* 	PURPOSE:	Prints the Cvec3 
		RECEIVES:	splinePoint - The Cvec3f to be printed. 
	*/

	float x = splinePoint[0];
	float y = splinePoint[1];
	float z = splinePoint[2];

	cout << "<" << x << ", " << y << ", " << z << ">" << endl;
}
