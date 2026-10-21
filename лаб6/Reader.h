#ifndef READER_H_
#define READER_H_

#include <string>
#include <vector>
#include "Book.h"

class Reader {
public:
	std::string full_name;
	int ticket_number;
	bool is_blacklisted;

	std::vector<std::string> reading_history;
	std::vector<std::string> reserved_books;
	Book* current_borrowed_book;
	int borrow_duration_days;

	Reader();
	Reader(std::string name, int ticket);
	~Reader();

	void displayReaderInfo() const;
	void borrowBook(Book& book);
	void returnBook();
	void reserveBook(const std::string& book_title);
	void extendBorrowPeriod(int extra_days, bool is_reserved_by_others);
};

#endif  // READER_H_