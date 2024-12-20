#if 0

#include <iostream>
#include <cstring>
#include "hash.hpp"

using namespace std;

int main() {
	Book book1;
	Book book2;
	Box box1;

	strcpy(book1.title, "Learn C++ Programming");
	strcpy(book1.author, "Channel Myyan");
	strcpy(book1.subject, "C++ Programming");
	book1.bookId = 6495407;

	strcpy(book2.title , "Telecom Billing");
	strcpy(book2.author , "Yakit Singha");
	strcpy(book2.subject, "Telecom");
	book2.bookId = 6495700;

	box1.setLength(2.0);
	box1.setBreath(2.0);

	printBook(book1);

	printBook(book2);

	box1.print();

	return 0;
}

#endif

#if 1

// This sample demonstrates how try {} block disables handler set by signal()
// on MinGW-w64 with GCC SJLJ build
#include <signal.h>
#include <iostream>

int izero = 0;

static void SIGWntHandler(int signum) //sub_code)
		{
	std::cout << "### : In signal handler, signum = " << signum << std::endl;
	std::cout << "### : Now exiting..." << std::endl;
//	std::exit(1);
	// TODO : Handle Final State to gracefully shutdown
}

int main(int argc, char* argv[]) {
	std::cout << "\tEntered main(), arming signal handler..." << std::endl;
	if (signal(SIGSEGV, (void (*)(int))SIGWntHandler)== SIG_ERR)
	std::cout << "\tsignal(OSD::SetSignal) error\n";
	if (signal(SIGFPE, (void (*)(int))SIGWntHandler)== SIG_ERR)
	std::cout << "\tsignal(OSD::SetSignal) error\n";
	if (signal(SIGILL, (void (*)(int))SIGWntHandler)== SIG_ERR)
	std::cout << "\tsignal(OSD::SetSignal) error\n";

	// this try block disables signal handler...
	try {
		std::cout << "\tIn try block" << std::endl;
	} catch (char* errMsg) {
		std::cerr << "Exception : " << errMsg;
	}

	std::cout << "#### : Doing bad things to cause signal..." << std::endl;
	izero = 1 / izero; // cause integer division by zero
	char* ptrnull = 0;
	ptrnull[0] = '\0'; // cause access violation

	std::cout << "We are too lucky..." << std::endl;
	return EXIT_SUCCESS;
}

#endif