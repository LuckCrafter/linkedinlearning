#include <iostream>
#include <string>
#include <set>

int main() {
    std::set<std::string> names;

    // dopplungwerden nicht abgespeichert

    names.insert("John");
    names.insert("Josh");
    names.insert("Steve");
    names.insert("Alex");
    names.insert("John");
    names.insert("Jeff");

    // Warum funktioniert beides?
    std::cout << "Names:\n";
    for (const auto e : names) std::cout << e << std::endl;
    std::cout << "Names Ref:\n";
    for (const auto &e : names) std::cout << e << std::endl;
}