#include <iostream>
using namespace std;

#define TIME_METHOD 1

#if TIME_METHOD //TIME_METHOD = 1
#include <time.h>

int main() {
	char date[20];
	struct tm now;
	time_t timer = time(NULL);
	errno_t error = localtime_s(&now, &timer);

	sprintf_s(date, "%04d/%02d/%02d %02d:%02d:%02d",
		now.tm_year + 1900, now.tm_mon + 1, now.tm_mday,
		now.tm_hour, now.tm_min, now.tm_sec);

	cout << date << endl;

	return 0;
}

#else //TIME_METHOD = 0
#include <windows.h>

int main() {
	char date[24];
	SYSTEMTIME timer;

	GetLocalTime(&timer); //JST
	//GetSytimeremTime(&timer); //UTC

	sprintf_s(date, "%04d/%02d/%02d %02d:%02d:%02d.%03d",
		timer.wYear, timer.wMonth, timer.wDay,
		timer.wHour, timer.wMinute, timer.wSecond,
		timer.wMilliseconds);

	cout << date << endl;

	return 0;
}
#endif

