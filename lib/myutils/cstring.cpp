#include "myutils/cstring.h"

uint32_t myutils::strLen(const char *str)
{
    uint32_t i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}


/// @brief compares two strings by the first different value, then by length
/// @param s1 
/// @param s2 
/// @return returns +ve if s1 > s2, 0 if s1 == s2, -ve s1 < s2
int32_t myutils::strCompare(const char *s1,const char *s2)
{
    while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
        s1++; s2++;
    };

    if (*s1 == '\0' && *s2 == '\0')
        return 0;
    if(*s1 == '\0')
        return -1;

    if(*s2 == '\0')
        return 1;
    
    return (*s1 - *s2);
}

void myutils::strToLower(char *str)
{
    while(*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
            *str += 'a' - 'A';
        str++;
    }
}

void myutils::strToUpper(char *str)
{
    while(*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
            *str += 'A' - 'a';
        str++;
    }
}
void myutils::strConcat(uint32_t sizeStr1, char *str1, const char *str2)
{

    while(*str1 != '\0')
    {
        str1++;
        sizeStr1--;
    }
    while(*str2 != '\0')
    {
        if(sizeStr1 == 0)
            return ;
        *str1 = *str2;
        str1++, str2++;
        sizeStr1--; 
    }
    *str1 = '\0';
}

void myutils::strCopy(char *dest, const char *src)
{
    while(*src != '\0')
    {
        *dest = *src;
        dest++, src++;
    }
    *dest = '\0';
}
