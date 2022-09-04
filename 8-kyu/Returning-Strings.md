## Description:

Make a function that will return a greeting statement that uses an input; your program should return, `"Hello, <name> how are you doing today?"`.

[Make sure you type the exact thing I wrote or the program may not execute properly]

**Kata's link:** [Returning Strings](https://www.codewars.com/kata/55a70521798b14d4750000a4/cpp)

## Best Practices

**First:**
```cpp
std::string greet(const std::string& n) {return "Hello, " + n + " how are you doing today?";}
```

**Second:**
```cpp
#include <string>

std::string greet(const std::string& n) {
  return "Hello, " + n + " how are you doing today?";
}
```

## My Solutions
```cpp
#include <string>

std::string greet(const std::string& n)
{
	return "Hello, " + n + " how are you doing today?";
}
```