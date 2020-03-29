
#include <iostream>
#include <string>


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


int main() {
	Msg* m = new Msg("a", 1.0, "b");

	delete m;
}
