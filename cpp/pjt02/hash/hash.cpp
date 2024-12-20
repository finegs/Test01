#include <stdio.h>
#include <iostream>
#include <cstring>
#include "hash.hpp"

using namespace std;

void Book::printBook() {
	printf("Book={Title=%s, Author=%s, Subject=%s, Id=%d\n",
			title, author, subject, bookId);
}

std::ostream& operator<<(std::ostream& os, const Book& o) {
	os << "{\"title\":" << o.title;
	os << ",\"author\":" << o.author;
	os << ",\"id\":" << o.bookId;
	os << ",\"subject\":" << o.subject;
	os << "}";
	return os;
}

std::istream& operator>>(std::istream& is, Book& o) {
	is >> o.title >> o.author >> o.bookId >> o.subject;
	return is;
}

double Box::getLength() {
	return this->length;
}
double Box::getBreath() {
	return this->breath;
}
double Box::getHeight() {
	return this->height;
}
void Box::setLength(float f) {
	this->length = f;
}
void Box::setBreath(float f) {
	this->breath = f;
}
void Box::setHeight(float f) {
	this->height = f;
}
void Box::print() {
	printf("Length=%f, Breadth=%f, Height=%f\n", length, breath, height);
}


