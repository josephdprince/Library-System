#ifndef __STANDARD_H__
#define __STANDARD_H__

#include "User.h"
#include "Book.h"
#include <string>
#include <vector>

class Standard : public User {
    private:
        vector<Book*> checkedOut;
        vector<Book*> favorites;
        double totalFines;

    public:
        Standard(std::string userID);
        void run();
        void recommend();
        void checkoutBook(Book*);
        void returnBook(Books*);
        void displayBooks();
        void addFavorite(Book*);
        void removeFavorite(Book*);
};

#endif
