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

struct SimpleNode {
    int mItem;
    std::shared_ptr<SimpleNode> mNext;
    SimpleNode(){
        mItem = 0;
    }
};

std::shared_ptr<SimpleNode> list {nullptr};

void addElements(const int value) {
    auto ptr = std::make_shared<SimpleNode>();
    ptr->mItem = value;
    ptr->mNext = list;
    list = ptr;
}

void printList() {
    std::shared_ptr<SimpleNode> ptr = list;
    while (ptr) {
        printf("%i\n",ptr->mItem);
        ptr = ptr->mNext;
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