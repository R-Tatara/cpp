#include <iostream>
#include <vector>
#include <windows.h>
#include <time.h>
using namespace std;

const static int LAP_BUFF_SIZE = 5;

class StopWatch {
private:
	double			start;
	double			end;
	vector<double>	lap;
	bool			is_started;
	double			Get(void);
public:
	StopWatch();
	~StopWatch();
	void	Start(void);
	bool	Lap(void);
	bool	Stop(void);
	void	Print(void);
};

StopWatch::StopWatch()
	:start(0.0), end(0.0), is_started(false)
{
}

StopWatch::~StopWatch()
{
}

void StopWatch::Start() {
	this->start = this->Get();
	this->end = 0.0;
	this->is_started = true;

	//Clear lap time
	this->lap.clear();
    this->lap.shrink_to_fit();
	return;
}

bool StopWatch::Lap() {
	double now;

	if (this->is_started == false) {
		cerr << "Lap() called before SetStart()" << endl;
		return false;
	}

	if (this->lap.size() < LAP_BUFF_SIZE) {
		now = this->Get();
		this->lap.push_back(now - this->start);
	}
	else {
		cerr << "Lap time buffer size exceeded the limit" << endl;
	}
	return true;
}

bool StopWatch::Stop() {
	double now;

	if (is_started == false) {
		cerr << "Stop() called before SetStart()" << endl;
		return false;
	}

	now = this->Get();
	this->end = now - this->start;
	return true;
}

double StopWatch::Get(void) {
	double sys_time_count;
	static LARGE_INTEGER freq;
	LARGE_INTEGER time;

	if (freq.QuadPart == 0) {
		QueryPerformanceFrequency(&freq);
	}
	QueryPerformanceCounter(&time);
	sys_time_count = time.QuadPart / (double)freq.QuadPart;
	return sys_time_count;
}

void StopWatch::Print() {
	for (unsigned int i = 0; i < this->lap.size(); i++) {
		cout << "Lap(" << i + 1 << ") : " << this->lap[i] << " [s]" << endl;
	}
	cout << "Time : " << this->end << " [s]" << endl;
	return;
}

int main()
{
	StopWatch sw;

	sw.Start();

	//Process 1
	Sleep(500); //0.5s
	sw.Lap();

	//Process 2
	Sleep(500); //0.5s
	sw.Lap();

	sw.Stop();
	sw.Print();

	getchar();
	return 0;
}