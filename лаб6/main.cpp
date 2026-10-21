#include <iostream>
#include <windows.h>

#include "Book.h"
#include "Catalog.h"
#include "GenericStorage.h"
#include "LibraryCard.h"
#include "LibraryItem.h"
#include "Order.h"
#include "Reader.h"

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::cout << "========================================================\n";
    std::cout << " ЛАБОРАТОРНА РОБОТА №6 (3 РІВЕНЬ) \n";
    std::cout << "========================================================\n";

    Book book1("Кобзар", "Т.Шевченко", 1840, 350, "PDF", 200.0, true, 5);
    book1.addChapter("Вступ");
    book1.addChapter("Думи мої");

    // --- ПУНКТ 1: Унарні оператори ---
    std::cout << "\n--- ПУНКТ 1: Демонстрація операторів ++ та -- ---\n";
    std::cout << "Початкові копії: " << book1.getCopies() << "\n";
    ++book1;
    std::cout << "Після префіксного ++: " << book1.getCopies() << "\n";
    book1--;
    std::cout << "Після постфіксного --: " << book1.getCopies() << "\n";

    // --- ПУНКТ 2: Бінарні оператори ---
    std::cout << "\n--- ПУНКТ 2: Демонстрація операторів + та - ---\n";
    Book book_plus = book1 + 3;
    std::cout << "book1 + 3 (нові копії): " << book_plus.getCopies() << "\n";
    Book book_minus = book1 - 2;
    std::cout << "book1 - 2 (видалені копії): " << book_minus.getCopies() << "\n";

    // --- ПУНКТ 3: Оператори *, =, +=, -=, *=, [] ---
    std::cout << "\n--- ПУНКТ 3: Демонстрація *, =, +=, -=, *=, [] ---\n";
    book1 += 2;
    std::cout << "Після book1 += 2: " << book1.getCopies() << " шт.\n";
    book1 *= 1.10; // Збільшення ціни на 10%
    std::cout << "Після book1 *= 1.10 (нова ціна): " << book1.getPrice() << " грн\n";
    std::cout << "Глава [1] через operator[]: " << book1[1] << "\n";

    // --- ПУНКТ 4: Шаблонна функція в класі ---
    std::cout << "\n--- ПУНКТ 4: Демонстрація шаблонної функції ---\n";
    book1.printAttributeFormatted("Рік видання (int)", book1.year);
    book1.printAttributeFormatted("Ціна книги (double)", book1.getPrice());
    book1.printAttributeFormatted("Назва (string)", book1.title);

    // --- ПУНКТ 5 & 6: Шаблон класу з 5 параметрами та Користувацьким типом ---
    std::cout << "\n--- ПУНКТ 5 & 6: Шаблон класу GenericStorage та LibraryCard ---\n";
    LibraryCard my_card("Аліна Ращупкіна", 2026, true);

    // Створення екземпляру шаблону із 5 типами, де T1 є користувацьким типом LibraryCard
    GenericStorage<LibraryCard, std::string, int, double, bool> storage(
        my_card, "Головне Сховище", 100, 4999.99, true);

    storage.addItem(my_card);
    storage.displayStorage();

    return 0;
}