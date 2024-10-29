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

struct SimpleList{
    int mNote;
    SimpleList* mNext;

    SimpleList(){
        mNote=0;
    }
    ~SimpleList(){
        mNext=nullptr;
    }
};

SimpleList* list = nullptr;

void addElements(const int value) {
    SimpleList* ptr = new SimpleList;
    ptr->mNote = value;
    ptr->mNext = list;
    list = ptr;
}

void printList() {
    SimpleList* ptr = list;
    while(ptr) {
        std::cout << ptr->mNote << std::endl;
        ptr = ptr->mNext;
    }
}



int main() {
    addElements(12);
    addElements(22);
    addElements(342);
    addElements(145);
    //std::cout << list << " " << list->note << " " << list->next << std::endl;
    printList();

    return 0;
}