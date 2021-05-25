#ifndef __ADMIN_H__
#define __ADMIN_H__

#include <string>
#include <vector>
#include "Standard.hpp"

class Admin : public Standard {
    public:
	Admin(const std::string& uname, const std::string& pass);
	inline std::string getUserType() { return "admin"; }
        void run();
	void addBook(Book*, std::vector<Book*>);
        void remBook(Book*, std::vector<Book*>);
};

#endif
