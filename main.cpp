#include <iostream>
#include "MyString.h"

int main() {
    String str("Hello World");
    String str2("Hello World");

    if(str.Compare(str2))
        std::cout << "str and str2 is ths same" << std::endl;
}