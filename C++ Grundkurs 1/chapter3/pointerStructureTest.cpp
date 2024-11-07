#include <iostream>
//#include <memory>

struct MyVector {
    int mNum;
    int *mValues = nullptr; 
};

int main(){
    auto pMyVector = new MyVector;
    pMyVector->mNum=5;
    pMyVector->mValues=new int[pMyVector->mNum];

    for (int i {0}; i<pMyVector->mNum;++i) {
        pMyVector->mValues[i]=i;
    }

    for (int i {0}; i<pMyVector->mNum;++i) {
        std::cout << pMyVector->mValues[i] << std::endl;
    }
}