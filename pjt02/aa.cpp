#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <chrono>
#include <ctime>
#include <iomanip>

std::multiset<std::string> names;

void log(const std::chrono::system_clock::time_point& tp, const std::string& msg)
{
    std::chrono::system_clock::duration se = tp.time_since_epoch();
    std::time_t nc = std::chrono::system_clock::to_time_t(tp);
    char a[3+1];
	sprintf(a, "%03lld", 
           std::chrono::duration_cast<std::chrono::milliseconds>(se - std::chrono::duration_cast<std::chrono::seconds>(se)));
    std::cout << std::put_time(std::localtime(&nc), "%F %T.") << a << " : " << msg << std::endl;
}

template<typename T>
void loadAndAdd(T&& name)
{
    auto now = std::chrono::system_clock::now();
    log(now, "logAndAdd");
    names.emplace(std::forward<T>(name));
}


int main(int argc, char* argv[])
{

 //   log(std::chrono::system_clock::now(), "main");

    std::cout << "Hello World\n";


	int x = 100;

	[=]() { std::cout << "no mutable : " << x << std::endl; } ();

	[=]() mutable { x = 300; std::cout << "mutable : " << x << std::endl; x = 200; } ();

	std::cout << x << std::endl;

	getchar();

    return EXIT_SUCCESS;
}
