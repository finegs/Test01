#ifndef _TEST01_H_
#define _TEST01_H_

#include <string>

template<typename T>
class Array
{
    public:
        Array();
        virtual ~Array();

        Array<T>& operator=(const Array<T>& rhs) = delete;
        Array(const Array<T>& src) = delete;

        T at(size_t x) const;
        T& operator[](size_t x);

        void set(size_t x, const T& val);

    private:
       static const size_t kAllocSize = 4;
       void resize(size_t newSize);
       void initializeElements();
       T* mElems;
       size_t mSize;
        
};

class AA {
    private:
        std::string name;
        std::string desc;
    public:
		AA() : name(""), desc("") {}
        AA(const char* _name, const char* _desc) : name(_name), desc(_desc) {}
        AA(const AA& o) : name(o.name), desc(o.name) {}
        AA(AA&& o)  : name(std::move(o.name)), desc(std::move(o.desc)) {}
        AA& operator=(const AA& o) 
        {
			if(this==&o) return *this;
            name = o.name;
            desc = o.desc;
            return *this;
        }
        AA& operator=(AA&& o) 
        {
			if(this==&o) return *this;
            name = std::move(o.name);
            desc = std::move(o.desc);
            return *this;
        }

        const std::string& getName() { return name; }
        const std::string& getDesc() { return desc; }
};

#endif
