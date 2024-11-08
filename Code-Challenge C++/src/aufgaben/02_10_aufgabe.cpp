
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

class FooBarAusgabe{
    public:
        FooBarAusgabe(){mutex_b.lock();};
        ~FooBarAusgabe(){mutex_b.unlock();};

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
            mutex_a.lock();
             std::cout << "foo";
            mutex_b.unlock();
        }
        void bar(){
            //todo implementieren Sie hier
            mutex_b.lock();
            std::cout << "bar " << std::endl;
            mutex_a.unlock();
        }
    private:
        std::mutex mutex_a, mutex_b;
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