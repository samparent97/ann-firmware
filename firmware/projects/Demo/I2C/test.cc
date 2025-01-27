#include <format>
#include <iostream>

int main() {
    int number = 42;
    std::string text = "test";

    auto formatted = std::format("Number: {}, Text: {}", number, text);
    std::cout << formatted << std::endl;

    return 0;
}