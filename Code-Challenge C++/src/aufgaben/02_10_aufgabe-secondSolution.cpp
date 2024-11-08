
#include <iostream>
#include <thread>
#include <chrono>

class FooBarAusgabe{
    public:
        FooBarAusgabe(){};
        ~FooBarAusgabe(){};

        void runFoo(){
            for(int i = 0; i < 10; i++){
                foo();
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
            }
        }

        void runBar(){
            for(int i = 0; i < 10; i++){
                bar();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }

        void foo(){
            // todo implementieren Sie hier    
            std::cout << "foo";
        }

        void bar(){
            //todo implementieren Sie hier
            std::cout << "bar " << std::endl;
        }
};

int main()
{
    // Aendern Sie hier nichts!!!
    FooBarAusgabe foo_bar_ausgabe;

    std::thread t1(&FooBarAusgabe::runBar, &foo_bar_ausgabe);
    std::thread t2(&FooBarAusgabe::runFoo, &foo_bar_ausgabe);

    t1.join();
    t2.join();

    return 0;
}