#pragma once
#include <cstdint>

namespace myutils
{

uint32_t strLen(const char *str);

int32_t strCompare(const char *s1, const char *s2);

void strToLower(char *str);
void strToUpper(char *str);

void strConcat(uint32_t sizeStr1, char *str1, const char *str2);

void strCopy(char *dest, const char *src);
} // myutils
