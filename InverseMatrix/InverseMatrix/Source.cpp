/*++
Inverse matrix
--*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 4

double* mat[N];

class Matrix {
private:
	double tmp;
	double inv_A[N][N];
	double A_buf[N][N];
public:
	void Inverse(double A[][N]);
};

void Matrix::Inverse(double A[][N]) {
	for (int i = 0; i < N; i++) {
		mat[i] = A[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A_buf[i][j] = A[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				inv_A[i][j] = 1.0;
			}
			else {
				inv_A[i][j] = 0.0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		tmp = 1.0 / A_buf[i][i];
		for (int j = 0; j < N; j++) {
			A_buf[i][j] *= tmp;
			inv_A[i][j] *= tmp;
		}
		for (int j = 0; j < N; j++) {
			if (i != j) {
				tmp = A_buf[j][i];
				for (int k = 0; k < N; k++) {
					A_buf[j][k] -= A_buf[i][k] * tmp;
					inv_A[j][k] -= inv_A[i][k] * tmp;
				}
			}
		}
	}

	return;
}

Matrix matrix;

int main() {
	const double A[N][N] = {
		{ 1, 2, 0, -1 },
		{ -1, 1, 2, 0 },
		{ 2, 0, 1, 1 },
		{ 1, -2,-1, 1 }
	};
	double A_buf[N][N];
	double inv_A[N][N];
	double tmp;

	memcpy(A_buf, A, sizeof(A));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				inv_A[i][j] = 1.0;
			}
			else {
				inv_A[i][j] = 0.0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		tmp = 1.0 / A_buf[i][i];
		for (int j = 0; j < N; j++) {
			A_buf[i][j] *= tmp;
			inv_A[i][j] *= tmp;
		}
		for (int j = 0; j < N; j++) {
			if (i != j) {
				tmp = A_buf[j][i];
				for (int k = 0; k < N; k++) {
					A_buf[j][k] -= A_buf[i][k] * tmp;
					inv_A[j][k] -= inv_A[i][k] * tmp;
				}
			}
		}
	}
	
	//matrix.Inverse(A_buf);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %f", inv_A[i][j]);
		}
		printf("\n");
	}

	getchar();
	return 0;
}