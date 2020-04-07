#include <iostream>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person {
	public:
		string name;

		Person();
		~Person();
};

Person::Person() {}
Person::~Person() {}

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
