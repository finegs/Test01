
#include <iostream>

template<typename T>
struct is_void : std::false_type
{
};

template<>
struct is_void<void> : std::true_type
{
};

int main() {

	std::cout << is_void<char>::value << '\n';
	std::cout << is_void<void>::value << '\n';

    return 0;
}
