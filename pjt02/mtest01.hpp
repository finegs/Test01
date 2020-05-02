#ifndef __MTEST01_HPP
#define __MTEST01_HPP

#include <iostream>

class Point {
	private:
		int x,y;

	public:
		Point() :x(0), y(0) {}
		Point& operator() (int dx, int dy);
		void show() { std::cout << "x = " << x << ", y = " << y; }
};

Point& Point::operator() (int dx, int dy) {
	x = dx; y = dy; return *this;
}

std::string remove_ctrl(std::string s){
	std::string result;

	for(size_t i = 0;i < s.length();++i) {
		if(s[i] >= 0x20) result = result + s[i];
	}
	return result;
}

std::string remove_ctrl_mutating(std::string s){
	std::string result;

	result.reserve(s.length());

	for(size_t i = 0;i < s.length();++i) {
		if(s[i] >= 0x20) result +=  s[i];
	}
	return result;
}

#endif
