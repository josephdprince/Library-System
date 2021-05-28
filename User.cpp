#include <string>
#include "User.hpp"

User::User(const std::string& uname, const std::string& pass) : userID(uname), password(pass) {}

bool User::check(const std::string& uname, const std::string& pass) const {
	if(uname == "")
		return false;
	return userID == uname && password == pass;
}

void User::run(Library* library) {}
