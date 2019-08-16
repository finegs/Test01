#if 1

#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <thread>
#include <cstring>

#include "aa.hpp"
#include "u.hpp"
#include "uu1.hpp"
#include "mipc.hpp"

#define MY_DEBUG 1

#define VERSION "v1.0.0_20190602_b02"

extern void cls();

extern bool IS_UU1_EXIT;
extern bool T_IS_DEBUG;

std::unordered_map<std::string, MyClz> m1;
bool bExit = false;

//#ifdef MY_DEBUG
//bool T_IS_DEBUG = true;
//#endif

// 0. Initialize Program Parameters
int initArgs(int argc, char *argv[], std::vector<std::string> &params) {
	int rc = EXIT_SUCCESS;
	for (int i = 1; i < argc; i++) {
		if (!strcmp("-d", argv[i]) || !strcmp("-D", argv[i])) {
			T_IS_DEBUG = true;
		}
		else if (!strcmp("-v", argv[i]) || !strcmp("--version", argv[i])) {
			rc = EXIT_OTHERS;
			std::cout << argv[0] << " Version : " << VERSION << std::endl;
		}
		else {
			// added by SGK 20190620  :
			params.emplace_back(argv[i]);
		}
	}
	return rc;
}

void handleUserInput(int argc, char* argv[]) {
	do {
		std::string line;
		std::stringstream ss;
		std::string cmd;
		std::string key, value, desc;
		std::vector<std::string> params;

		line = cmd = key = value = desc = "";
		ss.clear();
		params.clear();

		std::cout << "cmd << ";
		std::cout.flush();
		std::getline(std::cin, line);

		ss.str(line);
		while (true) {
			cmd = "";
			ss >> cmd;
			if (cmd.size() < 1)
				break;
			params.push_back(cmd);
		}

		cmd = params.at(0);

		cls();

		if ("-q" == cmd || "-Q" == cmd || "-quit" == cmd || "-QUIT" == cmd || "-exit" == cmd || "-EXIT" == cmd) {
			if (params.size() > 1 && "-i" == params[1]) {
				std::cout << "\t>> [I] Exit.." << std::endl;
				bExit = true;
				continue;
			}
			std::cout << "\t>> [I] Are you sure to quit? (Y/N)" << std::endl;

			std::getline(std::cin, cmd);

			if ("Y" == cmd || "y" == cmd) {
				bExit = true;
				break;
			}
		}
		else if ("-p" == cmd || "-P" == cmd || "-print" == cmd || "-PRINT" == cmd) {
			if (m1.empty()) {
				std::cout << "\t>> [E] m1 is emtpy" << std::endl;
				continue;
			}
			int i = 0;
			for (auto iter = m1.cbegin(); iter != m1.cend(); iter++, i++) {
				std::cout << "\t\t[" << i << "] = " << iter->second << std::endl;
			}
		}
		else if ("-c" == cmd || "-C" == cmd || "-clear" == cmd || "-CLEAR" == cmd) {
			cls();
		}
		else if ("-I" == cmd || "-i" == cmd) {
			if (params.size() > 0)
				key = params[1];
			if (params.size() > 1)
				value = params[2];
			if (params.size() > 2)
				desc = params[3];

			MyClz c(key, value);
			c.setDesc(desc);

			if (T_IS_DEBUG)
				std::cout << "\t>> [D] m1.size= " << m1.size() << ", Data= " << c << std::endl;

			m1[key] = c;
		}
		else if ("-d" == cmd || "-D" == cmd) { 
			if (params.size() > 1)
				key = params[1];

			if (key.length() < 1) {
				std::cout << "\t>> [E] key is empty" << std::endl;
				continue;
			}

			int cnt = 0;
			if (T_IS_DEBUG) {
				std::cout << "\t>> [I] Found Count : " << m1.count(key) << std::endl;
				for (auto iter = m1.find(key); iter != m1.end(); iter++)
				{
					std::cout << "\t\t(" << cnt++ << "),  m1[" << iter->first << "] = " << iter->second << std::endl;
				}
			}
			m1.erase(key);

			if (T_IS_DEBUG) {
				std::cout << "\t>> [D] Deleted count = " << cnt << ", m1.size = " << m1.size() << std::endl;
			}
		}
		else if ("-h" == cmd || "-H" == cmd || "-help" == cmd || "-HELP" == cmd) {
			MyClz::printCRUDUsage();
		}
		else if ("-t00" == cmd || "-T00" == cmd) {

			MyIPC::testIPC(argc, argv);
		}
		else if ("-t01" == cmd || "-t01" == cmd) {
			MyUU1 u;

			std::cout << u << std::endl;
		}
		else if ("-t02" == cmd || "-T02" == cmd) {
			MyClz m;

			if (params.size() > 1)
				m.testFibo(atoi(params[1].c_str()));
			else
				m.testFibo();
		}
		else if ("-t03" == cmd || "-T03" == cmd) {
			if (params.size() < 3)
				continue;
			int base = MyUU1::matoi(params[1].c_str());
			int exp = MyUU1::matoi(params[2].c_str());

			std::cout << "MyUU1::mypow(" << base << ", " << exp << ") = " << MyUU1::mypow(base, exp) << std::endl;
		}
		else if ("-t04" == cmd || "-T04" == cmd) {
			MyUU1::test04();
		}
		else if ("-t05" == cmd || "-T05" == cmd) {
			MyIPC::testIPCMapFile(argc, argv, params);
		}
		else if ("-tc" == cmd || "-TC" == cmd) {
			if (params.size() < 2)
				continue;
			MyUU1::testCode(params[1], argc, argv, params);
		}
		else {
			std::cout << "\t>> [E] Unsupported command : " << key << std::endl;
			MyClz::printCRUDUsage();
		}

	} while (!bExit);

}

int main(int argc, char *argv[]) {

	int rc;
	std::string line;
	std::stringstream ss;
	std::string cmd;
	std::string key, value, desc;
	std::vector<std::string> params;

	rc = EXIT_SUCCESS;

	// 0. Initialize Program Parameters
	if (EXIT_SUCCESS != (rc = initArgs(argc, argv, params))) {
		return rc;
	}

	// 1. Initialize TestEnumCodeMap
	MyUU1::MyUU1::initTestEnumMap();

	if (std::end(params) != std::find_if(std::begin(params), std::end(params), [&](std::string &s) {
			if ("-t05" == s || "-T05" == s)
				return true;
			else
				return false;
		})) {
	
		MyIPC::testIPCMapFile(argc, argv, params);
		return EXIT_SUCCESS;
	}

	std::thread cinReader = std::thread(handleUserInput, argc, argv);

//#ifdef _WIN32
//	system("pause");
//#endif

	cinReader.join();

	getchar();

	return EXIT_SUCCESS;
}

#endif

#if 0
#include <iostream>
#include <string>
#include <cstdio>

void f1();
void f2();

int main() {
    f2();
}

void f2() {
    std::ios::syn_with_stdio(false);
    std::cout << "a\n";
    std::printf("b\n");
    std::cout<<"c\n";
}

void f1() {
    double n;
    while(std::cout << "Please, enter a number\n"
            && !(std::cin>>n)) {
        std::cin.clear();
        std::string line;
        std::getline(std::cin, line);
        std::cout << "I am sorry, but '" << line << "' is not a number\n";
    }

    std::cout << "Thank you for enterring the number " << n <<  '\n';
}

#endif

#if 0

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include <math.h>
#include <vector>
#include <set>

#if 1

int frequency_of_prime(int n, std::set<int>& s) {
	int i;
	int freq = n-1;
	for(i=2;i<=n;++i)
		if(isPrime(i))
			s.emplace(i);

//		for(j=sqrt(i);j>1;--j)
//			if(i%j==0) { 
//				--freq; break; 
//			}
//			else {
//				if(s.count(i) < 1)
//					s.emplace(i);
//			}

	return freq;
}
#endif


int main() {
#if 0	
	char str[] = "This is a sample string.";

	char* pch;
	printf("Looking for the 's' character in \"%s\" ....\n", str);

	pch = strchr(str, 's');

	while(pch) {
		printf("found at %lld\n", pch-str+1);
		pch=strchr(pch+1, 's');
	}


	char* pch;
	char str[] = "Example string";
	pch = (char*)memchr(str, 'p', strlen(str));
	if(pch)
		printf("'p' found at position %lld.\n", pch-str+1);
	else
		printf("'p' not found .\n");

#endif

	clock_t t;
	int f;
	std::set<int> s;

	t = clock();
	printf("Calculating...\n");
	f = frequency_of_prime(999999, s);
	printf("The number of primes than 100,000 is : %d\n", f);
	t = clock() - t;

	printf("Prime Numbres\n");
	int i = 0, m = 10;
	for(auto iter = s.cbegin();iter != s.cend() && m > 0;++iter, i++, --m) {
		printf("[%d] = %d\n", i, *iter);
	}

	printf("It took me %ld clicks (%f seconds). \n", t, ((float)t)/CLOCKS_PER_SEC);

	return EXIT_SUCCESS;
}
#endif

#if 0

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class MyData {
		private:
				int a;
				std::string b;
		public:
				MyData() : a(-1), b("") {}
				MyData(int _a, const char* _b) : a(_a), b(_b) {}
				MyData(int _a, const std::string& _b) : a(_a), b(_b) {} 

				MyData(const MyData& o) : a(o.a), b(o.b) {}
				MyData(MyData&& o) : a(o.a), b(std::move(o.b)) { std::cout << "## MyData(MyData&&)} " << std::endl; }

				MyData& operator=(const MyData& o) {
						if(this==&o) return *this;
						a = o.a;
						b = o.b;
						return *this;
				}
				MyData& operator=(MyData&& o) {
						if(this==&o) return *this;
						a = o.a;
						b = std::move(o.b);
						return *this;
				}

				friend std::ostream& operator<<(std::ostream& os, const MyData& o)  {
						os << "{ this = " << &o << ", a = " << o.a << ", b = " << o.b << "}";
						return os;
				}

				const std::string& getB() {  return b; }

				template<typename T>
				static void checkB(T&& _b) {
					std::cout << "&b  = " << &_b 
								<< ", b = " << _b << std::endl;
				}

				template<typename T>
				static void checkMyData(T&& d) {
					std::cout << " &d =" << &d 
								<< ", d = " << d  << std::endl;
				}

};


int main() {
		MyData a(-100, " This is b  !!!!! ######## ");

		std::cout << "1-1, " << a << std::endl;
		std::cout << "1-2, " << a << std::endl;

		MyData::checkB(a.getB());

		std::cout << "2. " << a << std::endl;

		MyData::checkMyData(a);

		std::cout << "3. " << a << std::endl;

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
#include <unordered_map>
#include <utility>
#include <string>
#include <vector>
#include <memory>

#include <iostream>
#include <tuple>

#include "u.hpp"

// ua bb vc

//#pragma clang diagnostic ignored "-Wunused"


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

int comp_dat(const void* a, const void * b)
{
	const data* l = (const data*)a;
	const data* r = (const data*)b;
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
	data key = { .nr = 3 };
	const data* res = (const data*)bsearch(&key, dat, sizeof(dat)/sizeof(dat[0]), sizeof(dat[0]), comp_dat);

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
