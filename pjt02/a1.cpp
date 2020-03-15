#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <unordered_set>

std::tuple<double, char, std::string> get_student(int id) 
{
	if(id ==0) return std::make_tuple(3.89, 'A', "Lisa Simpsion");
	if(id ==1) return std::make_tuple(2.33, 'B', "Milhouse Van Houten");
	if(id ==2) return std::make_tuple(1.70, 'D', "Ralph Wiggum");
	throw std::invalid_argument("illegal id");
}

int strrev(char* str, size_t len) {
	if(!str) return EXIT_FAILURE;
	if(len<=0) return EXIT_FAILURE;
	int  l = 0, r = len;
	char t;
	for(l = 0, r = len-1;l<r;l++,r--) {
		t = str[l]; str[l] = str[r]; str[r] = t;
	}
	return EXIT_SUCCESS;
}

struct Point { double x, y; };

int f2() {
	auto std0 = get_student(0);

	std::cout << "ID : 0, "
				<< "GPA: " <<  std::get<0>(std0) << ", "
				<< "Grade: " <<  std::get<1>(std0) << ", "
				<< "Name: " <<  std::get<2>(std0) << "\n";

	double gpa1;
	char grade1;
	std::string name1;

	std::tie(gpa1, grade1, name1) = get_student(1);


	std::cout << "ID : 1, "
			<< "GPA: " <<  gpa1 << ", "
			<< "Grade: " << grade1 << ", "
			<< "Name: " <<  name1 << "\n";

	std::cout << "Set    Grade: " << grade1 << std::endl;

	grade1 = 'G';

	std::cout <<  "\tNew grade:" << grade1 << std::endl;


	auto [gpa2, grade2, name2] = get_student(2);
	
	std::cout << "ID : 2, "
				<< "GPA: " <<  gpa2 << ", "
				<< "Grade: " << grade2 << ", "
				<< "Name: " <<  name2 << "\n";

	return EXIT_SUCCESS;
}

void f3() {
	std::string str;
	size_t len;

	std::cout << "str? : "; std::cout.flush();
	std::cin >> str; std::cin.clear();
	char* cstr = new char[(len = str.length())+1];
	memset(cstr, '\0', len+1);
	strncpy(cstr, str.c_str(), len);
	std::cout << "str before strrev(cstr) : " << cstr << std::endl;
	std::cout << "strrev("<<cstr<<", " << len << ") = " << strrev(cstr, len) << std::endl;
	std::cout << "str after  strrev(cstr) : " << cstr << std::endl;

	std::free(cstr);
}
	
int f1() {
	Point pts[3] = { {1, 0}, {2, 0}, {3, 0} };
 
	//points is a set containing the addresses of points
	std::unordered_set<Point *> points = { pts, pts + 1, pts + 2 };
 
	//Change each y-coordinate of (i, 0) from 0 into i^2 and print the point
	for(auto iter = points.begin(); iter != points.end(); ++iter){
	    (*iter)->y = ((*iter)->x) * ((*iter)->x); //iter is a pointer-to-Point*
	    std::cout << "(" << (*iter)->x << ", " << (*iter)->y << ") ";
	}
	std::cout << '\n';
 
	//Now using the range-based for loop, we increase each y-coordinate by 10
	for(Point * i : points) {
	    i->y += 10;
	    std::cout << "(" << i->x << ", " << i->y << ") ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}


int main() 
{

	f1();
	f2();
	f3();


}

