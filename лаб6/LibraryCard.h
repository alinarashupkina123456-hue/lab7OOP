#ifndef LIBRARY_CARD_H_
#define LIBRARY_CARD_H_

#include <iostream>
#include <string>

// ============================================================================
// ПУНКТ 6: Користувацький клас для використання в якості параметра шаблона
// ============================================================================
class LibraryCard {
public:
    std::string owner_name;
    int card_id;
    bool is_active;

    LibraryCard() : owner_name("Невідомо"), card_id(0), is_active(false) {}
    LibraryCard(std::string name, int id, bool active)
        : owner_name(name), card_id(id), is_active(active) {
    }

    friend std::ostream& operator<<(std::ostream& os, const LibraryCard& card) {
        os << "Квиток #" << card.card_id << " (" << card.owner_name
            << ", Статус: " << (card.is_active ? "Активний" : "Заблокований") << ")";
        return os;
    }
};

#endif  // LIBRARY_CARD_H_