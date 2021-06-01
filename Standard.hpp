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
	std::vector<Lists*> extraDel;
	
    public:
	virtual ~Standard();
        virtual void newList(Library*);
        virtual void viewLists();
        void recommend(std::vector<Book*>);
        inline Standard(const std::string& uname, const std::string& pass) {userID = uname; password = pass;} 
	virtual void AddCheckedOut(Book*);
        virtual void AddHistory(std::pair<Book*, double>);
        virtual void AddLists(Composition*);
	virtual void AddExtraDel(Lists*);
	virtual void SetLists(std::vector<Composition*> lists) {this->lists = lists;}
        virtual std::vector<Book*> GetCheckedOut() {return checkedOut;}
        virtual std::map<Book*, double> GetHistory() {return history;}
        virtual std::vector<Composition*> GetLists() {return lists;}
	inline std::string getUserType() { return "standard"; }
        virtual void checkoutBook(Book*, std::vector<Book*>&);
        virtual void returnBook(Book*, std::vector<Book*>&, int);
	virtual void addBook(Book*, std::vector<Book*>&) {};
	virtual void remBook(Book*, std::vector<Book*>&) {};
        inline void displayBooks();
};

#endif
