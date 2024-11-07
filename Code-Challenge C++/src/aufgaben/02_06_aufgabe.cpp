#include <iostream>
#include <vector>

class MaxStack
{

private:
    std::vector<int> list {0};
    std::vector<int> maxs {0};

public:
    MaxStack(){};
    ~MaxStack(){};

    void push(int element)
    {
        // todo implementieren Sie die Push Funtkion
        int _max = (list.back()<element) ? element : list.back();
        maxs.push_back(_max);
        list.push_back(element);
    }

    int pop()
    {
        // todo implementieren Sie die Pop Funktion
        int last_element = list.back();
        list.pop_back();
        maxs.pop_back();
        return last_element;
    }

    int max()
    {
        // todo implementieren Sie die max Funktion
        return maxs.back();
    }
};

int main()
{
    MaxStack max_stack;
    max_stack.push(5);
    max_stack.push(3);
    max_stack.push(7);
    max_stack.push(1);

    std::cout << "Max Element ist " << max_stack.max() << " - richtiges Ergebnis ist 7" << std::endl;

    max_stack.pop();
    max_stack.pop();
    std::cout << "Max Element ist " << max_stack.max() << " - richtiges Ergebnis ist 5" << std::endl;

    return 0;
}