#ifndef __USER_HPP__
#define __USER_HPP__

#include <string>
#include "Library.hpp"

class User { 
    protected:
        std::string userID;
	std::string password;

    public:
        virtual void run(Library*) = 0;
	User(const std::string&, const std::string&);
	inline std::string getUserID() { return userID; }
	virtual std::string getUserType() = 0;
	bool check(const std::string& uname, const std::string& pass) const;
};

#endif
