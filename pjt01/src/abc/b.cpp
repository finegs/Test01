#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <any>
#include <iomanip>
#include <assert.h>
#include <cstring>

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

class TTLCache {
public:

 //Initializes with a given ttl (in seconds)
 TTLCache(uint32_t ttl):ttlSeconds(ttl){}

 //Adds an item to the cache along with the current timestamp
 bool add(const std::string& key, const std::any& value);

 //Gets a value from cache if exists
 // - otherwise returns empty std::any
 std::any get(const std::string& key);

 //Erases an item for a given key if exists
 void erase(const std::string& key);

 // Fires periodically in a separate thread and erases the items
 //  - from cache that are older than the ttlSeconds
 void onTimer();

 //...more interfaces...

private:

 //Values stored along with timestamp
 struct Item {
  time_t timestamp;
  std::any value;
 };

 //Expire time (ttl) of items in seconds
 uint32_t ttlSeconds;

 //Items are stored against keys along with timestamp
 std::unordered_map<std::string, Item> items;
};

#if 1
struct Abstract {
	// NG
//	virtual void f() { cout << "Abstract.f()" << endl;}
//	 OK
	virtual void f() = 0;
};
void Abstract::f() { cout << "Abstract.f()" << endl; }
struct Concrete : Abstract {
	// NG
//	void f() override { cout << "Concrete.f()" << endl;}
	// OK
//	virtual void f() {}
	virtual void f();
	virtual void ff();
};
void Concrete::f() { cout << "Concrete.f()" << endl; }
void Concrete::ff() { cout << "Concrete.ff()" << endl; }

struct Concrete2 : Concrete {
	void ff() override = 0;
};

#endif

#if 0
struct Abstract {
	virtual void f() = 0;
};

struct Concrete : Abstract {
	void f() override {}
	virtual void ff();
};

struct Concrete2 : Concrete {
	void ff() override = 0;
};
#endif

int main() {

	Concrete b;
	b.f();

	Abstract& a = b;
	a.f();

//	Concrete2 c;
//	c.ff();

#if 0
	Person* p;

	p = createPerson("Name is Name");

	cout << p-> name << endl;

	processPerson(*p);

	cout << p-> name << endl;

	delete p;

#endif

#if 0
	std::unordered_map<std::string, std::function<int(void*)>> map;

	map.insert(std::make_pair("f1", f1));
	map.insert(std::make_pair("f2", f2));
	map.insert(std::make_pair("f3", f3));

	int a = 1000;
	cout << any_cast<std::function<int(void*)>>(map["f1"])(&a) << endl;
	cout << any_cast<std::function<int(void*)>>(map["f2"])(&(++a)) << endl;
	cout << any_cast<std::function<int(void*)>>(map["f3"])(&(++a)) << endl;
#endif

#if 0
	std::any a = std::string("hello");

	std::cout << std::any_cast<std::string>(a) << "\n";

	auto str = std::any_cast<std::string&&>(std::move(a));

	cout << "str:" << str << endl;
	cout << "a:" << std::any_cast<std::string&>(a) << endl;


	cout << boolalpha << a.has_value() << endl;

	struct A {};
	struct B : A {};

	std::any a = B{};
	A* ptrA = std::any_cast<A>(&a);
	cout << (ptrA==nullptr ? "true" : "false") << endl;

	std::any ai = 10;

	try {
		std::cout << std::any_cast<int64_t>(ai) << endl;
	} catch (const std::bad_any_cast& e) {
		cout << "Wrong Type!" << endl;
	}
#endif

	std::function<size_t(const char*)> mstrlen = [&](const char* str)->size_t { return strlen(str); };

	cout << "strlen(\"aaa\")="<< mstrlen("aaa");

	return 0;
}
