# String Class with C++
This Repository contains String Class made with C++, <br /> the purpose of this Class is just for learning.

[Reference](https://modoocode.com/198) <- Korean C++ Tutorial
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
str.print(); // Hello World Again

str.Assign("Not Hello World");
str.print(); // Not Hello World
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

The reason for the existence of 'Capacity' is for minimal memory allocation. <br />
It could reduce time wasting for allocating. <br />
If the Capacity is too big to contain new String, it does not have to reallocate the size of the memory.