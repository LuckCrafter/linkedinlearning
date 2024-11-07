
#include <iostream>
#include <thread>

class BrotBauer{

    public:
        BrotBauer(){};
        ~BrotBauer(){};

        void runBrot(){
            for(int i = 0; i < 10; i++){
                brot();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }

        void runKaese(){
            for(int i = 0; i < 10; i++){
                kaese();
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        }

        void brot(){
            // todo implementieren Sie hier die synchronisation
             std::cout << "Brot";
        }

        void kaese(){
            // todo implementieren Sie hier die synchronisation
            std::cout << "Kaese";
        }
};

int main()
{
    BrotBauer brot_bauer;

    std::thread t1(&BrotBauer::runKaese, &brot_bauer);
    std::thread t2(&BrotBauer::runBrot, &brot_bauer);
    std::thread t3(&BrotBauer::runBrot, &brot_bauer);
    std::thread t4(&BrotBauer::runKaese, &brot_bauer);
    std::thread t5(&BrotBauer::runBrot, &brot_bauer);
    std::thread t6(&BrotBauer::runBrot, &brot_bauer);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    return 0;
}