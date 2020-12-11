#include <iostream>
#include <memory>
#include <string>

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

void processPerson(Person* p) {
	p->name = "Name is changed";
}

int main() {
	Person* p;

	p = createPerson("Name is Name");

	cout << p-> name << endl;

	processPerson(p);

	cout << p-> name << endl;

	delete p;

	return 0;
}
