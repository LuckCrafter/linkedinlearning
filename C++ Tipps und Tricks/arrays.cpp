#include <iostream>
#include <cstring>

int main() {
    const char* myCharArray = "This is a test";
    const std::string myString = "This is a test";

    // Case 1 strcmp
    std::cout << "Case 1: ";
    if (strcmp(myCharArray,myString.c_str()) == 0)
      std::cout << "Strings are same after reforming\n";
    else
      std::cout << "Strings are diff after reforming\n";
    
    // Case 2 Pointer equalize
    std::cout << "Case 2: ";
    if (myCharArray == myString.data()) // should be wrong (pointer are on diff location)
      std::cout << "Strings are same after reforming\n";
    else
      std::cout << "Strings are diff after reforming\n";

    // Case 3 operator== as std::string
    std::cout << "Case 3: ";
    if(myCharArray == myString) // Achtung Trigger operator== as std::string. Kein Zeigervergleich
      std::cout << "Strings are same after reforming\n";
    else
      std::cout << "Strings are diff after reforming\n";  

    return 0;
}