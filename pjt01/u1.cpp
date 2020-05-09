
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class Customer {
	private:
		std::string name;
		
	public:
		Customer(const std::string& n) : name(n) {}
		std::string getName() const { return name; }
		friend std::ostream& operator<<(std::ostream& os, const Customer& o);
};

std::ostream& operator<<(std::ostream& os, const Customer& o) {
	os << "(" << o.getName() << ")";
	return os;
}

int main() {
	struct MyCustomerHash {
		std::size_t operator() (const Customer& o) const {
			return std::hash<std::string>()(o.getName());
		}
	};

	struct MyCustomerEqual {
		bool operator()(const Customer& a, const Customer& b) const {
			return a.getName() == b.getName();
		}
	};

	auto hash  = [](const Customer& o) { return std::hash<std::string>()(o.getName()); };
	auto equal = [](const Customer& a, const Customer& b) { return a.getName() == b.getName(); };

	std::unordered_set<Customer, MyCustomerHash, MyCustomerEqual> coll;
	// coll.emplace("aa");
	// coll.insert(Customer("aa"));
	coll.insert({"aa"});
	coll.emplace("aa");

	std::cout << (coll.end() != coll.find({"aa"}) ? "founded" : "not found") << std::endl;

	using CustomHashSet = std::unordered_set<Customer, decltype(hash), decltype(equal)>;
	CustomHashSet cs(10, hash, equal);
	cs.insert({"aa"});
	cs.emplace("aa");
	cs.insert({"bb"});

	std::cout << (cs.end() != cs.find({"aa"}) ? "founded" : "not found") << std::endl;
	// std::unordered_set<Customer, decltype(hash), decltype(equal)> col2;

	std::for_each(cs.begin(), cs.end(), [](auto& i) { std::cout<< ", (" << i <<")" << std::endl; });
	std::unordered_map<Customer, Customer, MyCustomerHash, MyCustomerEqual> m1;
	Customer c{"bb"};
	m1.insert({{"a"},{"b"}});
	m1.insert({c, c});
	std::for_each(m1.begin(), m1.end(), [](auto& i) { std::cout<< ", (" << i.first << ", " << i.second << ")"; });
	std::cout<< std::endl;

	std::unordered_multimap<Customer, Customer, MyCustomerHash, MyCustomerEqual> m2;

	m2.insert({{"a1"}, {"a1 value"}});
	m2.insert({{"a1"}, {"a1 other value"}});

	std::for_each(m2.begin(), m2.end(), [](auto& i) { std::cout<< ", (" << i.first << ", " << i.second << ")"; });

	std::cout<< std::endl;

	return 0;
}
