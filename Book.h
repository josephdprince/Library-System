#ifndef __BOOK_H__
#define __BOOK_H__

#include<string>

class Book {
    private:
	std::string title;
	std::string author;
	std::string genre;
	int ID;
	std::string dueDate;
	double rating;
	int numReviews;

    public:
	Book(std::string, std::string, std::string, int);
	
	std::string GetTitle();
	std::string GetAuthor();
	std::string GetGenre();
	int GetID();
	std::string GetDueDate();
	double GetRating();
	int GetNumReviews();
	
	void SetTitle(std::string);
	void SetAuthor(std::string);
	void SetGenre(std::string);
	void SetID(int);
	void SetDueDate(std::string);
	void SetRating(double);
	void SetNumReviews(int);
};
#endif
