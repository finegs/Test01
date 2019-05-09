#if 1

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

int main(int argc, char* argv[]) 
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
