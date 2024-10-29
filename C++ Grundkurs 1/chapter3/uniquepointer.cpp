#include <iostream>
#include <memory>

struct List {
    int value;
    std::unique_ptr<List> next;
};

std::unique_ptr<List> head = nullptr;

void addElements(const int val) {
    std::unique_ptr<List> ptr = std::make_unique<List>();
    ptr -> value = val;
    ptr -> next = std::move(head);
    head = std::move(ptr);
}

void printList() {
    std::unique_ptr<List> ptr = std::move(head);
    while (ptr) {
        std::cout << ptr -> value << std::endl;
        ptr = std::move(ptr -> next);
    }
}

int main() {
    addElements(12);
    addElements(22);
    addElements(342);
    addElements(145);

    printList();
    return 0;
}