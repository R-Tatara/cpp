#pragma once

extern constexpr int SIZE_64 = 64;
extern constexpr int SIZE_80 = 80;
extern constexpr char LVL_INFO[] = "[ INFO]";
extern constexpr char LVL_WARN[] = "[ WARN]";
extern constexpr char LVL_ERROR[] = "[ERROR]";
extern constexpr char LVL_FATAL[] = "[FATAL]";

//Prototype declaration
void GetDateForFilename(char *p_string);
void GetDateForLog(char *p_string);
void AppendString(const char *p_filename, const char append_str[]);