#if 1

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <type_traits>
#include <array>
using namespace std;

template<typename T, typename ... Args>
class Widget {
	Widget(Args&&... args_) {
		static_assert((std::is_constructible_v<T, Args&&> && ...));
		(args.push_back(std::forward<Args>(args_)), ...);
		// for(auto args : args_...) args.push_back(arg);
	}

//	template<typename TT, typename ... Args>
	friend
	std::ostream& operator<<(std::ostream& os, const Widget<T, Args...> o);

	std::vector<T> args;
};


template<typename T, typename ... Args>
std::ostream& operator<<(std::ostream& os, const Widget<T, Args...>& o) {
	int i = 0;
	for(auto aa:o) os << (i==0?" ":",") << aa;
	os<<'\n';
	return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& o) {
	int i = 0;
	for(auto ii : o) os << (i==0? "" : ", ") << i;
	return os;
}

template<typename ... Args>
// template<typename ... Args2>
std::unique_ptr<Widget<Args&&...>> create(Args&&... args) {
	auto uptr(std::make_unique<Widget>(std::forward<Args>(args)...) );
	// return std::move(uptr);
	return uptr;
}

void tprintf(const char* format) // base function
{
    std::cout << format;
}
 
template<typename T, typename... Targs>
void tprintf(const char* format, T value, Targs... Fargs) // recursive variadic function
{
    for ( ; *format != '\0'; format++ ) {
        if ( *format == '%' ) {
           std::cout << value;
           tprintf(format+1, Fargs...); // recursive call
           return;
        }
        std::cout << *format;
    }
}


void (*queue_print)(int *queue, int *begin, int *end);

void qprt(int *queue, int *begin,int *end);

int main()
{
    std::ios_base::sync_with_stdio();
    
	const int queue_size = 10000;
    int queue[queue_size] = {0,};
    int begin = 0;
    int end = 0;
	queue_print = &qprt;

    int n = 0;
    string command;
    int value;
    cin >> n;
    while (n--)
    {
        cin >> command;
        
        if (command == "push")
        {
			cin >> value;
			queue[end] = value;
			end++;
		}
        else if (command == "npush")
        {
			int i = 0, cnt = 0;
			cin >> cnt;
			cout << "Command : " << command << ", n = " << n << ", cnt = " << cnt << " is started" << '\n';
            while(i<cnt) {
				try
				{
					cin >> value;
					queue[end++] = value;
					i++;
				}
				catch(const std::exception& e)
				{
					std::cerr << "fail to npush " << "currennt cnt = " << cnt << ", Reson = " << e.what() << '\n';
					break;
				}
			}
			cout << "Command : " << command << ", n = " << n << ", cnt = " << cnt << " is completed" << '\n';
        }
        else if (command == "pop")
        {
            if (begin == end)
            {
                cout << "-1" << '\n';
                continue;
            }

            cout << queue[begin] << '\n';
            begin++;
        }
        else if (command == "npop")
        {
			int i = 0, cnt = 0;
			cin >> cnt;
			
			while(i++<cnt) cout << queue[begin++] << '\n';

			// queue_print(queue, queue+begin, queue+end;
			// while (i < n && begin != end) {
			// 	cout << "queue[" << end << "]=" << queue[begin++] << '\n';
			// }
            // if (begin == end) {
            //     cout << "-1" << '\n';
            //     continue;
            // }

            // cout << queue[begin] << '\n';
            // begin++;
        }
		else if (command == "setn")
        {
			cin >> n;
            cout << "Command : " << command << ", n = " << n << " executed" << '\n';
        }
        else if (command == "size")
        {
            cout << end - begin << '\n';
        }
		else if (command == "print") {
			cout << "Command : " << command << ", n = " << n << " is started" << '\n';
			queue_print(queue, queue+begin, queue+end);
			cout << "Command : " << command << ", n = " << n << " is complited" << '\n';
		}
        else if (command == "empty")
        {
            if (end - begin == 0)
            {
                cout << "1" << '\n';
            }
            else
            {
                cout << "0" << '\n';
            }
        }
        else if (command == "front")
        {
            if (end - begin == 0)
            {
                cout << "-1" << '\n';
                continue;
            }

            cout << queue[begin] << '\n';
        }
        else if (command == "back")
        {
            if (end - begin == 0)
            {
                cout << "-1" << '\n';
                continue;
            }

            cout << queue[end - 1] << '\n';
        }
		else if(command == "wdget") {
			int i = 0, cnt = 0;
			cin >> cnt;
			cout << "Command : " << command << ", n = " << n << ", cnt = " << cnt << " is started" << '\n';
			vector<int> ar;
            while(i<cnt) {
				try
				{
					cin >> value;
					ar.push_back(value);
				}
				catch(const std::exception& e)
				{
					std::cerr << "fail to npush " << "currennt cnt = " << cnt << ", Reson = " << e.what() << '\n';
					break;
				}
			}
			Widget<int, std::vector<int>> wd(ar);
			cout << "Command : " << command << ", n = " << n << ", cnt = " << cnt << " is completed" << '\n';
			cout << "\t\t Widget=" << wd << '\n';
		}
		else {
			cout << "Unsupported Command : n = " << n << ", Command : " << command << '\n';
			cin.clear();
		}
	}

	return 0;
}

void qprt(int *q, int* begin, int* end) {
	int i = 0;
	int *cur = begin;
	while(cur != end) {
		cout << "queue["<< i++ <<"]="<< (*cur++) << '\n';
	}
}
    
#endif

#if 0
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib> // defines putenv in POSIX
#include <vector>
#include <string>
#include <chrono>
#include <sstream>
#include <my.hpp>
#include <utility>
#include <functional>

void* operator new(size_t size, std::align_val_t al) {
	std::cout << "Allocating " << size << " bytes" << std::endl;
	return malloc(size);
}

void* operator new[](size_t size, std::align_val_t al) {
	std::cout << "Allocating " << size << " bytes" << std::endl;
	return malloc(size);
}

struct Object {
	int x,y,z;
	friend std::ostream& operator<<(std::ostream& os, const Object& o);
};

std::ostream& operator<<(std::ostream& os, const Object& o) {
	os << "{" << o.x << "," << o.y << "," << o.z << ")";
	return os;
}


class Singleton {
	public:
		static Singleton& getInstance() {
			return s_Instance;
		}

		void function() {
		}

	private:
		Singleton() {}
		Singleton(const Singleton&) = delete;

		static Singleton s_Instance;
};

Singleton Singleton::s_Instance;


template<typename T>
T passR(T&& arg) {
	std::remove_reference_t<T> x;
	x = arg*arg;
	arg += x;
	return arg;
}

template<typename T>
T add(T&& o) {
	o++;
	return o;
}

template<typename T>
void g(T&);
template<typename T>
void g(T const&);
template<typename T>
void g(T&&);

template<typename T>
void forwardToG(T&& x) {
	g(std::forward<T>(x));
}

class Clz {
	public:
		std::string name;
	friend std::ostream& operator<<(std::ostream& os, const Clz& o);
};

std::ostream& operator<<(std::ostream& os, const Clz& o) {
	os << "{\"name\":" << "\"" << o.name << "\"}";
	return os;
}

// template<typename T>
void g(Clz& o) {
	std::cout << "T& : " <<  o << '\n';
}

void g(Clz const& o) {
	std::cout << "T const& : " <<  o << '\n';
}

void g(Clz&& o) {
	std::cout << "T&& : " <<  o << '\n';
}

using namespace std;

int main() {

// passR(42);
// int i;
// passR(i);

	{
		std::unique_ptr<Object[]> aaa = std::make_unique<Object[]>(10);

		aaa[0].x = 100;
		aaa[9].z = 200;

		int ii = 0;
		cout <<  __LINE__ << " : " << '\n';
		for_each(next(aaa.get(), 0), next(aaa.get(), 10), [&](Object& o) {
			o.z = o.x*1 + o.y*2 + ii++;
		});
		cout << '\n';

		cout <<  __LINE__ << " : " << '\n';
		for_each(&aaa[0], &aaa[10], [] (Object& o) { cout << o << ",";});
		cout << '\n';

		cout <<  __LINE__ << " : " << '\n';
		for_each(std::next(aaa.get(), 0), next(aaa.get(), 10), [](const Object& o) {
			cout << o << ',';
		});
		cout << '\n';
	}

	int i;
	cout << " i : "; cout.flush();
	cin >> i;
	cin.clear(); 
	cout << "add(" << i << ") : " << passR(i) << endl;

	// string l;
	// getline(cin, l);

	Clz cc;
	cc.name = "Name";
	forwardToG(cc);

	system("pause");

		return 0;
}
#endif

#if 0
	int nInput;
	printf("n:"); fflush(stdout);
	scanf("%d", &nInput);

	std::cout << my::ts() << ("#######################\n");
    std::time_t t = std::time(nullptr);
    std::cout << my::ts() << "UTC:       " << std::put_time(std::gmtime(&t), "%c %Z") << "\n";
    std::cout << my::ts() << "local:     " << std::put_time(std::localtime(&t), "%c %Z") << "\n";
    // POSIX-specific:
    std::string tz = "TZ=Asia/Seoul";
    putenv((char*)tz.data());
    std::cout << my::ts() << "Seoul: " << std::put_time(std::localtime(&t), "%c %Z") << std::endl;

	std::vector<uint8_t> v;
	v.push_back((uint8_t)0);
	
	std::cout << my::ts() << " ##################" << std::endl;
	std::cout << my::ts();
	for(size_t i = 0;i<v.size();i++) {
		std::cout << std::to_string(v[i]);
		std::cout << ((i%5==0) ? "\n" : "\t");
	}
	std::cout << std::endl;
	std::cout << my::ts() << "Good" << std::endl;

	Object* o = new Object();

	Singleton& instance = Singleton::getInstance();

	instance.function();

	std::cout << my::ts() << "Enter any keyboard : "; std::cout.flush();

	return 0;
}

#endif

#if 0
	std::string m = "Hello";
	m.insert(3, "  ");
	m.replace(3, 2, "");

	m.replace(m.find("Hell"), 4, "****");
	std::cout << my::ts() << m << std::endl;

	std::string line;
	std::getline(std::cin, line);

		return 0;
}
#endif

#if 0
	EFEM Temp
	int nInput = 0;
	int n2;
	// int i = 0;

	printf("Enter Number:"); fflush(stdout);
	scanf("%d", &nInput);fflush(stdin);

	if(nInput<1) nInput = 1;
	printf("2-Comp(%d) : %d\n", nInput, n2=(~nInput)+1);
	printf("OV(%d) : %d\n", nInput, (~n2)+1);
	printf("-OV(%d) : %d\n", nInput, ((1<<31) | nInput)+1);
	printf("~OV(%d) : %d\n", nInput, ~nInput);
	printf("1<<31(%d) : %d\n", 1, 1<<31);
	int n3=nInput;
	for(int i = 0;i<31;i++) {
		n3 <<=1; n3|=1;
	}
	printf("OV(%d)<<1 |1 = %d\n", nInput, n3);

		return 0;
}
#endif

#if 0
	std::vector<uint8_t> v;
	else if(nInput>9) nInput = 9;

	while(i<nInput) {
		putchar('*');
		i++;
	}
	getchar();
	putchar('\n');

		return 0;
}
#endif
