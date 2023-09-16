#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

const constexpr int size_type_def = 10;
// Клас Аллокатора
template <class T, size_t MaxCount = size_type_def>
struct CustomAllocator {
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;

    CustomAllocator() = default;
    CustomAllocator(const CustomAllocator&) = default;
    template <typename U, size_t S>
    CustomAllocator(const CustomAllocator<U>&) {}
    ~CustomAllocator() {}

    pointer allocate (std::size_t n);
    
    void deallocate (pointer p, std::size_t n)
    {
        ::operator delete(p);
    }
    
    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        ::new ((void*)p) U(std::forward<Args>(args)...);
    }

    template<typename U>
    void destroy(U* p) {
        p->~U();
    }

    template< typename U >
    struct rebind
    {
        typedef CustomAllocator<U> other;
    };

    private : 
        int currentCountReserved = 0 ;
};

template <typename T, size_t MaxCount>
typename CustomAllocator<T, MaxCount>::pointer CustomAllocator<T, MaxCount>::allocate(size_t n)
{
    try {
        if (MaxCount >= currentCountReserved + n )
        {
            currentCountReserved += n;
            return static_cast<T*>(::operator new(n*sizeof(T)));
        }
        throw;
        }
    catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return nullptr;
        }
}