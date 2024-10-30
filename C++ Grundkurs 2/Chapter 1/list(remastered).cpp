#include <iostream>
#include <memory>

template<class T>
struct SimpleNode {
    T mItem = 0;
    std::unique_ptr<SimpleNode> mNext {nullptr};
};

template <class T>
struct SimpleLinkedList {

    void add(const T value) {
        auto ptr = std::make_unique< SimpleNode<T> >();
        ptr -> mItem = value;
        ptr -> mNext = std::move(head);
        head = std::move(ptr);
    }

    void print() {
        std::unique_ptr<SimpleNode<T>> ptr = std::move(head);
        while(ptr) {
            std::cout << ptr -> mItem << std::endl;
            ptr = std::move(ptr -> mNext);
        }
    }

    std::unique_ptr< SimpleNode<T> > head {nullptr};

};

int main() {
    SimpleLinkedList<int> ints;
    ints.add(7);
    ints.add(21);
    ints.add(3);
    ints.add(231);
    ints.print();

    /*SimpleLinkedList<std::string> strings;
    strings.add("test");
    strings.add("World");
    strings.add("Hello");
    strings.print();*/

    return 0;
}