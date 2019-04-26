#if 1

#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstring>

class AA {
    private:
        std::string name;
        std::string desc;
    public:
        AA(const char* _name, const char* _desc) : name(_name), desc(_desc) {}
        const std::string& getName() { return name; }
        const std::string& getDesc() { return desc; }
};

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;

    AA a("a", "aaa");
//    std::cout << a.getName() << a.getDesc() << std::endl;
}

int main(int argc, char* argv[]) {

    int n;
    int* arr;

    if(argc>1) {
        n = argc;
        arr = new int[n];
        memset(arr, 0, sizeof(int)*n);
        for(int i = 0;i < n;i++) *(arr+i) = std::atoi(argv[i]);
    }
    else {
        n = 10;
        arr = new int[n];
        
        int i=0;
        for(int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) *(arr+i++) = n;
    }

    std::priority_queue<int> q;

    for(int i = 0;i < n;i++) q.push(arr[i]);

    print_queue(q);

    std::priority_queue<int, std::vector<int>, std::greater<int>> q2;

    for(int i = 0;i < n;i++) q2.push(arr[i]);

    print_queue(q2);

    auto cmp = [](int left, int right) { return (left^1) < (right^1);};

    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    for(int i = 0;i < n;i++) q3.push(arr[i]);

    print_queue(q3);


    std::cout << "3^1=" << (3^1) << std::endl;

    return EXIT_SUCCESS;

}


#endif


#if 0
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

template<typename T> T& Array<T>::operator[](size_t x)
{
//    if(x>=mSize) throw std::out_of_range("Array<T>::[]");
    while(x>=mSize)
    {
        resize(mSize*2+x);
    }
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
    {
        //ma.set(i, i*100);
        ma[i] = i+100;
    }

    for(size_t i=0;i<10;i++)
        std::cout << ma[i] << ", ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

#endif

