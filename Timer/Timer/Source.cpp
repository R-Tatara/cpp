#include <iostream>
#include <windows.h>
#include <time.h>
#include <vector>
using namespace std;

class Time {
private:
	double start;
	double prev;
    vector<double> rap;
	double end;
    double Get(void);
    bool is_started;
public:
    Time();
    void SetStart(void);
    int SetRap(void);
    int SetEnd(void);
    void Print(void);
};

Time::Time()
    :start(0.0), prev(0.0), end(0.0), is_started(false)
{
}

void Time::SetStart () {
    this->start = this->Get();
    this->prev = this->start;
    this->is_started = true;
    return;
}

int Time::SetRap() {
    double now;

    if (this->is_started == false) {
        cerr << "SetRap() called without SetStart()" << endl;
        return false;
    }
    now = this->Get();
    this->rap.push_back(now - this->prev);
    if (this->rap.size() >= 256) {
        cerr << "Rap time queue length exceeded the limit" << endl;
        exit(0);
    }
    this->prev = now;
    return true;
}

int Time::SetEnd() {
    double now;

    if (is_started == false) {
        cerr << "SetEnd() called without SetStart()" << endl;
        return false;
    }
    now = this->Get();
    this->end = now - this->start;
    return true;
}

double Time::Get(void) {
    double ret;
    static LARGE_INTEGER freq;
    LARGE_INTEGER time;

    if (freq.QuadPart == 0) {
        QueryPerformanceFrequency(&freq);
    }
    QueryPerformanceCounter(&time);
    ret = time.QuadPart / (double)freq.QuadPart;
    return ret;
}

void Time::Print() {
    for (unsigned int i = 0; i < this->rap.size(); i++) {
        cout << "Rap(" << i + 1 << ") : " << this->rap[i] << " [s]" << endl;
    }
    cout << "Total : " << this->end << " [s]" << endl;
    return;
}

Time t;

int main()
{
    t.SetStart();

	for (int i = 0; i < 5; i++) {
        Sleep(500); //0.5s
		t.SetRap();
	}
    t.SetEnd();
    t.Print();

	getchar();
	return 0;
}