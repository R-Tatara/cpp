#include <fstream>
#include <iostream>
#include <windows.h>
#include "Header.h"

//Global object definition
file logfile;

//Function definition
file InitFileName() {
    SYSTEMTIME st;

    GetLocalTime(&st);
    sprintf_s(logfile.name, STR_SIZE, "Log_%04d%02d%02d-%02d%02d%02d_%03d.txt",
            st.wYear, st.wMonth, st.wDay,
            st.wHour, st.wMinute, st.wSecond,
            st.wMilliseconds);

    return logfile;
}

//file InitFileName() {
//    time_t tim = time(NULL);
//    struct tm now_time;
//    errno_t error = localtime_s(&now_time, &tim);
//
//    sprintf_s(logfile.name, STR_SIZE, "Log_%04d%02d%02d-%02d%02d%02d.csv",
//        now_time.tm_year + 1900,
//        now_time.tm_mon + 1,
//        now_time.tm_mday,
//        now_time.tm_hour,
//        now_time.tm_min,
//        now_time.tm_sec);
//
//    return logfile;
//};

void AppendString(file file, const char append_str[]) {
    std::ofstream ofs(file.name, std::ios::app);

    if (!ofs) {
        std::cerr << "Failed to open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    ofs << append_str << std::endl;
    ofs.close();
    return;
};