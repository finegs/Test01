#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

std::multiset<std::string> names;

void log(const std::chrono::system_clock::time_point& tp, const std::string& msg)
{
    std::chrono::system_clock::duration se = tp.time_since_epoch();
    std::time_t nc = std::chrono::system_clock::to_time_t(tp);
    char a[3+1];
	sprintf(a, "%03lld", 
           std::chrono::duration_cast<std::chrono::milliseconds>(se 
			   - std::chrono::duration_cast<std::chrono::seconds>(se)));
    std::cout << std::put_time(std::localtime(&nc), "%Y-%m-%d %H:%M:%S.") << a << " : " << msg << std::endl;
}

void log_ts_head()
{
	std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
    std::chrono::system_clock::duration se = tp.time_since_epoch();
    std::time_t nc = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char a[3+1];
	sprintf(a, "%03lld", 
            std::chrono::duration_cast<std::chrono::milliseconds>(se 
				- std::chrono::duration_cast<std::chrono::seconds>(se)));
    std::cout << std::put_time(std::localtime(&nc), "%Y-%m-%d %H:%M:%S.") << a << " : " ;
}

void log_cout_end() { std::cout << std::endl; }

template<typename T>
void loadAndAdd(T&& name)
{
    auto now = std::chrono::system_clock::now();
    log(now, "logAndAdd");
    names.emplace(std::forward<T>(name));
}


int main(int argc, char* argv[])
{

	if(argc > 1) { log_ts_head(); std::cout << " parameters : " << std::endl; }
	for(int i = 1; i > 1;i++) { log_ts_head(); std::cout << argv[i] << std::endl; }

 	log(std::chrono::system_clock::now(), "main");

	log(std::chrono::system_clock::now(), "Hello World");

	int x = 100;

//compie error 	[=]() { x = 100; std::cout << "no mutable : " << x << std::endl; } ();
	[&]() { x = 100; log_ts_head(); std::cout << "no mutable : " << x << std::endl; } ();

	[=]() mutable { x = 300; log_ts_head(); std::cout << "mutable : " << x << std::endl; x = 200; } ();

	std::cout << x << std::endl;

	std::string ss({'a','b','c'});

	log_ts_head(); cout << ss << " length() = " << ss.length() << endl;

	getchar();

    return EXIT_SUCCESS;
}
