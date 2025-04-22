#pragma once
#include <cstddef>
#include <stdexcept>
#include <iterator>

// Шаблонный статический массив фиксированного размера
template<typename T, std::size_t N>
class MyArray {
public:
    // Доступ по индексу с проверкой
    T& operator[](std::size_t i) {
        if (i >= N) throw std::out_of_range("Index out of range");
        return data[i];
    }
    const T& operator[](std::size_t i) const {
        if (i >= N) throw std::out_of_range("Index out of range");
        return data[i];
    }
    constexpr std::size_t size() const noexcept { return N; }

    // Итераторы
    T* begin() noexcept { return data; }
    T* end() noexcept { return data + N; }
    const T* begin() const noexcept { return data; }
    const T* end() const noexcept { return data + N; }

private:
    T data[N];
};
