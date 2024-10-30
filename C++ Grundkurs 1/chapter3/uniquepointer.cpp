#include <iostream>
#include <memory>

/*
    Prefix for Class/Structures

    m for members
    c for constants/readonlys
    p for pointer (and pp for pointer to pointer)
    v for volatile
    s for static
    i for indexes and iterators
    e for events
*/

struct List {
    int m_value;
    std::unique_ptr<List> m_next;
    List() {
        m_next=nullptr;
        m_value = 0;
    }
};

/*
Or Short
struct List {
    int m_value {0};
    std::unique_ptr<List> m_next {nullptr};
};
*/

std::unique_ptr<List> head = nullptr;

void addElements(const int val) {
    std::unique_ptr<List> ptr = std::make_unique<List>();
    ptr -> m_value = val;
    ptr -> m_next = std::move(head);
    head = std::move(ptr);
}

void printList() {
    std::unique_ptr<List> ptr = std::move(head);
    while (ptr) {
        std::cout << ptr -> m_value << std::endl;
        ptr = std::move(ptr -> m_next);
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