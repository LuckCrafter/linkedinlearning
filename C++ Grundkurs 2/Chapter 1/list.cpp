#include <memory>
#include <iostream>

template <typename T>
struct List {
    T m_value;
    std::unique_ptr<List> m_next {nullptr};
};

std::unique_ptr<List<char>> head {nullptr};

template <typename T>
void addElements(T value) {
    auto ptr = std::make_unique<List<T>>();
    ptr -> m_value = value;
    ptr -> m_next = std::move(head);
    head = std::move(ptr);
}

void printList() {
    auto ptr = std::move(head);
    while (ptr) {
        std::cout << ptr->m_value << std::endl;
        ptr = std::move(ptr -> m_next);
    }
}

int main() {
    /*
    addElements(7);
    addElements(21);
    addElements(3);
    */
    addElements('3');
    addElements('W');
    addElements('H');
    printList();
    return 0;
}