#include <iostream>

class MaxStack
{

public:
    MaxStack(){};
    ~MaxStack(){};

    void push(int element)
    {
        // todo implementieren Sie die Push Funtkion
    }

    int pop()
    {
        // todo implementieren Sie die Pop Funktion
        int last_element = 0;
        return last_element;
    }

    int max()
    {
        // todo implementieren Sie die max Funktion
        int max_element = 0;
        return max_element;
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