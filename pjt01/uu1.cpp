
#include <iostream>
#include <unordered_map>
#include <algorithm>

#include <uu1.hpp>


void MyUU1::test04() {
//std::unordered_map<std::string, std::string> mm = 
	std::unordered_multimap<std::string, std::string> mm = 
		{{"1", "0000"}, 
			{"1", "00"}, 
			{"1", "11"}, 
			{"2", "22"}, 
			{"3", "33"}, 
			{"4", "44"}};

	auto range = mm.equal_range("2");
	for(auto it = range.first;it != range.second;++it) {
		std::cout << it->first << ' ' << it->second << '\n';
	}

	int n = 0;
	std::for_each(mm.begin(), mm.end(), [&](auto& it) {
		std::cout << "[" << n++ << "] " << it.first << ", " << it.second << std::endl;
	});
}
