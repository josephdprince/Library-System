#ifndef __RATINGS_HPP__
#define __RATINGS_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Book.hpp"

class Lists {
    public:
        virtual void print(int) = 0;
	virtual void file(std::ofstream&) = 0;
        virtual void find_rating() = 0;
};

class Individual : public Lists {
    private:
        Book* book;
    public:
        virtual void print(int space) {
            for (int i = 0; i < space; ++i) {
                std::cout << " ";
            }
            std::cout << book->GetTitle() << " by " << book->GetAuthor() << std::endl;
        }

	virtual void file(std::ofstream& fout) {
            fout << book->GetID() << std::endl;
        }
        
        virtual void find_rating() {
            std::cout << book->GetTitle() << " is rated " << book->GetRating() << "/5.0" << std::endl;
        }

        void SetBook(Book* book) {
            this->book = book;
        }

        Book* GetBook() {return book;}
};

class Composition : public Lists {
    private:
        std::string list_name;
        std::vector<Lists*> list;
    public:
        virtual void print(int space) {
            std::cout << list_name << ":" << std::endl;
            for (auto i : list) {
                i->print(space + 1);
            }
        }

	virtual void file(std::ofstream& fout) {
            std::cout << list_name << std::endl;
            for (auto i : list) {
                i->file(fout);
            }
            fout << "}" << std::endl;
        }

        virtual void find_rating() {
            for (auto i : list) {
                i->find_rating();
            }
        }
        
        void Add(Lists* obj) {
            list.push_back(obj);
        }

        void SetName(std::string name) {
            list_name = name;
        }

        std::string GetName() {
            return list_name;
        }
};

#endif
