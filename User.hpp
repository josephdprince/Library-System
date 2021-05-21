#ifndef __USER_HPP__
#define __USER_HPP__

#include <string>
#include "Library.h"

class User { 
    private:
        std::string userID;

    public:
        virtual void run(Library*) = 0;
        void setID(std::string userID) { this->userID = userID; }
};

#endif
