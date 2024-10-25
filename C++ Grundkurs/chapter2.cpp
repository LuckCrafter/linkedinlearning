#include <iostream>
#include <fstream>
#include <array>

const int numRows = 4;
const int numCols = 4;

std::array< std::array<float,numCols>,numRows> matrix;

int main() {
    std::ifstream file("numbers.csv");
    if (!file.is_open()) {
        printf("Cann\'t open the file\n");
        return 1;
    }
    float numbers[numRows][numCols] {0};
    int a {0};
    int b {0};
    std::string str;
    while (getline(file, str,' ')) {
        numbers[a][b]=(float) atof(str.c_str());
        a==a+1%numRows;
        if(a==0) ++b;
    }
    file.close();
    
    float sumR[4] {0};
    float sumC[4] {0};

    for (int i=0;i<4;++i) {
        for (int j=0;j<4;++j) {
            sumR[i]+=numbers[i][j];
            sumC[i]+=numbers[j][i];
        }
    }

    for (int i=0;i<4;++i) {
        printf("Row %i has a sum of %f\n",i,sumR[i]);
        printf("Col %i has a sum of %f\n\n",i,sumC[i]);
    }

    for (int i=0;i<16;++i) {
        std::cout << numbers[i/4][i%4] << std::endl;
    }
}