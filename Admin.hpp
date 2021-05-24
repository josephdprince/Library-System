#ifndef __ADMIN_H__
#define __ADMIN_H__

#include <string>
#include "Standard.hpp"

class Admin : public Standard {
    public:
	Admin(const std::string& uname, const std::string& pass) : Standard(uname, pass) {}
        void addBook(Book*);
        void remBook(Book*);
};

#endif
