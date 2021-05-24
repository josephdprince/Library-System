#ifndef __STANDARD_H__
#define __STANDARD_H__

#include <string>
#include <vector>
#include "Book.h"
#include "User.hpp"

class Standard : public User {
    private:
        std::vector<Book*> checkedOut;
        std::vector<Book*> favorites;
        double totalFines;

    public:
        Standard(const std::string&, const std::string&);
        virtual void run();
        void recommend();
        void checkoutBook(Book*, std::vector<Book*>);
        void returnBook(Book*, std::vector<Book*>);
        void displayBooks();
        void addFavorite(Book*);
        void removeFavorite(Book*);
};

#endif
