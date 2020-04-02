
#include <iostream>
#include <memory>
#include <string>
#include <system_error>
#include <type_traits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <queue>
#include <condition_variable>
#include <mutex>

template<typename T>
T max(T const a, T const  b) {
	return b < a? a : b;
}


template<typename T = std::string>
bool f(T = "") {
	return true;
}

template<typename T>
T* max(T* a, T* b) {
	return *b<*a? a : b;
}
char const* max(char const* a, char const* b) {
	return std::strcmp(b, a) < 0 ? a:b;
}

std::vector<std::string> read_until(std::istream& is, std::string_view& terminator) {
	std::vector<std::string> res;
	for(std::string s; is >> s && s != terminator; )
		res.push_back(s);

	return res;
}
std::vector<std::string> read_until(std::istream& is, const std::string& terminator) {
	std::vector<std::string> res;
	for(std::string s; is >> s && s != terminator; )
		res.push_back(s);

	return res;
}

enum MsgType {
	Msg_Normal = 1,
	Msg_Abnormal,
	Msg_Exit
};

class UserData {
	private:
		std::string msgDetail;
		std::string userName;

	public:
		UserData(const char* _msgDetail, const char* _userName) 
			: msgDetail(_msgDetail), userName(_userName) {}
		UserData(const UserData& o) 
			: msgDetail(o.msgDetail), userName(o.userName) {}
		UserData(UserData&& o) 
			: msgDetail(std::move(o.msgDetail)), userName(std::move(o.userName)) {}
		
		UserData& operator=(const UserData& o) {
			if(this==&o) return *this;
			msgDetail = o.msgDetail;
			userName = o.userName;
			return *this;
		}

		UserData& operator=(UserData&& o) {
			if(this==&o) return *this;
			msgDetail = std::move(o.msgDetail);
			userName = std::move(o.userName);
			return *this;
		}

		friend
		std::ostream& operator<(std::ostream& os, const UserData& o) {
			os << "UserName : " << o.userName << ", MsgDetail : " << o.msgDetail;
			return os;
		}

		std::string& getMsgDetail() { return msgDetail; }
		std::string& getUserName() { return userName; }
};


class Msg {
	private:
		std::string msg;
		double val;
		std::string name;
		MsgType msgType;
		UserData* userData;

	public:
		Msg() : msg(""), val(-1.0), name(""), msgType(Msg_Normal), userData(nullptr) {}
		Msg(std::string _msg = "", double _val = -1.0, MsgType _msgType = MsgType::Msg_Normal, UserData* _userData = nullptr)
			: msg(_msg), val(_val), msgType(_msgType) , userData(_userData) {}
		Msg(const Msg& o) 
			: msg(o.msg), val(o.val), name(o.name), msgType(o.msgType), userData(o.userData) {}
		Msg(Msg&& o)
			: msg(std::move(o.msg)), val(o.val), name(std::move(o.name)), msgType(o.msgType) {
				if(this==&o) return;
				if(userData) delete userData;
				userData = nullptr;

				userData = o.userData;
				o.userData = nullptr;
		}

		Msg& operator=(const Msg& o) 
		{
			if(this==&o) return *this;
			msg = o.msg;
			val = o.val;
			name = o.name;
			msgType = o.msgType;
			if(userData) delete userData;
			userData = nullptr;
			UserData* os = o.userData;
			if(os) {
				userData = new UserData(os->getMsgDetail().c_str(), os->getUserName().c_str());
			}
			return *this;
		}

		Msg& operator=(Msg&& o) {
			if(this==&o) return *this;
			msg = std::move(o.msg);
			val = o.val;
			name = std::move(o.name);
			msgType = o.msgType;
			if(userData) delete userData;
			userData = nullptr;
			if(o.userData) {
				userData = o.userData;
			}
			o.userData = nullptr;

			return *this;
		}

		friend
		std::ostream& operator<<(std::ostream& os, const Msg& o) {
			os << "Name : " << o.name << ", Val : " << o.val << ", Msg : " << o.msg << ", MsgType : " << o.val;
			os << ", UserData : ";
			if(o.userData)
				os << o.userData;
			else
				os << "";
			return os;
		}

//		~UserData() {
//			if(userData) delete userData;
//			userData = nullptr;
//		}

		std::string& getMsg() { return msg; }
		double getVal() { return val; }
		std::string& getName() { return name; }
		MsgType getMsgType() { return msgType; }
		UserData* getUserData() { return userData; }

};


class SingleTone {
	private:
		static std::queue<Msg*> QUEUE;
		static std::mutex      MUTEX;
		static std::condition_variable CV;

	public:
		static void initialize();
};

void SingleTone::initialize() {
	std::queue<Msg*> QUEUE;
	std::mutex 		MUTEX;
	std::condition_variable CV;
};

int func1(int argc, char* argv[]);
int func2(int argc, char* argv[]);
int func3(int argc, char* argv[]);


int main(int argc, char* argv[]) {
	
	std::function<int(int argc, char* argv[])> f1 = func1;
	std::function<int(int argc, char* argv[])> f2 = func2;
	std::function<int(int argc, char* argv[])> f3 = func3;

	f1(argc, argv);
	f2(argc, argv);
	f3(argc, argv);

	return EXIT_SUCCESS;
}

int func2(int argc, char* argv[]) {
#ifdef MYDEBUG
	if(argc>1) {
		for(int i = 1;i<argc;i++) {
			std::cout << " argv[" << i << "] : " << argv[i] << (i+1>argc?", ": "");
		}
	}
#endif
	return EXIT_SUCCESS;
}

int func1(int argc, char* argv[]) {
#ifdef MYDEBUG
	if(argc>1) {
		for(int i = 1;i<argc;i++) {
			std::cout << " argv[" << i << "] : " << argv[i] << (i+1>argc?", ": "");
		}
	}
#endif

	Msg* m = new Msg{"a", 1.0};
	std::cout << " new Msg{\"a\", 1.0} = " << (*m) << std::endl;

	std::cout << " 1 < 2 = " << std::boolalpha << max(1,2) << std::endl;
	std::cout << " f(\"1\") = " << std::boolalpha << f() << std::endl;

	char const* a = "hello";
	char const* b = "world";
///	a[1] = 'J';
	a = "Good";
//	char* const aa = "Good";
//	aa[1] = 'C';
//	aa = "Gooooood";
	std::cout << "max(" << a << "," << b << ") : " <<  max(a,b) << std::endl;
	delete m;
	return EXIT_SUCCESS;
}


int func3(int argc, char* argv[]) {
	if(argc < 2) std::cout << "Default : " << argv[0] << std::endl; 

	SingleTone::initialize();

	std::string str{"a:b"};

	return EXIT_SUCCESS;
}

