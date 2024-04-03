#include <iostream>
#include <string>

int main() {
    std::string text;
    while (std::getline(std::cin, text)) {
        std::cout << "\033[36m" << text << "\033[0m" << std::endl;
    }
}