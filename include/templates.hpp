#pragma once
#include <sstream>
#include <iterator>
#include <string>
#include <type_traits>

// Универсальная функция swap на основе шаблона
template<typename T>
void mySwap(T& a, T& b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

// Преобразование любого контейнера в строку вида "{elem1, elem2, ...}"
template<typename Container>
std::string container_to_string(const Container& c) {
    std::ostringstream oss;
    oss << "{ ";
    auto it = std::begin(c);
    while (it != std::end(c)) {
        oss << *it;
        ++it;
        if (it != std::end(c))
            oss << ", ";
    }
    oss << " }";
    return oss.str();
}
