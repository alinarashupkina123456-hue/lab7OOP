#include "Reader.h"
#include <iostream>

Reader::Reader()
    : full_name("Невідомо"), ticket_number(0), is_blacklisted(false),
    current_borrowed_book(nullptr), borrow_duration_days(0) {
}

Reader::Reader(std::string name, int ticket)
    : full_name(name), ticket_number(ticket), is_blacklisted(false),
    current_borrowed_book(nullptr), borrow_duration_days(0) {
}

Reader::~Reader() {
    std::cout << "[Destructor Reader]: Читач " << full_name << " видалений.\n";
}

void Reader::displayReaderInfo() const {
    std::cout << "Читач: " << full_name << " | Квиток №: " << ticket_number
        << " | В чорному списку: " << (is_blacklisted ? "ТАК" : "Ні") << "\n";
}

void Reader::borrowBook(Book& book) {
    if (is_blacklisted) {
        throw std::runtime_error("Читач у ЧОРНОМУ СПИСКУ! Видача заборонена.");
    }
    book.markBorrowed();
    current_borrowed_book = &book;
    borrow_duration_days = 14;
    reading_history.push_back(book.title);
    std::cout << "-> Читач " << full_name << " успішно взяв книгу: \"" << book.title << "\"\n";
}

void Reader::returnBook() {
    if (current_borrowed_book != nullptr) {
        current_borrowed_book->markReturned();
        std::cout << "-> Читач " << full_name << " повернув книгу: \"" << current_borrowed_book->title << "\"\n";
        current_borrowed_book = nullptr;
    }
    else {
        std::cout << "-> У читача немає активної книги.\n";
    }
}

void Reader::reserveBook(const std::string& book_title) {
    reserved_books.push_back(book_title);
    std::cout << "-> [Резервування] Читач " << full_name << " зарезервував книгу: \"" << book_title << "\"\n";
}

void Reader::extendBorrowPeriod(int extra_days, bool is_reserved_by_others) {
    if (is_reserved_by_others) {
        throw std::invalid_argument("Помилка продовження: Книга зарезервована іншим читачем!");
    }
    borrow_duration_days += extra_days;
    std::cout << "-> Термін користування продовжено на " << extra_days << " днів. Новий термін: " << borrow_duration_days << " днів.\n";
}