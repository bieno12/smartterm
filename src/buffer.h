#ifndef BUFFER_H
#define BUFFER_H

#include <cstdint>


template<typename T>
class Buffer
{

    public:
    Buffer(): mCapacity(0), mSize(0), mData(nullptr)
    {
        reserve(2);

    }
    Buffer(uint32_t capacity) : mCapacity(0), mSize(0), mData(nullptr)
    {
        reserve(capacity);
    }


    Buffer(const Buffer &other) : mData(nullptr)
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

    Buffer(Buffer &&other)
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
    ~Buffer()
    {
        if(mData != nullptr)
            free(mData);
        mData = nullptr;
    }

    Buffer& operator=(const Buffer& other)
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

    Buffer& operator=(Buffer&& other)
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

        for (uint32_t i = index; i < mSize - 1; i++)
        {
            mData[i] = mData[i+1];
        }
        mSize--;

        mData[mSize].~T();
    }
    uint32_t getSize() { return mSize;}
    uint32_t getCapacity() {return mCapacity;}


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

    T& operator [](int x)
    {
        return mData[x];
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
#endif