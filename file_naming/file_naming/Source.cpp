#include <fstream>
#include <time.h>
#include "Source.h"


int main() {
	time_t tim = time(NULL);
	struct tm now_time;
	errno_t error;
	char filename[64];

	error = localtime_s(&now_time, &tim);
	
	sprintf_s(filename, "/Users/rabum/source/repos/file_naming/%04d%02d%02d%02d%02d%02d.txt",
		now_time.tm_year + 1900,
		now_time.tm_mon + 1,
		now_time.tm_mday,
		now_time.tm_hour,
		now_time.tm_min, 
		now_time.tm_sec);
	
	std::ofstream ofs(filename);
	ofs.clear();
	ofs.seekp(0);
	ofs << "Test" << std::endl;

	return 0;
}