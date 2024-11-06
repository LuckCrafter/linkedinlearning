#include <fstream>
#include <iostream>

int tryOpenFile() {
    std::ifstream file("AFileThatDontExist.txt");
    if(!file) {
        std::cout << "File: AFileThatDontExist.txt could not be opened\n";
        return 1;
    }
    
    for (int n; file >> n;)std::cout << n << ' ';
    std::cout << std::endl;

    if(file.bad()) {
        std::cout << "I/O err while reading\n";
        return 4;
    }
    if(file.eof()) {
        std::cout << "End of file reached successfully\n";
        return 3;
    }
    if(file.fail()) {
        std::cout << "Non-integer data encountered\n";
        return 2;
    }

    return 0;
}

int main() {
    int code {tryOpenFile()};
    if(code != 0) {
        std::cout << "Err, try to read file. Code: " << code << std::endl;
        return 1;
    }

    return 0;
}