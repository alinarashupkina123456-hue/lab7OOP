#ifndef CATALOG_H_
#define CATALOG_H_

#include <vector>
#include <string>
#include "Book.h"

class Catalog {
private:
	std::vector<Book*> books_;

public:
	Catalog() = default;
	~Catalog() = default;

	void addBook(Book* book);
	Book* findBook(const std::string& title);
};

#endif  // CATALOG_H_