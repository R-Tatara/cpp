#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

int main() {
    time_t tim = time(NULL);
    struct tm now_time;
    errno_t error;
    char filename[64];

    error = localtime_s(&now_time, &tim);

    sprintf_s(filename, "Sample_%04d%02d%02d-%02d%02d%02d.txt",
        now_time.tm_year + 1900,
        now_time.tm_mon + 1,
        now_time.tm_mday,
        now_time.tm_hour,
        now_time.tm_min,
        now_time.tm_sec);

    ofstream ofs(filename);
    if (!ofs) {
        cerr << "Failed to open file." << endl;
    }
    ofs << "Test" << endl;
    ofs.close();

    return 0;
}