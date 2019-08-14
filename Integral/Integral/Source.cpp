#include <stdio.h>
#include <math.h>
#include <conio.h>

#define PI 3.14159265358979323846264338327950288
#define FUNCTION(TIME) (sin(TIME)) 
#define SAMPLING_TIME 0.001 //[s]
#define MAX_TIME 3.14  //[s]

class Num {
public:
	double data_buf;
	double data;
	int function(double time) {
		this->data_buf = FUNCTION(time - SAMPLING_TIME);
		this->data = FUNCTION(time);
		return 0;
	}
};

//Quadrature by parts
class Simple {
public:
	double sum;
	int  Integral(double data) {
		this->sum += data * SAMPLING_TIME;
		return 0;
	}

	Simple() {
		sum = 0.0;
	}
};

//Trapezoidal rule
class Trapezoid {
public:
	double sum;
	int  Integral(int cycle, double data_buf, double data) {
		if (cycle != 0) {
			this->sum += (data_buf + data) * SAMPLING_TIME / 2.0;
		}
		return 0;
	}

	Trapezoid() {
		this->sum = 0.0;
	}
};

//Simpson's rule
class Simpson {
public:
	double sum;
	double sum_a;
	double s1;
	double s2;
	double tmp;
	int Integral(int cycle, double data_buf, double data) {
		if (cycle == 0) {
			this->tmp = data;
		}
		else if (cycle % 2 == 1) {
			this->s1 += data;
			this->sum_a = sum + (data_buf + data) * SAMPLING_TIME / 2.0; //Complemened by Trapezoidal rule
		}
		else if (cycle % 2 == 0 && cycle != 0) {
			this->s2 += data;
			this->sum = SAMPLING_TIME / 3.0 * (this->tmp - data + 4.0 * s1 + 2.0 * s2);
			this->sum_a = this->sum;
		}
		return 0;
	}

	Simpson() {
		this->sum = 0.0;
		this->sum_a = 0.0;
		this->s1 = 0.0;
		this->s2 = 0.0;
	}
};

Num num;
Simple simple;
Trapezoid trapezoid;
Simpson simpson;

int main() {
	int i = 0;
	double time = 0.0;

	while (time < MAX_TIME) {
		time = SAMPLING_TIME * i;
		num.function(time);
		simple.Integral(num.data);
		trapezoid.Integral(i, num.data_buf, num.data);
		simpson.Integral(i, num.data_buf, num.data);
		printf("Time : %lf, Val : %+lf, Sum1 : %+lf, Sum2 : %+lf, Sum3 : %+lf\n",
			time,
			num.data,
			simple.sum,
			trapezoid.sum,
			simpson.sum_a);
		i++;
	}

	getchar();
	return 0;
}