#include "Header.h"
#include <string.h>
#include <iostream>

int main() {
    char filename[SIZE_64];
    char date_time[SIZE_64];
    char log_line[SIZE_80];

    GetDateForFilename(filename);

    GetDateForLog(date_time);
    sprintf_s(log_line, SIZE_80, "%s %s: Sample\n", LVL_INFO, date_time);
    AppendString(filename, log_line);

    return 0;
}