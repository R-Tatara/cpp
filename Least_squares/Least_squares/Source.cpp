#include <stdio.h>
#include <iostream>

using namespace std;

void LeastSquaresMethod(double x[], double y[], int N, double *a0, double *a1) {
	int i;
	double A00 = 0, A01 = 0, A02 = 0, A11 = 0, A12 = 0;

	for (i = 0; i < N; i++) {
		A00 += 1.0;
		A01 += x[i];
		A02 += y[i];
		A11 += x[i] * x[i];
		A12 += x[i] * y[i];
	}

	*a0 = (A02 * A11 - A01 * A12) / (A00 * A11 - A01 * A01);
	*a1 = (A00 * A12 - A01 * A02) / (A00 * A11 - A01 * A01);
}
 
int main() {
	double x[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double y[] = { 3.0, 4.0, 5.0, 6.0, 7.0 };
	double a0 = 0.0; //Intercept
	double a1 = 0.0; //Slope

	//The size of array 
	int N;
	int Nx = sizeof(x) / sizeof(x[0]);
	int Ny = sizeof(y) / sizeof(y[0]);

	if (Nx == Ny) {
		N = Nx;
		LeastSquaresMethod(x, y, N, &a0, &a1);
		cout << "Slope : " << a1 << "\nIntercept : " << a0 << endl;
	}
	else {
		cout << "Different size of array." << endl;
	}

	getchar();
	return 0;
}