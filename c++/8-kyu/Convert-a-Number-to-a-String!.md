## Description:

We need a function that can transform a number(integer) into a string.

What ways of achieving this do you know ?

### Examples(input-- > output) :

	123  -- > "123"
	999  -- > "999"
	- 100 -- > "-100"

**Kata's link:** [Convert a Number to a String!](https://www.codewars.com/kata/5265326f5fda8eb1160004c8/cpp)

## Best Practices

**First:**
```cpp
#include <string>

std::string number_to_string(int num) {
  return std::to_string(num);
}
```

**Second:**
```cpp
#include <string>

std::string number_to_string(int num) {
  std::string poo = std::to_string(num);
  return poo;
}
```

## My Solutions
```cpp
#include <string>
#include <sstream>

std::string number_to_string(int num)
{
    std::string str;
    std::stringstream stream;
    stream << num;
    stream >> str;
    return str;
}
```