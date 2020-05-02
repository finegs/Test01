#include <ios>
#include <iostream>
#include <cstdlib>

class A6Clz {
	private:
		const char* id;

	public:
		A6Clz(const char* _id) : id(_id) {
			std::cout << "&_id : " << &_id << std::endl;
			std::cout << "&id  : " << &id << std::endl;
			std::cout << "&id  : " << &id << std::endl;
			std::boolalpha(std::cout);
			std::cout << " ( &id == &_id ) = " << (&_id == &id) << std::endl;
			std::cout << " ( id == _id ) = " << (_id == id) << std::endl;
		}

		friend std::ostream& operator<<(std::ostream& os, const A6Clz& o) {
			os << "&o : " << &o << ", &id : "<< &o.id << ", id : " << o.id << std::endl;
			return os;
		}
};



int main() {

	const char gid[]{"Good"};

	std::cout << "gid  : " << &gid << std::endl;
	A6Clz a(gid);

	std::cout << a << std::endl;

	return EXIT_SUCCESS;
}
