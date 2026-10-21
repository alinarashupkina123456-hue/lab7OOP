#ifndef LIBRARY_ITEM_H_
#define LIBRARY_ITEM_H_

#include <fstream>
#include <iostream>
#include <string>

class LibraryItem {
public:
    std::string title;
    std::string author;
    int year;

    LibraryItem() : title("Невідомо"), author("Невідомо"), year(0) {}
    LibraryItem(std::string t, std::string a, int y)
        : title(t), author(a), year(y) {
    }

    virtual ~LibraryItem() {
        std::cout << "[Virtual Destructor LibraryItem] Об'єкт '" << title << "' вилучено.\n";
    }

    virtual void displayInfo() const = 0;
    virtual void Write(std::ofstream& fout) const;
    virtual void Read(std::ifstream& fin);
};

class PrintableItem : virtual public LibraryItem {
public:
    int page_count;

    PrintableItem() : page_count(0) {}
    PrintableItem(std::string t, std::string a, int y, int pages)
        : LibraryItem(t, a, y), page_count(pages) {
    }

    virtual ~PrintableItem() {
        std::cout << "[Virtual Destructor PrintableItem]\n";
    }

    virtual void printPageSummary() const {
        std::cout << "  -> [Друковане видання] Кількість сторінок: " << page_count << "\n";
    }
};

class DigitalItem : virtual public LibraryItem {
public:
    std::string file_format;

    DigitalItem() : file_format("N/A") {}
    DigitalItem(std::string t, std::string a, int y, std::string format)
        : LibraryItem(t, a, y), file_format(format) {
    }

    virtual ~DigitalItem() {
        std::cout << "[Virtual Destructor DigitalItem]\n";
    }

    virtual void showDigitalSpecs() const {
        std::cout << "  -> [Цифрове видання] Формат файлу: " << file_format << "\n";
    }
};

#endif  // LIBRARY_ITEM_H_