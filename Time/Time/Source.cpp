#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

class Time {
public:
	double start;
	double now;
	double cycle;
	double tmp;
	double prev;
	double Get(void) {
		static LARGE_INTEGER freq;
		if (freq.QuadPart == 0) {
			QueryPerformanceFrequency(&freq);
		}

		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);
		return (time.QuadPart / (double)freq.QuadPart);
	}
	int Update(void) {
		this->tmp = this->Get();
		this->now = this->tmp - this->start;
		this->cycle = this->now - this->prev;
		this->prev = this->now;
		return 0;
	}
};

Time t;

int main()
{
	t.start = t.Get();

	for (int i = 0; i < 10000; i++) {
		t.Update();

		cout << fixed
			<< "Cycle : " << i
			<< setprecision(4)
			<< "\tTime[s] : " << t.now
			<< "\tLoopTime[ms] : " << t.cycle * 1000
			<< endl;
	}

	getchar();
	return 0;
}