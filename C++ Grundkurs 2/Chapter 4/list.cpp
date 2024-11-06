#include <iostream>
#include <list>

int main() {

    // verkette liste (beidseitig verkettet (nach vorne und hinten))
      // nicht wie in Chapter 1, list(remastered)
    std::list<int> myRange;

    for (int i {0}; i<7; ++i) myRange.push_front(i);
    for (int i {0}; i<7; ++i) myRange.push_back(100+i);
    for (int i {0}; i<7; ++i) myRange.push_front(200+i);
    {
        auto it = myRange.end();
        it--;
        myRange.insert(it,500);

        it--;it--;

        it = myRange.erase(it);

        it--;

        myRange.erase(it);
    }

    std::cout << "myRange :" << std::endl;
    for(const auto e : myRange) std::cout << e << std::endl;
    return 0;
}