/*
 * File Name: MyString.h
 * Last Update: [Sep, 28, 2020]
 */

#ifndef MY_OWN_STRING_MYSTRING_H
#define MY_OWN_STRING_MYSTRING_H

class String {
private:
    char *mString;
    int mStrlen;
    int mMemCap;

public:
    // Constructor
    [[maybe_unused]] explicit String(char c);
    explicit String(const char *str);
    String(const String &str);

    // Return && Print
    [[nodiscard]] int GetStrlen() const;
    [[nodiscard]] char at(int location) const;
    [[nodiscard]] int capacity() const;
    void print() const;
    void println() const;

    // Assign
    void Assign(const String &str);
    void Assign(const char *str);
    // Reserve
    void Reserve(int size);

    // Destructor
    ~String();
};

#endif //MY_OWN_STRING_MYSTRING_H
