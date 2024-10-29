#include <iostream>
#include <memory>

struct SimpleList{
    int note;
    SimpleList* next;

    SimpleList(){
        note=0;
    }
};

SimpleList* list = nullptr;

void addElements(const int value) {
    SimpleList* ptr = new SimpleList;
    ptr->note = value;
    ptr->next = list;
    list = ptr;
}

void printList() {
    SimpleList* ptr = list;
    while(ptr) {
        std::cout << ptr->note << std::endl;
        ptr = ptr->next;
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
