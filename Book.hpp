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
	Book(std::string, std::string, std::string, int, double, int);
	Book(const Book& b);
	std::string GetTitle() const;
	std::string GetAuthor() const;
	std::string GetGenre() const;
	int GetID() const;
	double GetRating() const;
	int GetNumReviews() const;
	
	void SetTitle(std::string);
	void SetAuthor(std::string);
	void SetGenre(std::string);
	void SetID(int);
	void SetRating(double);
	void SetNumReviews(int);
};
#endif
