#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>

std::tuple<double, char, std::string> get_student(int id) 
{
	if(id ==0) return std::make_tuple(3.89, 'A', "Lisa Simpsion");
	if(id ==1) return std::make_tuple(2.33, 'B', "Milhouse Van Houten");
	if(id ==2) return std::make_tuple(1.70, 'D', "Ralph Wiggum");
	throw std::invalid_argument("illegal id");
}


int main() 
{
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

}

