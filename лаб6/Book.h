#ifndef BOOK_H_
#define BOOK_H_

#include "LibraryItem.h"
#include <exception>
#include <stdexcept>
#include <vector>

class Book : public PrintableItem, public DigitalItem {
private:
    double price_;
    bool is_available_;
    int available_copies_;
    std::vector<std::string> chapters_;

public:
    static int total_books;

    Book();
    Book(std::string t, std::string a, int y, int pages, std::string format,
        double pr, bool avail, int copies);

    virtual ~Book() override;

    void displayInfo() const override;
    void markBorrowed();
    void markReturned();

    void Write(std::ofstream& fout) const override;
    void Read(std::ifstream& fin) override;

    double getPrice() const { return price_; }
    bool isAvailable() const { return is_available_; }
    int getCopies() const { return available_copies_; }
    void addChapter(const std::string& chapter) { chapters_.push_back(chapter); }

    // ==========================================================================
    // ПУНКТ 1: Унарні оператори ++ та -- (Префіксні та Постфіксні)
    // ==========================================================================
    Book& operator++();    // Префіксний ++ (збільшує кількість копій)
    Book operator++(int);  // Постфіксний ++
    Book& operator--();    // Префіксний -- (зменшує кількість копій)
    Book operator--(int);  // Постфіксний --

    // ==========================================================================
    // ПУНКТ 2: Бінарні оператори + та -
    // ==========================================================================
    Book operator+(int extra_copies) const;  // Додати копії
    Book operator-(int remove_copies) const; // Зменшити копії

    // ==========================================================================
    // ПУНКТ 3: Оператори *, =, +=, -=, *=, []
    // ==========================================================================
    Book operator*(double factor) const;     // Множення ціни на коефіцієнт
    Book& operator=(const Book& other);      // Присвоєння
    Book& operator+=(int extra_copies);      // Присвоєння зі додаванням
    Book& operator-=(int remove_copies);     // Присвоєння зі відніманням
    Book& operator*=(double factor);         // Зміна ціни через *=
    std::string& operator[](size_t index);   // Індексація глав книги

    // ==========================================================================
    // ПУНКТ 4: Шаблонна функція в класі
    // ==========================================================================
    template <typename T>
    void printAttributeFormatted(const std::string& label, const T& value) const {
        std::cout << "  [Форматований вивід] " << label << ": " << value << "\n";
    }
};

#endif  // BOOK_H_