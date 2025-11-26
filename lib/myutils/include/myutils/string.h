#ifndef STRINGMINA_H
#define STRINGMINA_H

#include "vector.h"
#include <cstdint>
#include <iostream>
namespace myutils
{

class String 
{
private:
    Vector<char> mData;

public:
    String();                              // Default constructor
    String(uint32_t capacity);
    String(const char* str);               // Constructor from C-string
    String(const String& other);           // Copy constructor
    String(String&& other) noexcept;       // Move constructor
    ~String();                             // Destructor

    String& operator=(const String& other); // Copy assignment operator
    String& operator=(String&& other) noexcept; // Move assignment operator

    char& operator[](uint32_t index) const;        // Subscript operator (non-const)
    // const char& operator[](uint32_t index) const; // Subscript operator (const)

    // Get the size of the string
    inline uint32_t getSize() const {
        return mData.getSize() - 1;
    }
    // Check if the string is empty
    inline bool isEmpty() {
        return getSize() == 0;
    }

    inline void clear() { mData.clear();}                          // Clear the string
    void push_back(char c);                // Append a character to the string
    void pop_back();                // Append a character to the string

    inline const char* cStr() {return &mData[0];}             // Get C-string representation

    bool operator==(const String& other) const; // Equality operator
    bool operator!=(const String& other) const; // Inequality operator

    String operator+(const String& other) const;
    String& operator+=(const String& other);

    friend std::ostream & operator<<(std::ostream &stream, String &s);
};
} // namespace myutils

#endif