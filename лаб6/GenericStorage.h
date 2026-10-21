#ifndef GENERIC_STORAGE_H_
#define GENERIC_STORAGE_H_

#include <iostream>
#include <string>
#include <vector>

// ============================================================================
// ПУНКТ 5: Шаблон класу із 5 шаблонними даними та методами
// ============================================================================
template <typename T1, typename T2, typename T3, typename T4, typename T5>
class GenericStorage {
private:
    T1 data1_;
    T2 data2_;
    T3 data3_;
    T4 data4_;
    T5 data5_;
    std::vector<T1> items_list_;

public:
    GenericStorage(T1 d1, T2 d2, T3 d3, T4 d4, T5 d5)
        : data1_(d1), data2_(d2), data3_(d3), data4_(d4), data5_(d5) {
    }

    // Метод 1: Оновлення перших двох полів
    void updatePrimaryFields(const T1& d1, const T2& d2) {
        data1_ = d1;
        data2_ = d2;
    }

    // Метод 2: Додавання елементів до списку
    void addItem(const T1& item) {
        items_list_.push_back(item);
    }

    // Метод 3: Отримання кількості елементів
    size_t getItemCount() const {
        return items_list_.size();
    }

    // Метод 4: Відображення збережених даних
    void displayStorage() const {
        std::cout << "--- [GenericStorage Вміст] ---\n";
        std::cout << " Поле 1: " << data1_ << "\n";
        std::cout << " Поле 2: " << data2_ << "\n";
        std::cout << " Поле 3: " << data3_ << "\n";
        std::cout << " Поле 4: " << data4_ << "\n";
        std::cout << " Поле 5: " << data5_ << "\n";
        std::cout << " Всього елементів у списку: " << items_list_.size() << "\n";
    }

    // Метод 5: Порівняння першого та другого типів (якщо застосовно)
    bool isPrimaryValid() const {
        return (data3_ > 0);
    }

    T1 getData1() const { return data1_; }
    T2 getData2() const { return data2_; }
};

#endif  // GENERIC_STORAGE_H_