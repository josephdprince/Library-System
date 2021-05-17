#ifndef __ADMIN_H__
#define __ADMIN_H__

#include <string>
#include "Standard.hpp"

class Admin : public Standard {
    public:
        void run();
        void addBook(Book*);
        void remBook(Book*);
};
