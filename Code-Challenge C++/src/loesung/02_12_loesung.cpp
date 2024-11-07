
#include <iostream>

class Tier
{
protected:
    int alter_;

public:
    Tier() { alter_ = 10; };
    virtual ~Tier(){};

    void ausgabeTier() { std::cout << "Ich bin ein Tier." << std::endl; }

    virtual void machGerausch() = 0;
};

class Tiger : public Tier
{
public:
    Tiger():Tier() {}
    virtual ~Tiger() {}

    void machGerausch()
    {
        std::cout << "Roarrrr..." << std::endl;
    }

    int nenneAlter(){
        return alter_;
    }
};

class Elefant : public Tier
{
public:
    Elefant():Tier() {}
    virtual ~Elefant() {}

    void machGerausch()
    {
        std::cout << "Tatuuuu..." << std::endl;
    }

    int nenneAlter(){
        return alter_;
    }
};

class Wolf : public Tier
{
public:
    Wolf():Tier() {}
    virtual ~Wolf() {}

    void machGerausch()
    {
        std::cout << "Jaulll..." << std::endl;
    }

    int nenneAlter(){
        return alter_;
    }
};

int main()
{
    Tiger tiger;
    tiger.machGerausch();
    std::cout << "Alter des Tigers " << tiger.nenneAlter() << std::endl;

    Wolf wolf;
    wolf.machGerausch();

    Elefant elefant;
    elefant.machGerausch();

    return 0;
}