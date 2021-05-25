#ifndef __BOOK_HPP__
#define __BOOK_HPP__

#include<string>

class Book {
    private:
	std::string title;
	std::string author;
	std::string genre;
	int ID;
	double rating;
	int numReviews;

    public:
	Book(std::string, std::string, std::string, int);
	
	std::string GetTitle();
	std::string GetAuthor();
	std::string GetGenre();
	int GetID();
	double GetRating();
	int GetNumReviews();
	
	void SetTitle(std::string);
	void SetAuthor(std::string);
	void SetGenre(std::string);
	void SetID(int);
	void SetRating(double);
	void SetNumReviews(int);
};
#endif
