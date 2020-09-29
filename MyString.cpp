/*
 * File Name: MyString.cpp
 * Last Update: [Sep, 28, 2020]
 */

#include <iostream>
#include "MyString.h"

// Constructor
String::String(char c) {
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
int String::length() const { return mStrlen; }
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
String& String::Assign(const String &str) {
    if(mMemCap < str.mStrlen) {
        delete[] mString;
        mMemCap = str.mMemCap;
        mString = new char[str.mMemCap];
    }

    mStrlen = str.mStrlen;
    for(int i = 0; i < mStrlen; i++)
        mString[i] = str.mString[i];

    return *this;
}
String& String::Assign(const char *str) {
    String temp(str);
    return Assign(temp);
}
// Reserve
String& String::Reserve(int size) {
    if(size > mMemCap) {
        char *temp = mString;

        mString = new char[size];
        mMemCap = size;

        for(int i = 0; i < mStrlen; i++)
            mString[i] = temp[i];

        delete[] temp;
        return *this;
    }
    // There's reason to set 'else' part;
    // 'Cause int size has to be larger than previous Memory Capacity;
}
// Insert
String& String::Insert(int loc, const String &str) {
    if(loc < 0 || loc > mStrlen)
        return *this;

    if(mStrlen + str.mStrlen > mMemCap) {
        // initialize Capacity
        if(mStrlen + str.mStrlen < mMemCap * 2)
            mMemCap *= 2;
        else
            mMemCap = mStrlen + str.mStrlen;

        // save previous Content of String
        // and reallocate memory
        char *temp = mString;
        mString = new char[mMemCap];


        int i;
        for(i = 0; i < loc; i++) // Saving Content right before location
            mString[i] = temp[i];

        for(int j = 0; j < str.mStrlen; j++) // Inserting
            mString[j + loc] = str.mString[j];

        for(; i < mStrlen + str.mStrlen; i++) // Adding remaining elements of string
            mString[i + str.mStrlen] = temp[i];

        delete[] temp;
        mStrlen += str.mStrlen;
        return *this;
   }

    // if Capacity is enough to insert
    // it does not have to adjust Capacity

    // For loop down below, push elements of string back
    for(int i = mStrlen - 1; i >= loc; i--)
        mString[i + str.mStrlen] = mString[i];

    for(int i = 0; i < str.mStrlen; i++)
        mString[i + loc] = str.mString[i];

    mStrlen += str.mStrlen;
    return *this;
}
String& String::Insert(int loc, const char *str) {
    String temp(str);
    return Insert(loc, temp);
}
String& String::Insert(int loc, char c) {
    String temp(c);
    return Insert(loc, temp);
}
// Compare
int String::Compare(const String &str) const {
    if(mStrlen != str.mStrlen)
        return 0;

    for(int i = 0; i < mStrlen; i++) {
        if(mString[i] != str.mString[i])
            return 0;
    }

    return 1;
}
// Destructor
String::~String() {
    delete[] mString;
}