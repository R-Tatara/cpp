#include <stdio.h>
#include <iostream>
using namespace std;

void mul(const double ma[3][3], const double mb[3][3], double m_ans[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m_ans[i][j] = 0;
			for (int k = 0; k < 3; k++)
				m_ans[i][j] += ma[i][k] * mb[k][j];
		}
	}
}

int main() {
	double A[3][3] = { { 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0 } };
	double B[3][3] = { { 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0 } };
	double ans[3][3];

	mul(A, B, ans);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	getchar();
	return (0);
}
