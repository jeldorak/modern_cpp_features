#include <iostream>

template<typename... Args>
void printer(Args... args) {
    (std::cout << ... << args);
}

int main() {
    printer(1,2,3,"true", '\t', 'a', '\n');
    return 0;
}
