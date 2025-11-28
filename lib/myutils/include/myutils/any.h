#ifndef ANYMINA_H
#define ANYMINA_H

#include <type_traits>
#include <exception>
#include <sstream>
namespace myutils   
{
// Trait to check if operator<< is valid for Type
template <typename T, typename = void>
struct has_ostream_operator : std::false_type {};

template <typename T>
struct has_ostream_operator<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>>
    : std::true_type {};

class Any
{
private:
    // A Manager is created for each type used by Any, it stores type info and handlers.
    template<typename Type>
    struct AnyManager
    {
        static void destroy(void **ptrToMDataPtr)
        {
            // cast the void pointer to Type to destroy it
            Type *ptr_as_type = static_cast<Type*>(*ptrToMDataPtr);
            ptr_as_type->~Type();
            operator delete(ptr_as_type);
            //set mDataPtr = null
            *ptrToMDataPtr = nullptr;
        }
        static void copy(void **dest, void * const *src)
        {
            //dest is a ptr to mDataPtr of other
            //src is a ptr to mDataPtr of this
            Type *src_as_type = static_cast<Type*>(*src);

            //allocate new memory in other.mDataPtr
            *dest = operator new (sizeof(Type));

            // call the copy constructor using placement new
            Type *dest_as_type = new (*dest) Type(*src_as_type); 
        }
        static void move(void **dest, void **src)
        {
            //dest is a ptr to mDataPtr of other
            //src is a ptr to mDataPtr of this
            Type *src_as_type = static_cast<Type*>(*src);

            //allocate new memory in other.mDataPtr
            *dest = operator new (sizeof(Type));

            // call the move constructor using placement new
            Type *dest_as_type = new (*dest) Type(std::move(*src_as_type)); 
        }

        static std::string toString(void *ptr)
        {
            if constexpr (has_ostream_operator<Type>::value)
            {
                Type *ptr_as_type = static_cast<Type*>(ptr);
                std::stringstream ss;
                ss << *ptr_as_type;
                return ss.str();
            }
            else
            {
                return "Object";
            }
        }
        static const std::type_info &type() { return typeid(Type);}
    };
    struct Manager
    {
        void (*destroy)(void **);
        void (*copy)(void **, void * const*);
        void (*move)(void **, void **);
        const std::type_info & (*type)();

        std::string (*toString)(void *);
    };

    template<typename Type>
    constexpr static Manager manager_for_type = {
        &AnyManager<Type>::destroy,
        &AnyManager<Type>::copy,
        &AnyManager<Type>::move,
        &AnyManager<Type>::type,

        &AnyManager<Type>::toString,
    };

public:
    Any() : mHasValue(false), mDataPtr(nullptr) {
        reset();
    }
    template<typename Type, 
            typename U = std::decay_t<Type>,
            typename = std::enable_if_t<!std::is_same_v<U,Any>, Type>>
    Any(Type &&data)
    {
        mHasValue = true;
        //allocate the memory without construction
        mDataPtr = operator new (sizeof(Type));
        //construct the object by placement new
        U *ptr = new (mDataPtr) U(data);

        mManager = &manager_for_type<U>;
    }
    // Copy Constructor
    Any(const Any& other)
    {
        if(other.mHasValue)
        {
            mHasValue = true;
            mManager = other.mManager;
            mManager->copy(&mDataPtr, &other.mDataPtr); //mDataPtr is populated with new data ptr

        }
        else
        {
            mHasValue = false;
            mDataPtr = nullptr;
            mManager = nullptr;
        }


    }
    // Move Constructor
    Any(Any&& other)
    {
        if(other.mHasValue)
        {
            mHasValue = true;
            mManager = other.mManager;
            mDataPtr = other.mDataPtr;
            
            other.mHasValue = false;
            other.mManager = nullptr;
            other.mDataPtr = nullptr;
        }
        else
        {
            mHasValue = false;
            mDataPtr = nullptr;
            mManager = nullptr;
        }

    }
    // copy assignment;
    Any& operator=(const Any& other)
    {
        *this = Any(other);
        return *this;
        
    }
    // Move asssignemnt
    Any& operator=(Any &&other)
    {
        if(this->hasValue())
        {
            mManager->destroy(&mDataPtr);
        }
        mHasValue = false;
        mManager = nullptr;

        if(other.mHasValue)
        {
            mHasValue = true;
            mManager = other.mManager;
            mDataPtr = other.mDataPtr;
            
            other.mHasValue = false;
            other.mManager = nullptr;
            other.mDataPtr = nullptr;
        }
        else
        {
            mHasValue = false;
            mDataPtr = nullptr;
            mManager = nullptr;
        }
        return *this;
    }


    template<typename Type, 
        typename U = std::decay_t<Type>,
        typename = std::enable_if_t<!std::is_same_v<U,Any>, Type>>
    Any& operator=(Type && value)
    {
        *this = Any(value);
        return *this;
    }

    // Destructor
    ~Any()
    {
        if(this->hasValue())
            mManager->destroy(&mDataPtr);
        mHasValue = false;        
        mManager = nullptr;        
    }

    void reset()
    {
        if(mHasValue)
        {
            mHasValue = false;
            //destroy the stored object
            mManager->destroy(&mDataPtr);

        }
        mDataPtr = nullptr;
        mManager = nullptr;
    }


    bool hasValue()
    {
        return mHasValue;
    }

    template<typename Type, typename U = std::decay_t<Type>>
    U& get()
    {
        if(typeid(U) != mManager->type())
            throw std::bad_cast();
        return *static_cast<U*>(mDataPtr);
    }
    const std::type_info& type()
    {
        if(mManager == nullptr)
            return typeid(void);
        else
            return mManager->type();
    }


    friend std::ostream& operator<<(std::ostream &stream, Any& obj)
    {
        stream << obj.mManager->toString(obj.mDataPtr);
        return stream;
    }
private:
    void *mDataPtr;
    bool mHasValue;
    const Manager *mManager;
};
} // namespace myutils  

#endif