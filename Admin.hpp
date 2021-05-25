#ifndef __ADMIN_HPP__
#define __ADMIN_HPP__

#include <string>
#include <vector>
#include "Standard.hpp"
#include "Library.hpp"

class Admin : public Standard {
    public:
        virtual void run(Library*);
        void addBook(Book*, std::vector<Book*>);
	Admin(const std::string& uname, const std::string& pass);
	inline std::string getUserType() { return "admin"; }
        void remBook(Book*, std::vector<Book*>);
};

#endif
