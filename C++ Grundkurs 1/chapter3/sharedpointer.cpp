#include <iostream>
#include <memory>

struct SimpleNode {
    int mItem = 0;
    std::shared_ptr<SimpleNode> mNext;
};

std::shared_ptr<SimpleNode> list;

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