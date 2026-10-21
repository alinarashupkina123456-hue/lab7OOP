#include "Book.h"

int Book::total_books = 0;

Book::Book()
    : LibraryItem("Невідомо", "Невідомо", 0),
    PrintableItem("Невідомо", "Невідомо", 0, 0),
    DigitalItem("Невідомо", "Невідомо", 0, "PDF"),
    price_(0.0),
    is_available_(true),
    available_copies_(0) {
    total_books++;
}

Book::Book(std::string t, std::string a, int y, int pages, std::string format,
    double pr, bool avail, int copies)
    : LibraryItem(t, a, y),
    PrintableItem(t, a, y, pages),
    DigitalItem(t, a, y, format),
    price_(pr),
    is_available_(avail),
    available_copies_(copies) {
    total_books++;
}

Book::~Book() {
    std::cout << "[Virtual Destructor Book]: '" << title << "' знищено.\n";
    total_books--;
}

void Book::displayInfo() const {
    std::cout << "Книга: \"" << title << "\" | Автор: " << author << " | Рік: " << year
        << " | Ціна: " << price_ << " грн | Доступно: "
        << (is_available_ ? "Так" : "Ні") << " (" << available_copies_ << " шт.)\n";
    printPageSummary();
    showDigitalSpecs();
}

void Book::markBorrowed() {
    if (available_copies_ <= 0) {
        throw std::out_of_range("Помилка: Немає доступних копій для видачі!");
    }
    available_copies_--;
    if (available_copies_ == 0) {
        is_available_ = false;
    }
}

void Book::markReturned() {
    available_copies_++;
    is_available_ = true;
}

void Book::Write(std::ofstream& fout) const {
    LibraryItem::Write(fout);
    fout << page_count << "\n" << file_format << "\n" << price_ << "\n"
        << is_available_ << "\n" << available_copies_ << "\n";
}

void Book::Read(std::ifstream& fin) {
    LibraryItem::Read(fin);
    fin >> page_count >> file_format >> price_ >> is_available_ >> available_copies_;
}

// --- ПУНКТ 1: Унарні оператори ---
Book& Book::operator++() {
    available_copies_++;
    is_available_ = true;
    return *this;
}

Book Book::operator++(int) {
    Book temp = *this;
    ++(*this);
    return temp;
}

Book& Book::operator--() {
    if (available_copies_ > 0) {
        available_copies_--;
        if (available_copies_ == 0) is_available_ = false;
    }
    return *this;
}

Book Book::operator--(int) {
    Book temp = *this;
    --(*this);
    return temp;
}

// --- ПУНКТ 2: Бінарні оператори ---
Book Book::operator+(int extra_copies) const {
    Book temp = *this;
    temp.available_copies_ += extra_copies;
    temp.is_available_ = true;
    return temp;
}

Book Book::operator-(int remove_copies) const {
    Book temp = *this;
    temp.available_copies_ = (temp.available_copies_ >= remove_copies)
        ? temp.available_copies_ - remove_copies
        : 0;
    if (temp.available_copies_ == 0) temp.is_available_ = false;
    return temp;
}

// --- ПУНКТ 3: Спеціальні оператори ---
Book Book::operator*(double factor) const {
    Book temp = *this;
    temp.price_ *= factor;
    return temp;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        title = other.title;
        author = other.author;
        year = other.year;
        page_count = other.page_count;
        file_format = other.file_format;
        price_ = other.price_;
        is_available_ = other.is_available_;
        available_copies_ = other.available_copies_;
        chapters_ = other.chapters_;
    }
    return *this;
}

Book& Book::operator+=(int extra_copies) {
    available_copies_ += extra_copies;
    is_available_ = true;
    return *this;
}

Book& Book::operator-=(int remove_copies) {
    available_copies_ = (available_copies_ >= remove_copies)
        ? available_copies_ - remove_copies
        : 0;
    if (available_copies_ == 0) is_available_ = false;
    return *this;
}

Book& Book::operator*=(double factor) {
    price_ *= factor;
    return *this;
}

std::string& Book::operator[](size_t index) {
    if (index >= chapters_.size()) {
        throw std::out_of_range("Помилка: Індекс глави вийшов за межі!");
    }
    return chapters_[index];
}