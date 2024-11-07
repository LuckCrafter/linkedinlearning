#include <iostream>

int g_var = 10;
static int uninit_var;

void someF() {
    int l_var = 20;
    int* heapArray = new int[10];
    std::cout << "g_var: " << g_var << std::endl;
    std::cout << "uninit_var: " << uninit_var << std::endl;
    std::cout << "l_var: " << l_var << std::endl;
    std::cout << "Heap Array: " << heapArray[0] << std::endl;

    delete[] heapArray; // Deallocate mem
}

int main() {
    someF();
    return 0;
}
