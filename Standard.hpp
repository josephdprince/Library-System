#ifndef __STANDARD_HPP__
#define __STANDARD_HPP__

#include <string>
#include <vector>
#include "Book.hpp"
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
