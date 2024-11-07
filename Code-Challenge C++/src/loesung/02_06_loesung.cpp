#include <iostream>
#include <list>

class MaxStack
{
private:
    std::list<int> stack;
    std::list<int> maxes;

public:
    MaxStack(){};
    ~MaxStack(){};

    void push(int element)
    {
        stack.push_back(element);
        maxes.push_back(std::max(element, maxes.back()));
    }

    int pop()
    {
        int last_element = maxes.back();
        stack.pop_back();
        maxes.pop_back();

        return last_element;
    }

    int max()
    {
        int max_element = maxes.back();
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