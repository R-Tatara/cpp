#pragma once

extern constexpr int STR_SIZE = 64;

typedef struct {
    char name[STR_SIZE];
}file;

//Prototype declaration
file InitFileName();
void AppendString(file file, const char append_str[]);