#include "include/myutils/string.h"
#include "include/myutils/cstring.h"
#include <utility>
#include "string.h"

myutils::String::String() : mData() {
    mData.push_back('\0');
}

myutils::String::String(uint32_t capacity) : mData(capacity + 1)
{
    mData.push_back('\0');
}

myutils::String::String(const char *str) : mData(strLen(str) + 1)
{
    uint32_t len = strLen(str);

    const char *current = str;
    while(*current != '\0')
    {
        mData.push_back(*current);
        current++;
    }
    mData.push_back('\0');
}

myutils::String::String(const myutils::String &other)
{
    mData = other.mData;
}

myutils::String::String(String &&other) noexcept
{
    mData = std::move(other.mData);
}

myutils::String::~String() {}

myutils::String &myutils::String::operator=(const String &other)
{
    mData = other.mData;
    return *this;
}

myutils::String &myutils::String::operator=(String &&other) noexcept
{
    mData = std::move(other.mData);
    return *this;
}

char &myutils::String::operator[](uint32_t index) const
{
    return mData[index];
}

void myutils::String::push_back(char c)
{
    //pop the null char
    mData.pop_back();
    //add the c
    mData.push_back(c);
    //readd the null
    mData.push_back('\0');
}

void myutils::String::pop_back()
{
    //pop the null char
    mData.pop_back();
    //pop last char
    mData.pop_back();
    //readd the null
    mData.push_back('\0');
}

bool myutils::String::operator==(const String &other) const
{
    if(getSize() != other.getSize())
        return false;

    for(uint32_t i = 0; i < getSize(); i++)
        if((*this)[i]  != other[i])
            return false;
    return true;
}

bool myutils::String::operator!=(const String &other) const
{
    return !(*this == other);
}

myutils::String myutils::String::operator+(const String &other) const
{
    String result(other.getSize() + getSize() + 1);
    
    //pop the last null char
    result.mData.pop_back();

    //fill in
    for(uint32_t i = 0; i < getSize(); i++)
    {
        result.mData.push_back((*this)[i]);
    }
    for(uint32_t i = 0; i < other.getSize(); i++)
    {
        result.mData.push_back(other[i]);
    }

    //readd the null
    result.mData.push_back('\0');

    return result;
}

myutils::String &myutils::String::operator+=(const String &other)
{
    //pop the last null char
    this->mData.pop_back();

    //add the others
    for (uint32_t i = 0; i < other.getSize(); i++)
        this->mData.push_back(other[i]);
    
    //readd the last null characters
    this->mData.push_back('\0');
    return *this;
}

namespace myutils
{
std::ostream &operator<<(std::ostream &stream, String &s)
{
    stream << s.cStr();
    return stream;
}

} // namespace myutils


