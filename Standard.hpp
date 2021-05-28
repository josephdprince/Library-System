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
        inline Standard(const std::string& uname, const std::string& pass) {userID = uname; password = pass;} 
        virtual void run(Library*);
	inline std::string getUserType() { return "standard"; }
        virtual void checkoutBook(Book*, std::vector<Book*>);
        virtual void returnBook(Book*, std::vector<Book*>);
	virtual void addBook(Book*, std::vector<Book*>) {};
	virtual void remBook(Book*, std::vector<Book*>) {};
        inline void displayBooks();
};

#endif
