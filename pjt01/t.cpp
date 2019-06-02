#if 1

#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <utility>

#include <u.hpp>

#define MY_DEBUG 1

#define VERSION "v1.0.0_20190602_b02"

class MyClz {
    private:
        std::string id;
        std::string value;
        std::string desc;

    public:
        MyClz() : id(""), value(""), desc("") {}
        MyClz(const std::string& _id, const std::string& _value) : id(_id), value(_value) {}
        MyClz(const MyClz& o) : id(o.id), value(o.value), desc(o.desc) {}
        MyClz(MyClz&& o) : id(std::move(o.id)), value(std::move(o.value)), desc(std::move(o.desc)) {}
        MyClz& operator=(const MyClz& o) {
            if(this==&o) return *this;
            id = o.id;
            value = o.value;
            desc = o.desc;
            return *this;
        }
        MyClz& operator=(MyClz&& o) {
            if(this==&o) return *this;
            id = std::move(o.id);
            value = std::move(o.value);
            desc = std::move(o.desc);
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const MyClz& o) {
            os << "{\"" << o.id << "\", \"" << o.value << "\", \"" << o.desc << "\"}" << std::endl;
            return os;
        }
//        MyClz(std::string&& _id, std::string&& _value) 
//                : id(std::forward<std::string>(_id)), value(std::forward<std::string>(_value)) {} ;
        ~MyClz() = default;

    public:
        struct MyClzComparator {
            bool operator() (const MyClz& a, const MyClz& b) const {
                return a.id < b.id;
            }
        };
};

std::unordered_map<std::string, MyClz> m1;

bool IS_DEBUG = false;

//#ifdef MY_DEBUG
//bool IS_DEBUG = true;
//#endif

// 0. Initialize Program Parameters
void initArgs(int argc, char* argv[]) {
    for(int i = 1;i < argc;i++) {
        if(!strcmp("-d", argv[i])) {
            IS_DEBUG = true;
        }
    }
}


int main(int argc, char* argv[]) {

    std::string line;
    std::stringstream ss;
    std::string key, value;
    bool bExit = false;

    // 0. Initialize Program Parameters
    initArgs(argc, argv); 

    do {
        line = "";
        std::getline(std::cin, line);

        if (("-quit" == line || "-QUIT" == line || "-exit" == line || "-EXIT" == line)) {
	            std::cout << "Are you sure to quit? (Y/N)" << std::endl;
	
	            std::getline(std::cin, line);
	
	        if("Y"==line||"y"==line) {
	            bExit = true;
	            break;
	        }
	        line.clear();
	        continue;
        }
	     else if("-p" == line || "-P" == line) {
	         for(auto iter = m1.cbegin();iter != m1.cend();iter++) {
	             std::cout << iter->second << std::endl;
	         }
	         line.clear();
	        continue;
	     }
	
	     ss.str(line);
	     ss >> key >> value;
	
	    if (IS_DEBUG)
	        std::cout << "Size = " << m1.size() << ", Key = " << key << ", Value = " << value << std::endl;
	
	     MyClz c(key, value);
	
	     m1[key] = c;
	
	     line.clear();

    } while(!bExit);

    system("pause");

    return EXIT_SUCCESS;
}


#endif



#if 0

#include <iostream>
#include <vector>
#include <initializer_list>
 
template <class T>
struct S {
    std::vector<T> v;
    S(std::initializer_list<T> l) : v(l) {
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(std::initializer_list<T> l) {
        v.insert(v.end(), l.begin(), l.end());
    }

    void append_begin(std::initializer_list<T> l) {
        v.insert(v.begin(), l.begin(), l.end());
    }

    void append_end(std::initializer_list<T> l) {
        append(l);
    }

    std::pair<const T*, std::size_t> c_arr() const {
        return {&v[0], v.size()};  // copy list-initialization in return statement
                                   // this is NOT a use of std::initializer_list
    }
};
 
template <typename T>
void templated_fn(T) {}
 
int main()
{
    S<int> s = {1, 2, 3, 4, 5}; // copy list-initialization
    s.append_begin({6, 7, 8});      // list-initialization in function call
 
    std::cout << "The vector size is now " << s.c_arr().second << " ints:\n";
 
    for (auto n : s.v)
        std::cout << n << ' ';
    std::cout << '\n';
 
    std::cout << "Range-for over brace-init-list: \n";
 
    for (int x : {-1, -2, -3}) // the rule for auto makes this ranged-for work
        std::cout << x << ' ';
    std::cout << '\n';
 
    auto al = {10, 11, 12};   // special rule for auto
 
    std::cout << "The list bound to auto has size() = " << al.size() << '\n';
 
//    templated_fn({1, 2, 3}); // compiler error! "{1, 2, 3}" is not an expression,
                             // it has no type, and so T cannot be deduced
    templated_fn<std::initializer_list<int>>({1, 2, 3}); // OK
    templated_fn<std::vector<int>>({1, 2, 3});           // also OK
}
#endif

#if 0

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <vector>
#include <memory>

#include <iostream>
#include <tuple>

#include <u.hpp>

// aa bb vc

//#pragma clang diagnostic ignored "-Wunused"


int main(int argc, char* argv[]) 
//int main(int /*argc*/, char* /*argv[]*/) 
{
    std::tuple<int, char> foo(10, 'x');
    auto bar = std::make_tuple("test", 3.1, 14, 'y');

    std::get<2>(bar) = 100;

    int myint; char mychar;

    std::tie(myint, mychar) = foo;
    std::tie(std::ignore, std::ignore, myint, mychar) = bar;

    mychar = std::get<3>(bar);

    std::get<0>(foo) = std::get<2>(bar);
    std::get<1>(foo) = mychar;


    std::cout << "foo contains : ";
    std::cout << std::get<0>(foo) << ' ';
    std::cout << std::get<1>(foo) << '\n';


    return EXIT_SUCCESS;
}

#endif

#if 0
struct data {
	int nr;
	char const* value;

	int get() && { return nr; } // call to this overload is rvalue
	int& get() & { return nr; } // call to this overload is lvalue
} dat[] = { {1, "Foo"}
	,{2, "Bar"}
	,{3, "Hello"}
	,{4, "World"}
	};

int comp_dat(void const* a, void const* b)
{
	struct data const* l = (struct data const*)a;
	struct data const* r = (struct data const*)b;
	if(l->nr < r->nr) return -1;
	else if(l->nr > r->nr) return 1;
	else return 0;
}

void test01() { std::string str = "Hello";
	std::vector<std::string> v;

	v.push_back(str);
	std::cout << "After copy, str is \"" << str << "\"\n";

	v.push_back(std::move(str));
	std::cout << "After move, str is \"" << str << "\"\n";
	std::cout << "The contents of the vector are \"" << v[0]
									<< "\", \"" << v[1] << "\"\n";
}

struct A {
	int n;
    A(int&& _n) { std::cout << "rvalue overload, n=" << (n = _n) << "\n"; }
    A(int& _n)  { std::cout << "lvalue overload, n=" << (n = _n) << "\n"; }
	A& operator=(A& o) { std::cout << "lvalue allocator overload, n=" << (n=o.n) << "\n"; return *this; }
	A& operator=(A&& o) { std::cout << "rvalue allocator overload, n=" << (n=o.n) << "\n"; return *this; }
};
 
class B {
public:
    template<class T1, class T2, class T3>
    B(T1&& t1, T2&& t2, T3&& t3) :
        a1_{std::forward<T1>(t1)},
        a2_{std::forward<T2>(t2)},
        a3_{std::forward<T3>(t3)}
    {
    }
 
private:
    A a1_, a2_, a3_;
};
 
template<class T, class U>
std::unique_ptr<T> make_unique1(U&& u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)));
}
 
template<class T, class... U>
std::unique_ptr<T> make_unique2(U&&... u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}
 
void test02()
{   
    auto p1 = make_unique1<A>(2); // rvalue
    int i = 1;
    auto p2 = make_unique1<A>(i); // lvalue
 
    std::cout << "B\n";
    auto t = make_unique2<B>(2, i, 3);
}

int main(int argc, char* argv[])
{
	struct data key = { .nr = 3 };
	struct data const* res = (struct data const*)bsearch(&key, dat, sizeof(dat)/sizeof(dat[0]), sizeof(dat[0]), comp_dat);

	if(res) {
		printf("No %d : %s\n", res->nr, res->value);
	}
	else {
		printf("No %d : not found\n", key.nr);
	}

	test01();
	test02();

	return EXIT_SUCCESS;
}

#endif

#if 0
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
void rm_v(std::vector<T>& v, const T& t)
{
  //  for(auto i:v) {
    for(auto i = v.begin();i!=v.end();) {
        if(*i == t)
            i = v.erase(i);
        else
            ++i;
    }
}

using namespace std;
int main(int argc, char* argv[])
{
    vector<int> v{3,1,4,1,5,9};
    for(auto i:v) cout << i << " ";
    cout << endl;

    make_heap(v.begin(), v.end());

    cout << "v: ";
    for(auto i:v) cout << i << ' ';
    cout << '\n';

    v.push_back(6);

    cout << "before push_heap: ";
    for(auto i:v) cout << i << ' ';
    cout << endl;

    push_heap(v.begin(), v.end());

    cout<< "after push_heap: ";
    for(auto i:v) cout << i << ' ';
    cout << endl;

    cout << "before remove(9), push_heap: ";
    for(auto i:v) cout << i << " ";
    cout << endl;

//    pop_heap(v);
    rm_v<int>(v, 9);
//    rm_v<int>(v, 5);

    make_heap(v.begin(), v.end());

    cout << "after remove(9), push_heap: ";
    for(auto i:v) cout << i << " ";
    cout << endl;

	return EXIT_SUCCESS;

}
#endif
