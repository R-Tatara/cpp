#include <fstream>
#include <iostream>
#include <windows.h>
#include "Header.h"

//Function definition
void GetDateForFilename(char *p_string) {
    SYSTEMTIME st;

    GetLocalTime(&st);
    sprintf_s(p_string, SIZE_64, "Log_%04d%02d%02d-%02d%02d%02d.txt",
            st.wYear, st.wMonth, st.wDay,
            st.wHour, st.wMinute, st.wSecond);

    return;
}

void GetDateForLog(char *p_string) {
    SYSTEMTIME st;

    GetLocalTime(&st);
    sprintf_s(p_string, SIZE_64, "%04d/%02d/%02d %02d:%02d:%02d.%03d",
            st.wYear, st.wMonth, st.wDay,
            st.wHour, st.wMinute, st.wSecond,
            st.wMilliseconds);

    return;
}

void AppendString(const char *p_filename, const char append_str[]) {
    std::ofstream ofs(p_filename, std::ios::app);

    if (!ofs) {
        std::cerr << "Failed to open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    ofs << append_str;
    ofs.close();
    return;
};