#include <iostream>

#define M 10 //Approximation order

using namespace std;

//Calculate the number of elements in array
template<typename tArray>
std::size_t getArraySize(tArray& iArray) {
	return std::extent<tArray>::value;
}

int LeastSquaresMethod(const double x[], const double y[], const int dataSize, //Input
					   double coef[]) {										   //Output
	double a[M + 1][M + 2];
	double s[2 * M + 1] = {0.0};
	double t[M + 1] = {0.0};
	double p, d;

	for (int i = 0; i < dataSize; i++) {
		for (int j = 0; j <= 2 * M; j++) {
			s[j] += pow(x[i], j);
		}
		for (int j = 0; j <= M; j++) {
			t[j] += pow(x[i], j) * y[i];
		}
	}

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			a[i][j] = s[i + j];
		}
		a[i][M + 1] = t[i];
	}

	for (int k = 0; k <= M; k++) {
		p = a[k][k];
		for (int j = k; j <= M + 1; j++) {
			a[k][j] /= p;
		}
		for (int i = 0; i <= M; i++) {
			if (i != k) {
				d = a[i][k];
				for (int j = k; j <= M + 1; j++)
					a[i][j] -= d * a[k][j];
			}
		}
	}

	for (int k = 0; k <= M; k++) {
		coef[k] = a[k][M + 1];
	}

	return 0;
}

int main() {
	int ArraySize;
	double x[] = {  0.0,  1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0, 10.0 };
	double y[] = { -2.0,  1.0,  4.0, -5.0,  0.0, -3.0,  4.0,  2.0,  3.0, -1.0, -4.0 };
	double a[M + 1] = {};
	double val = 0;

	if (getArraySize(x) == getArraySize(y)) {
		ArraySize = getArraySize(x);
	}
	else {
		std::cerr << "Array sizes should be same" << std::endl;
		return -1;
	}
	
	LeastSquaresMethod(x, y, ArraySize, a);
	for (int i = 0; i <= M; i++) {
		cout << "a" << i << " = " << a[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < ArraySize; i++) {
		val = 0;
		for (int j = 0; j <= M; j++) {
			val += a[j] * pow(x[i], j);
		}
		cout << i << "\t" << y[i] << "\t" << val << endl;
	}

	return 0;
}