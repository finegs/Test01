#include <iostream>
#include <test01.hpp>

template<typename T> Array<T>::Array() : mSize(kAllocSize)
{
    std::cout << "## 1## " << std::endl;
    mElems = new T[mSize];
    initializeElements();
}

template<typename T> Array<T>::~Array()
{
    delete[] mElems;
    mElems = nullptr;
}

template<typename T> void Array<T>::initializeElements()
{
        for (size_t i = 0;i < mSize;i++)
            mElems[i] = T();
}

template<typename T> void Array<T>::resize(size_t newSize)
{
    T* oldElems = mElems;
    size_t oldSize = mSize;
    mSize = newSize;
    mElems = new T[newSize];
    initializeElements();

    for(size_t i = 0;i < oldSize;i++)
    {
        mElems[i] = oldElems[i];
    }
    delete[] oldElems;
    oldElems = nullptr;
}

template<typename T> T Array<T>::at(size_t x) const
{
    if(x>=mSize) throw std::out_of_range("Array<T>::at()");
    return mElems[x];
}

template<typename T> void Array<T>::set(size_t x, const T& val)
{
     while(x>=mSize) {
     //    throw std::out_of_range("Array<T>::set()");
        resize(mSize*2+x); 
     }
     mElems[x] = val;
}


int main(int argc,char* argv[])
{
    Array<int> ma;

    for(size_t i=0;i<10;i++)
        ma.set(i, i*100);

    for(size_t i=0;i<10;i++)
        std::cout << ma.at(i) << ", ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
