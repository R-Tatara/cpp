#include <iostream>
using namespace std;

#define PI 3.14159265358979323846264338327950288
#define SAMPLING_TIME 0.01 //[s]

//Quadrature by parts
class Simple {
private:
	double sum;
public:
	Simple();
	void Integral(double data);
	double GetResult(void);
};

Simple::Simple()
	: sum(0.0)
{
}

void Simple::Integral(double data) {
	this->sum += data * SAMPLING_TIME;
	return;
}

double Simple::GetResult(void) {
	return this->sum;
}

//Trapezoidal rule
class Trapezoid {
private:
	int cycle;
	double data_pre;
	double sum;
public:
	Trapezoid();
	void Integral(double data);
	double GetResult(void);
};

Trapezoid::Trapezoid()
	: cycle(0), data_pre(0.0), sum(0.0)
{
}

void Trapezoid::Integral(double data) {
	if (this->cycle == 0) {
		this->data_pre = data;
	}
	else {
		this->sum += (this->data_pre + data) * SAMPLING_TIME / 2.0;
	}
	this->data_pre = data;
	this->cycle++;
	return;
}

double Trapezoid::GetResult(void) {
	return this->sum;
}

//Simpson's rule
class Simpson {
private:
	int cycle;
	double data_pre;
	double offset;
	double s1;
	double s2;
	double sum_odd;
	double sum;
public:
	Simpson();
	void Integral(double data);
	double GetResult(void);
};

Simpson::Simpson()
	:cycle(0),
	data_pre(0.0),
	offset(0.0),
	s1(0.0),
	s2(0.0),
	sum_odd(0.0),
	sum(0.0)
{
}

void Simpson::Integral(double data) {
	if (this->cycle == 0) {
		this->offset = data;
	}
	else if (this->cycle % 2 == 1) { //Cycle is odd
		this->s1 += data;
		this->sum_odd = this->sum + (this->data_pre + data) * SAMPLING_TIME / 2.0;
	}
	else if (this->cycle % 2 == 0 && this->cycle != 0) { //Cycle is even
		this->s2 += data;
		this->sum = SAMPLING_TIME / 3.0 * (this->offset - data + 4.0 * this->s1 + 2.0 * this->s2);
		this->sum_odd = this->sum;
	}
	this->data_pre = data;
	this->cycle++;
	return;
}

double Simpson::GetResult(void) {
	if (this->cycle % 2 == 1) { //Cycle is odd
		cout << "[WARN]Simpson integration interval is odd." << endl;
	}
	return this->sum;
}

Simple simple;
Trapezoid trapezoid;
Simpson simpson;

int main() {
	double time;
	double data;

	for (int i = 0; i < 314; i++) {
		time = (double)i * SAMPLING_TIME;
		data  = sin(time);
		simple.Integral(data);
		trapezoid.Integral(data);
		simpson.Integral(data);

		cout << "Time = " << time << " Value = " << data << endl;
	}

	cout << endl << "--- Integration result ---" << endl;
	cout << "Simple    : " << simple.GetResult() << endl;
	cout << "Trapezoid : " << trapezoid.GetResult() << endl;
	cout << "Simpson   : " << simpson.GetResult() << endl;

	getchar();
	return 0;
}