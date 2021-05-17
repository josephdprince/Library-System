#ifndef __USER_H__
#define __USER_H__

#include <string>

class User { 
    private:
        std::string userID;

    public:
        virtual void run() = 0;
        void setID(std::string userID) { this->userID = userID; }
};

#endif
