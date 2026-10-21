#ifndef ORDER_H_
#define ORDER_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include "Reader.h"
#include "Book.h"

enum class IssueType { ABONEMENT, READING_HALL };

class Order {
public:
    int order_id;
    Reader* reader;
    Book* book;
    IssueType issue_type;
    bool is_confirmed;

    Order(int id, Reader* r, Book* b, IssueType type)
        : order_id(id), reader(r), book(b), issue_type(type), is_confirmed(false) {
    }

    void processOrderByLibrarian() {
        if (book == nullptr) {
            throw std::runtime_error("Помилка: Книгу не знайдено у каталозі!");
        }
        if (reader == nullptr) {
            throw std::runtime_error("Помилка: Не вказано читача!");
        }

        if (reader->is_blacklisted) {
            throw std::runtime_error("Адміністратор заблокував читача (Чорний список)!");
        }
        if (!book->isAvailable()) {
            std::cout << "-> Книга недоступна. Автоматичне сповіщення: Читач "
                << reader->full_name << " поставлений у чергу резервування.\n";
            reader->reserveBook(book->title);
            return;
        }

        book->markBorrowed();
        reader->borrowBook(*book);
        is_confirmed = true;

        std::string type_str = (issue_type == IssueType::ABONEMENT) ? "на Абонемент" : "у Читальний зал";
        std::cout << "-> Бібліотекар видав книгу \"" << book->title << "\" " << type_str << " для " << reader->full_name << "\n";
    }
};

#endif  // ORDER_H_