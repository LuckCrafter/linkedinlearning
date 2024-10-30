#include <iostream>
#include <functional>

// old variant
int diff(const int a, const int b){return a-b;}
int sum(const int a, const int b){return a+b;}

void mainOld() {
    int x = 3;
    int y = 3;
    int z = 30;
    int result;

    int (*operate)(int,int);

    operate = &sum;
    result = operate(30,3);
    std::cout << result << std::endl;

    operate = &diff;
    result = operate(30,3);
    std::cout << result << std::endl;
}

// new variant
void mainNew() {
    int x = 3;
    int y = 3;
    int z = 30;
    int result;

    std::function<int(int,int)> calc;
    auto applySum = [](const int a, const int b) -> int { return a+b; };
    auto diffSum = [](const int a, const int b) -> int { return a-b; };

    calc = applySum;
    result = calc(30,3);
    std::cout << result << std::endl;

    calc = diffSum;
    result = calc(30,3);
    std::cout << result << std::endl;
}

int main(){
    mainNew();
    return 0;
}