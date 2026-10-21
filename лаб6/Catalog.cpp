#include "Catalog.h"

void Catalog::addBook(Book* book) {
    if (book != nullptr) {
        books_.push_back(book);
    }
}

Book* Catalog::findBook(const std::string& title) {
    for (auto* book : books_) {
        if (book != nullptr && book->title == title) {
            return book;
        }
    }
    return nullptr;
}