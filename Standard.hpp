#ifndef __STANDARD_HPP__
#define __STANDARD_HPP__

#include "User.hpp"
#include "Book.h"
#include "Library.h"
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
        Standard(std::string userID);
        virtual void run(Library*);
        void newList(Library*);
        void viewLists();
        void recommend(std::vector<Book*>);
        void checkoutBook(Book*, std::vector<Book*>);
        void returnBook(Book*, std::vector<Book*>);
        void displayBooks();
        void addFavorite(Book*);
        void removeFavorite(Book*);
};

#endif
