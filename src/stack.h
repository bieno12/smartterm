#ifndef STACKMINA_H
#define STACKMINA_H

#include <myutils/vector.h>
#include <cstdint>
template<typename Type>
class Stack
{
public:
    typedef Type* iterator;
    typedef const Type* const_iterator;

    Stack() = default;

    void push(Type item)
    {
        mItems.push_back(item);
    }

    Type pop()
    {
        Type item = mItems[mItems.getSize() - 1];
        mItems.pop_back();
        return item;
    }
    inline uint32_t size() { return mItems.getSize();}

    iterator begin() { return &mItems[0]; }
    const_iterator begin() const { return &mItems[0]; }
    iterator end() { return &mItems[0] + size(); }
    const_iterator end() const { return &mItems[0] + size(); }

private:
    myutils::Vector<Type> mItems;
};
#endif