#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

const static int LAP_BUFF_SIZE = 5;

class StopWatch {
private:
	double			start;		//Relative time when count is started
	double			end;		//Time from start to end
	vector<double>	lap;		//Time from start to lap
	bool			is_started;	//True: Time count started, False: Not started
	double			Get(void);	//Get relative time from system boot
public:
	StopWatch();
	~StopWatch();
	void	Start(void);
	bool	Lap(void);
	bool	Stop(void);
	void	Print(void);
};

StopWatch::StopWatch()
	:start(0.0), 
	 end(0.0), 
	 is_started(false)
{
}

StopWatch::~StopWatch()
{
}

void StopWatch::Start() {
	//Clear time
	this->end = 0.0;
	this->lap.clear();
	this->lap.shrink_to_fit();

	this->start = this->Get();
	this->is_started = true;
	return;
}

bool StopWatch::Lap() {
	double now; //Relative time from system boot

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
	double now; //Relative time from system boot

	if (is_started == false) {
		cerr << "Stop() called before SetStart()" << endl;
		return false;
	}

	now = this->Get();
	this->end = now - this->start;
	return true;
}

double StopWatch::Get(void) {
	double sys_time;
	static LARGE_INTEGER freq;
	LARGE_INTEGER time;

	if (freq.QuadPart == 0) {
		QueryPerformanceFrequency(&freq);
	}
	QueryPerformanceCounter(&time);
	sys_time = (double)time.QuadPart / (double)freq.QuadPart;
	return sys_time;
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

	//--------------------------------
	Sleep(500); //0.5s
	//--------------------------------
	sw.Lap();

	//--------------------------------
	Sleep(500); //0.5s
	//--------------------------------

	sw.Stop();
	sw.Print();

	getchar();
	return 0;
}