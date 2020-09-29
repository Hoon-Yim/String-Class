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
    [[nodiscard]] int length() const;
    [[nodiscard]] char at(int location) const;
    [[nodiscard]] int capacity() const;
    void print() const;
    void println() const;

    // Assign
    String& Assign(const String &str);
    String& Assign(const char *str);
    // Reserve
    String& Reserve(int size);
    // Insert
    String& Insert(int loc, const String &str);
    String& Insert(int loc, const char *str);
    String& Insert(int loc, char c);
    // Compare
    int Compare(const String &str) const;

    // Destructor
    ~String();
};

#endif //MY_OWN_STRING_MYSTRING_H
