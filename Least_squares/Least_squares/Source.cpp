#include <iostream>

using namespace std;

int LeastSquaresMethod(const double x[], const double y[], const int dataSize,	//Input
					   double *a0, double *a1) {								//Output
	double A00 = 0, A01 = 0, A02 = 0, A11 = 0, A12 = 0;

	for (int i = 0; i < dataSize; i++) {
		A00 += 1.0;
		A01 += x[i];
		A02 += y[i];
		A11 += x[i] * x[i];
		A12 += x[i] * y[i];
	}

	if (A00 * A11 - A01 * A01 != 0.0) {
		*a0 = (A02 * A11 - A01 * A12) / (A00 * A11 - A01 * A01);
		*a1 = (A00 * A12 - A01 * A02) / (A00 * A11 - A01 * A01);
	}
	else {
		cout << "[ERROR] division by zero" << endl;
		return -1;
	}

	return 0;
}
 
int main() {
	double x[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double y[] = { 3.0, 4.0, 5.0, 6.0, 7.0 };
	double intercept = 0.0;
	double slope = 0.0;
	int dataSize;
	int Nx = sizeof(x) / sizeof(x[0]);
	int Ny = sizeof(y) / sizeof(y[0]);

	if (Nx == Ny) {
		dataSize = Nx;
		LeastSquaresMethod(x, y, dataSize, &intercept, &slope);
		cout << "Slope : " << slope << "\nIntercept : " << intercept << endl;
	}
	else {
		cout << "Different size of array." << endl;
		return -1;
	}

	getchar();
	return 0;
}