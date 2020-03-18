
#include <iostream>
#include <cstdlib>
#include <type_traits>
#include <string>
#include <memory>


class Cust {
	private:
		std::string first;
		std::string last;
		int id;
	public:
		template<typename S1, typename S2 = std::string,
//			typename = std::enable_if<!std::is_convertible_v<S1, Cust>>>
			typename = std::enable_if_t<std::is_convertible_v<S1, std::string>>>
		Cust(S1&& f, S2&& l = "", int i = 0) 
			: first(std::forward<S1>(f)), last(std::forward<S2>(l)), id(i) {
		}

		friend
			std::ostream& operator<<(std::ostream& os, const Cust& o) {
				os << "first:" << o.first << ", last:" <<  o.last <<  ", id:" << o.id << std::endl;
				return os;
		}
};



int main() {


	Cust c{"Joe", "Fix", 42};
	Cust f{"Nico"};
	std::string s("Joe");
	Cust d{std::move(s), "Fix", 42};
	Cust g = "Nico";
	Cust h{f};
	const Cust cc{"Jim"};
	Cust i{cc};

	std::cout << "c : " << c;
	std::cout << "f : " << f;
	std::cout << "d : " << d;
	std::cout << "g : " << g;
	std::cout << "h : " << h;
	std::cout << "i : " << i;

	return EXIT_SUCCESS;
}
