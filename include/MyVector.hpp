#pragma once
#include <cstddef>
#include <utility>

// Класс-оболочка для динамического массива целых чисел.
// Демонстрирует copy и move семантику.
class MyVector {
public:
    MyVector();                            // конструктор по умолчанию
    explicit MyVector(std::size_t n);      // конструктор с размером
    ~MyVector();                           // деструктор

    // Конструктор копирования
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);

    // Конструктор перемещения
    MyVector(MyVector&& other) noexcept;
    MyVector& operator=(MyVector&& other) noexcept;

    int& operator[](std::size_t i);
    const int& operator[](std::size_t i) const;
    std::size_t size() const noexcept { return sz; }

private:
    int* data;
    std::size_t sz;
};
