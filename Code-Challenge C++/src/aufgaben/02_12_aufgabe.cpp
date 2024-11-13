
#include <iostream>

class Tier
{
protected:
    int m_alter;
public:
    Tier(){m_alter = 10;};
    virtual ~Tier(){};

    void ausgabeTier() { std::cout << "Ich bin ein Tier." << std::endl; }

    virtual void machGerausch() = 0;
    virtual int getAlter() {return m_alter;}
};

class Maus : public Tier {
public:
    void machGerausch() override {
        std::cout << "pieps.\n";
    }
};
class Hund : public Tier {
public:
    void machGerausch() override {
        std::cout << "wuff.\n";
    }
};
class Katze : public Tier {
public:
    void virtual machGerausch() override {
        std::cout << "miau.\n";
    }
};

int main()
{
    

    {
        Maus obj;
        std::cout << obj.getAlter();
        obj.machGerausch();
    }
    {
        Hund obj;
        std::cout << obj.getAlter();
        obj.machGerausch();
    }
    {
        Katze obj;
        std::cout << obj.getAlter();
        obj.machGerausch();
    }
    return 0;
}