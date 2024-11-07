
#include <iostream>
#include <thread>
//#include <atomic>
/*or via mutex*/
#include <mutex>

class ZaehlerImpl{
    private:
        //std::atomic<int> zaehler_;
        int zaehler_;
        std::mutex mutex;

    public:
        ZaehlerImpl(){ zaehler_ = 0;};
        ~ZaehlerImpl(){};

        void erhoeheZahler(int zahl){
            // todo implementieren Sie hier eine thread safe erhoehung um zahl /* lol changed to atomic :p */
            mutex.lock();
            zaehler_+=zahl;
            std::cout << "Erhoehe um " << zahl << std::endl;
            mutex.unlock();
        }

        void ausgabeZaehler(){
            std::cout << "Zaehler ist " << zaehler_ << std::endl;
        }
};

int main()
{
    ZaehlerImpl zaehler_impl;

    std::thread t1(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 10);
    std::thread t2(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 1);
    std::thread t3(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 6);
    std::thread t4(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 8);
    std::thread t5(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 4);
    std::thread t6(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 2);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    std::cout << "Zaehler sollte 31 sein." << std::endl;
    zaehler_impl.ausgabeZaehler();

    return 0;
}