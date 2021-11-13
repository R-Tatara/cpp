#include <iostream>
#include <math.h>
using namespace std;

double GetDistance(double x1, double y1, double z1, double x2, double y2, double z2);

int main() {
	double x1 = 0.0;
	double y1 = 0.0;
	double x2 = 100.0;
	double y2 = 200.0;
	double x3 = 20.0;
	double y3 = 70.0;
	double x4 = 80.0;
	double y4 = 30.0;
	double denom, tmp1, tmp2, nume_x, nume_y; //For intersection calculation
	double x, y; //Intersection of vector1_2 and vector3_4

	//Intersection calculation
	tmp1 = y3 * x4 - x3 * y4;
	tmp2 = y1 * x2 - x1 * y2;
	nume_x = tmp1 * (x2 - x1) - tmp2 * (x4 - x3); nume_y = tmp1 * (y2 - y1) - tmp2 * (y4 - y3);
	denom = (y2 - y1) * (x4 - x3) - (x2 - x1) * (y4 - y3);
	if (!denom) {
		cout << "Parallel line" << endl;
		return 0;
	}
	x = nume_x / denom;
	y = nume_y / denom;
	cout << "Intersection:" << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	return 0;
}

double GetDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	double distance;
	distance = pow((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1), 0.5F);
	return distance;
}