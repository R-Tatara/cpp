#include <iostream>

double* b[2];
double* c[2];

void func1(double(*a)[2]) {
	b[0] = a[0];
	b[1] = a[1];
	return;
}

void func2(double a[][2]) {
	c[0] = a[0];
	c[1] = a[1];
	return;
}

int main() {
	double a[2][2] = { { 0.0, 1.0 }, { 2.0, 3.0 } };
	func1(a);
	func2(a);

	for (int i = 0; i < 2; i++) {
		std::cout << b[i][0] << " " << b[i][1] << std::endl;
		std::cout << c[i][0] << " " << c[i][1] << std::endl;
	}

	getchar();
	return 0;
}