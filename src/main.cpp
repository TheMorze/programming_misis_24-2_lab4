#include "MyVector.hpp"
#include "templates.hpp"
#include "MyArray.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <string>

int main() {
    using Clock = std::chrono::high_resolution_clock;
    const std::size_t N = 1'000'000;

    // Создаём большой вектор
    MyVector v1(N);
    for (std::size_t i = 0; i < N; ++i) v1[i] = static_cast<int>(i);

    // Замер копирования
    auto t1 = Clock::now();
    MyVector v2 = v1;
    auto t2 = Clock::now();
    // Замер перемещения
    MyVector v3 = std::move(v1);
    auto t3 = Clock::now();

    auto copy_ms = std::chrono::duration<double, std::milli>(t2 - t1).count();
    auto move_ms = std::chrono::duration<double, std::milli>(t3 - t2).count();

    std::cout << "Copy time: " << copy_ms << " ms\n";
    std::cout << "Move time: " << move_ms << " ms\n\n";

    // Демонстрация mySwap
    int a = 5, b = 10;
    std::cout << "Before swap: a=" << a << ", b=" << b << "\n";
    mySwap(a, b);
    std::cout << "After swap:  a=" << a << ", b=" << b << "\n\n";

    // Демонстрация container_to_string
    std::vector<std::string> vs = {"one","two","three"};
    std::list<int> li = {1,2,3,4};
    std::set<char> sc = {'a','b','c'};

    std::cout << "Vector<string>: " << container_to_string(vs) << "\n";
    std::cout << "List<int>: "     << container_to_string(li) << "\n";
    std::cout << "Set<char>: "     << container_to_string(sc) << "\n\n";

    // Демонстрация MyArray
    MyArray<std::string, 5> arr;
    arr[0] = "Alice";
    arr[1] = "Bob";
    arr[2] = "Carol";
    arr[3] = "Dave";
    arr[4] = "Eve";

    std::cout << "MyArray<string,5>: ";
    for (auto& s : arr) std::cout << s << " ";
    std::cout << "\n";

    return 0;
}
