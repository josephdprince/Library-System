#ifndef __STANDARD_HPP__
#define __STANDARD_HPP__

#include "User.hpp"
#include "Book.hpp"
#include "Library.hpp"
#include "Lists.hpp"
#include <string>
#include <vector>
#include <map>

class Standard : public User {
    private:
        std::vector<Book*> checkedOut;
        std::map<Book*, double> history;
        std::vector<Composition*> lists;
	
    public:
        void newList(Library*);
        void viewLists();
        void recommend(std::vector<Book*>);
        inline Standard(const std::string& uname, const std::string& pass) : User(uname, pass) {} 
        inline virtual void run(Library*) {} 
	inline std::string getUserType() { return "standard"; }
        inline void checkoutBook(Book*, std::vector<Book*>);
        inline void returnBook(Book*, std::vector<Book*>);
        inline void displayBooks();
};

#endif
