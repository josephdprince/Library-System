#ifndef __USER_H__
#define __USER_H__

#include <string>

class User { 
    private:
        std::string userID;
	std::string password;

    public:
	std::string getUserID() const { return userID; }
	void setID(const std::string& u) { userID = u; }
	void setPass(const std::string& p) { password = p; }

	bool check(const std::string& uname, const std::string& pass) const {
		if(uname == "")
			return false;
		return userID == uname && password == pass;
	}
	
        virtual void run() = 0;
};

#endif
