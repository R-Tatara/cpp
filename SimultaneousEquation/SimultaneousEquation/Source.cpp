/*++
Simultaneous eqation
--*/

#include <stdio.h>

#define N 4

class SimultaneousEqation {
private:
	double mat[N][N + 1];
	double tmp;
	double ans[N];
public:
	double *CalcGaussElimination(double A[N][N], double b[N]);
};

double *SimultaneousEqation::CalcGaussElimination(double A[N][N], double b[N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (j != N) {
				mat[i][j] = A[i][j];
			}
			else {
				mat[i][j] = b[i];
			}
			printf("%+f x%d ", mat[i][j], j + 1);
		}
		printf("= %+f\n", mat[i][N]);
	}

	//Forward elimination
	for (int k = 0; k < N - 1; k++) {
		for (int i = k + 1; i < N; i++) {
			tmp = mat[i][k] / mat[k][k];
			for (int j = k + 1; j <= N; j++)
				mat[i][j] -= mat[k][j] * tmp;
		}
	}
	//Back substitution
	for (int i = N - 1; i >= 0; i--) {
		tmp = mat[i][N];
		for (int j = i + 1; j < N; j++)
			tmp -= mat[i][j] * mat[j][N];
		mat[i][N] = tmp / mat[i][i];
		ans[i] = mat[i][N];
	}

	return ans;
}

SimultaneousEqation Simultaneous;

int main() {
	double mat[N][N] = {
		{ 1.0, 2.0, 0.0, -1.0 },
	{ -1.0, 1.0, 2.0, 0.0 },
	{ 2.0, 0.0, 1.0, 1.0 },
	{ 1.0, -2.0, -1.0, 1.0 }
	};
	double b[N] = { 3.0, -2.0, 4.0, 1.0 };
	double *ans = Simultaneous.CalcGaussElimination(mat, b);

	//Result
	for (int i = 0; i < N; i++) {
		printf("x%d = %f\n", i + 1, ans[i]);
	}

	getchar();
	return 0;
}