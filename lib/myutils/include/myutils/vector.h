#ifndef BUFFER_H
#define BUFFER_H

#include <cstdint>
#include <stdlib.h>
#include <stdexcept>
namespace myutils
{
template<typename T>
class Vector
{
    public:
    Vector(): mCapacity(0), mSize(0), mData(nullptr)
    {
        reserve(2);

    }
    Vector(uint32_t capacity) : mCapacity(0), mSize(0), mData(nullptr)
    {
        reserve(capacity);
    }


    Vector(const Vector &other) : mData(nullptr)
    {
        if(mData != nullptr)
            deallocate();
        mData = nullptr;
        mSize = 0;
        mCapacity = 0;

        reserve(other.mCapacity);
        for (int i = 0; i < other.mSize; i++)
        {
            mData[i] = other.mData[i];
        }
        mSize = other.mSize;
        mCapacity = other.mCapacity;
        
    }

    Vector(Vector &&other)
    {
        if(mData)
            deallocate();
        
        mCapacity = other.mCapacity;
        mSize = other.mSize;
        mData = other.mData;

        other.mData = nullptr;
        other.mSize = 0;
        other.mCapacity = 0;

    }
    ~Vector()
    {
        if(mData != nullptr)
            free(mData);
        mData = nullptr;
    }

    Vector& operator=(const Vector& other)
    {
        if(mData)
            deallocate();
        mData = nullptr;
        mSize = 0;
        mCapacity = 0;

        reserve(other.mCapacity);
        for (int i = 0; i < other.mSize; i++)
        {
            mData[i] = other.mData[i];
        }
        mSize = other.mSize;
        mCapacity = other.mCapacity;
        return *this;
    }

    Vector& operator=(Vector&& other)
    {
        if(mData)
            deallocate();
        
        mCapacity = other.mCapacity;
        mSize = other.mSize;
        mData = other.mData;

        other.mData = nullptr;
        other.mSize = 0;
        other.mCapacity = 0;
        return *this;
    }

    void insert(uint32_t index, T c)
    {
        if(index < 0 || index >= mSize)
            throw std::out_of_range("Invalid Vector Index");
        if (mSize + 1 >= mCapacity)
            reserve(mCapacity * 1.5 + 1);
        
        for(int i = mSize; i > index; i--)
        {
            mData[i] = mData[i - 1];
        }
        mData[index] = c;
        mSize++;
    }

    void push_back(T c)
    {
        if (mSize == mCapacity)
            reserve(mCapacity * 1.5 + 1);

        mData[mSize] = c;
        mSize++;
    }
    void pop_back()
    {
        mSize--;
        mData[mSize].~T();
    }
    void erase(uint32_t index)
    {
        if(index < 0 || index >= mSize)
            throw std::out_of_range("Invalid Vector Index");
        for (uint32_t i = index; i < mSize - 1; i++)
        {
            mData[i] = mData[i+1];
        }
        mSize--;

        mData[mSize].~T();
    }
    uint32_t getSize() const { return mSize;}
    uint32_t getCapacity() const {return mCapacity;}


    //buffer manipulation
    void reserve(uint32_t newCapacity){
        if (newCapacity <= mCapacity)
            return;

        T *newData = static_cast<T*>(malloc(newCapacity * sizeof (T)));

        if (mData != nullptr) {
            for (int i = 0; i < mSize; i++)
                newData[i] = mData[i];
            free(mData);
        }
        mData = newData;
        mCapacity = newCapacity;
    }
    void resize(uint32_t  newSize) {
        if (newSize <= mSize)
            return ;
        if (newSize >= mCapacity)
        {
            reserve(newSize * 1.5 + 1);
        }
        while(mSize < newSize)
        {
            mData[mSize] = T();
            mSize++;
        }
    }

    void clear()
    {
        for(uint32_t i = 0; i < mSize; i++)
        {
            mData[i].~T();
        }
        mSize = 0;
    }
    T& operator [](int index) const
    {
        if(index < 0 || index >= mSize)
            throw std::out_of_range("Invalid Vector Index");
        return mData[index];
    }
private:
    void deallocate()
    {
        for(int i = 0; i < mSize; i++)
            mData[i].~T();
        free(mData);
        mData = nullptr;
        mSize = 0;
        mCapacity = 0;
    }
    T *mData;
    uint32_t mCapacity;
    uint32_t mSize;
};

} // namespace myutils
#endif