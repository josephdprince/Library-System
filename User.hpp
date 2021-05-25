#ifndef __USER_H__
#define __USER_H__

#include <string>

class User { 
    protected:
        std::string userID;
	std::string password;

    public:
	User(const std::string&, const std::string&);
	inline std::string getUserID() { return userID; }
	virtual std::string getUserType() = 0;
	bool check(const std::string& uname, const std::string& pass) const;
        virtual void run() = 0;
};

#endif
