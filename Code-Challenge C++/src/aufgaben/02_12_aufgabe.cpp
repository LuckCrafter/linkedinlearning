
#include <iostream>

class Tier
{
public:
    Tier(){};
    virtual ~Tier(){};

    void ausgabeTier() { std::cout << "Ich bin ein Tier." << std::endl; }

    virtual void machGerausch() = 0;
};

int main()
{

    return 0;
}