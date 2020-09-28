/*
 * File Name: MyString.cpp
 * Last Update: [Sep, 28, 2020]
 */

#include <iostream>
#include "MyString.h"

// Constructor
[[maybe_unused]] String::String(char c) {
    mStrlen = 1;
    mMemCap = 1;
    mString = new char[1];
    mString[0] = c;
}
String::String(const char *str) {
    mStrlen = strlen(str);
    mMemCap = mStrlen;
    mString = new char[mStrlen];

    for(int i = 0; i < mStrlen; i++)
        mString[i] = str[i];
}
String::String(const String &str) {
    mStrlen = str.mStrlen;
    mMemCap = str.mMemCap;
    mString = new char[mStrlen];

    for(int i = 0; i < mStrlen; i++)
        mString[i] = str.mString[i];
}

// Return && Print
int String::GetStrlen() const { return mStrlen; }
int String::capacity() const { return mMemCap; }
char String::at(int location) const {
    if(location < 0 || location > mStrlen)
        return 0;
    else
        return mString[location];
}
void String::print() const {
    for(int i = 0; i < mStrlen; i++)
        std::cout << mString[i];
}
void String::println() const {
    for(int i = 0; i < mStrlen; i++)
        std::cout << mString[i];
    std::cout << std::endl;
}

// Assign
void String::Assign(const String &str) {
    if(mMemCap < str.mStrlen) {
        delete[] mString;
        mMemCap = str.mMemCap;
        mString = new char[str.mMemCap];
    }

    mStrlen = str.mStrlen;
    for(int i = 0; i < mStrlen; i++)
        mString[i] = str.mString[i];
}
void String::Assign(const char *str) {
    int StrLen = strlen(str);
    if(mMemCap < StrLen) {
        delete[] mString;
        mMemCap = StrLen;
        mString = new char[StrLen];
    }

    mStrlen = StrLen;
    for(int i = 0; i < StrLen; i++)
        mString[i] = str[i];
}
// Reserve
void String::Reserve(int size) {
    if(size > mMemCap) {
        char *temp = mString;

        mString = new char[size];
        mMemCap = size;

        for(int i = 0; i < mStrlen; i++)
            mString[i] = temp[i];

        delete[] temp;
    }
    // There's reason to set 'else' part;
    // 'Cause int size has to be larger than previous Memory Capacity;
}


// Destructor
String::~String() {
    delete[] mString;
}