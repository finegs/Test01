#ifndef _TEST01_H_
#define _TEST01_H_

template<typename T>
class Array
{
    public:
        Array();
        virtual ~Array();

        Array<T>& operator=(const Array<T>& rhs) = delete;
        Array(const Array<T>& src) = delete;

        T at(size_t x) const;

        void set(size_t x, const T& val);

    private:
       static const size_t kAllocSize = 4;
       void resize(size_t newSize);
       void initializeElements();
       T* mElems;
       size_t mSize;
        
};

#endif
