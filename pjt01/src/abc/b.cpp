#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <any>
#include <iomanip>

using namespace std;

class Person {
	public:
		string name;

		Person();
		~Person();
		friend 
			std::ostream& operator<<(std::ostream& os, const Person& o);
		friend
			std::istream& operator>>(std::istream& is, Person& o);
};

Person::Person() {}
Person::~Person() {}

std::ostream& operator<<(std::ostream& os, const Person& o) {
	os << o.name;
	return os;
}

std::istream& operator>>(std::istream& is, Person& o) {
	is >> o.name;
	return is;
}

Person* createPerson(string _name) {
	Person* p = new Person();
	p->name  = _name;

	return p;
}

void processPerson(Person& p) {
	p.name = "Name is changed";
}

int f1(void* p) {
	cout << "f1 is called : " << setfill('0') << setw(2) << right << hex<< p << endl;
	return 10;
}
int f2(void* p) {
	cout << "f3 is called : " << setfill('0') << setw(2) << right << hex<< p << endl;
	return 20;
}
int f3(void* p) {
	cout << "f3 is called : " << setfill('0') << setw(2) << right << hex<< p << endl;
	return 30;
}

int main() {

#if 0
	Person* p;

	p = createPerson("Name is Name");

	cout << p-> name << endl;

	processPerson(*p);

	cout << p-> name << endl;

	delete p;

#endif

	std::unordered_map<std::string, std::function<int(void*)>> map;

	map.insert(std::make_pair("f1", f1));
	map.insert(std::make_pair("f2", f2));
	map.insert(std::make_pair("f3", f3));

	int a = 1000;
	cout << any_cast<std::function<int(void*)>>(map["f1"])(&a) << endl;
	cout << any_cast<std::function<int(void*)>>(map["f2"])(&(++a)) << endl;
	cout << any_cast<std::function<int(void*)>>(map["f3"])(&(++a)) << endl;


	return 0;
}
