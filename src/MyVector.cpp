#include "MyVector.hpp"
#include <algorithm>
#include <iostream>

// Код конструктора по умолчанию
MyVector::MyVector() : data(nullptr), sz(0) {}

// Конструктор с выделением памяти
MyVector::MyVector(std::size_t n)
    : data(new int[n]), sz(n) {
    std::fill(data, data + sz, 0);
}

// Деструктор освобождает память
MyVector::~MyVector() {
    delete[] data;
}

// Копирующий конструктор (глубокое копирование)
MyVector::MyVector(const MyVector& other)
    : data(new int[other.sz]), sz(other.sz) {
    std::copy(other.data, other.data + sz, data);
}

// Копирующий оператор присваивания
MyVector& MyVector::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] data;
        sz = other.sz;
        data = new int[sz];
        std::copy(other.data, other.data + sz, data);
    }
    return *this;
}

// Move-конструктор: "отбираем" ресурсы у other
MyVector::MyVector(MyVector&& other) noexcept
    : data(other.data), sz(other.sz) {
    other.data = nullptr;
    other.sz = 0;
}

// Move-оператор присваивания
MyVector& MyVector::operator=(MyVector&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        sz = other.sz;
        other.data = nullptr;
        other.sz = 0;
    }
    return *this;
}

int& MyVector::operator[](std::size_t i) { return data[i]; }
const int& MyVector::operator[](std::size_t i) const { return data[i]; }
