
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

class FooBarAusgabe
{
private:
    std::atomic<int> zaehler_;
    std::mutex zaehler_mutex_;
    std::condition_variable zaehler_condition_;

public:
    FooBarAusgabe() { zaehler_ = 0; };
    ~FooBarAusgabe(){};

    void runFoo()
    {
        for (int i = 0; i < 10; i++)
        {
            foo();
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }

    void runBar()
    {
        for (int i = 0; i < 10; i++)
        {
            bar();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    void foo()
    {
        std::unique_lock<std::mutex> lock{zaehler_mutex_};
        if (zaehler_ % 2 != 0)
            zaehler_condition_.wait(lock);

        std::cout << "foo";
        zaehler_++;
        zaehler_condition_.notify_one();
    }
    void bar()
    {
        std::unique_lock<std::mutex> lock{zaehler_mutex_};
        if (zaehler_ % 2 == 0)
            zaehler_condition_.wait(lock);

        std::cout << "bar " << std::endl;
        zaehler_++;
        zaehler_condition_.notify_one();
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