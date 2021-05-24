#ifndef __STANDARD_H__
#define __STANDARD_H__

#include "User.hpp"
#include "Book.h"
#include "Library.h"
#include <string>
#include <vector>
#include <map>

class Standard : public User {
    private:
        std::vector<Book*> checkedOut;
	std::map<Book*, double> history;
    public:
        Standard(std::string userID);
        virtual void run(Library*);
        void recommend();
        void checkoutBook(Book*, std::vector<Book*>);
        void returnBook(Books*, std::vector<Book*>);
        void displayBooks();
        void addFavorite(Book*);
        void removeFavorite(Book*);
};

#endif
