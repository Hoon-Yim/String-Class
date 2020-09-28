# String Class with C++
This Repository contains String Class made with C++, the purpose of this Class is just for learning.

## Constructor
```C++
// main function
String str(char c);
String str(const char *str);
String str2 = str; // Deep Copy
```

Deep Copy Constructor is allowed.

Every object except copy constructor have to be explicitly initialized.

## Assign
```C++
// main function
String str("Hello World");
str.print(); // output: Hello World
str.Assign("Assigning has been completely done");
str.print(); // output: Assigning has been completely done
```
Assign function offers not only assigning but also extends its Memory Size.

As you can see code below, this approach is also possible.

```C++
// main function
String str("Hello World Again");
String str2(str);
```

## Reserve
'Reserve' Function allows to extend size of our String.
```C++
// main function
String str("ABCDE");
str.capacity(); // 5

str.reserve(10); 

str.capacity(); // 10
// But the Length of String is still 5
// Capacity and size is totally different
```