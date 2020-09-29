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

## Insert
```C++
// main function
String str("Hello World");
str.capacity(); // 11

str.Insert(6, "to this ");
str.capacity(); // 11 + 8

str.print(); // output: Hello to this World

----------------------------------------------

String str("Hello World");
str.capacity(); // 11
str.Reverse(20); // 20

str.Insert(6, "to this ");
str.capacity(); // 20 because the capacity is already enough to insert "to this"

str.print(); // output: Hello to this World
```
This function literally allows to insert a string. <br />
If capacity is not enough to insert, <br />
it will automatically extend its capacity by length of string.

## Compare
```C++
String str("Hello World");
String str2("Hello World");

if(str.Compare(str2))
    std::cout << "str and str2 is ths same" << std::endl;
```

If both strings are the same, it will return 1 which is TRUE value. <br />
Or not, it is going to return 0 which is FALSE value.
