#include "Header.h"
#include <string.h>

int main() {
    char append_str[STR_SIZE];

    file logfile = InitFileName();

    strcpy_s(append_str, STR_SIZE, "OK");
    AppendString(logfile, append_str);

    return 0;
}