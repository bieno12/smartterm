#ifndef PYTHON_LISTMINA_H
#define PYTHON_LISTMINA_H
#include "vector.h"
#include "any.h"
#include <cstdint>
#include <iostream>
namespace myutils
{
class PythonList
{
public:
    PythonList() = default;
    
    // Copy Constructor
    PythonList(const PythonList&) = default;
    // Move Constructor
    PythonList(PythonList && other)
    {
        mItems = std::move(other.mItems);
    }
    // Copy Assignemnt Operator
    PythonList& operator=(const PythonList& other) = default;
    // move Assignment operator
    PythonList& operator=( PythonList&& other)
    {
        mItems = std::move(other.mItems);
        return *this;
    }
    
    // Destructor
    ~PythonList() = default;

    // API
    Any& operator[](uint32_t index)
    {
        return mItems[index];
    }

    template<typename Type>
    void append(Type element)
    {
        mItems.push_back(Any(element));
    }

    void extend(PythonList other)
    {
        for(uint32_t i = 0; i < other.size(); i++)
            append(other[i]);
    }

    void clear()
    {
        mItems.clear();
    }

    void reverse()
    {
        uint32_t left = 0, right = size() -1;

        while(left < right)
        {
            Any temp = mItems[right];
            mItems[right] = mItems[left];
            mItems[left] = temp;
            left++;
            right--;
        }
    }

    uint32_t size()
    {
        return mItems.getSize();
    }

    void print()
    {
        std::cout << "[";
        for(uint32_t i = 0; i < size() - 1; i++)
            std::cout << mItems[i] << ", ";
        std::cout << mItems[size() - 1] << "]\n";
    }
private:
    Vector<Any> mItems;
};

} // namespace myutils

#endif