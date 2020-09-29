#include <iostream>
#include "MyString.h"

int main() {
    String str("Hello World");
    std::cout << "Capacity : " << str.capacity() << std::endl;
    str.Insert(6, "Fucking");
    std::cout << "Capacity : " << str.capacity() << std::endl;
    str.print();

}