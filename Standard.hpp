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
        void checkoutBook(Book*, std::vector<Book*>);
        void returnBook(Books*, std::vector<Book*>);
        void displayBooks();
        void addFavorite(Book*);
        void removeFavorite(Book*);
};

#endif
