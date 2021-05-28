#ifndef __USER_HPP__
#define __USER_HPP__

#include "Book.hpp"
#include <vector>
#include <string>
class Library;

class User { 
    protected:
        std::string userID;
	std::string password;

    public:
        virtual void run(Library*) = 0;
	virtual void checkoutBook(Book*, std::vector<Book*>) = 0;
	virtual void returnBook(Book*, std::vector<Book*>) = 0;
	virtual void recommend(std::vector<Book*>) = 0;
	virtual void addBook(Book*, std::vector<Book*>) = 0;
	virtual void remBook(Book*, std::vector<Book*>) = 0;
	inline std::string getUserID() { return userID; }
	virtual std::string getUserType() = 0;
	bool check(const std::string& uname, const std::string& pass) const;
};

#endif
