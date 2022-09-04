## Description:

Complete the solution so that it reverses the string passed into it.

    'world' = > 'dlrow'
    'word' = > 'drow'

**Kata's link:** [Reversed Strings](https://www.codewars.com/kata/5168bb5dfe9a00b126000018/cpp)

## Best Practices

**First:**
```cpp
#include <algorithm>
#include <string>

std::string reverseString(const std::string& str) {
  return std::string(str.rbegin(), str.rend());
}
```

**Second:**
```cpp
#include <algorithm>
#include <string>

std::string reverseString(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}
```

## My Solutions
```cpp
#include <iostream>
#include <string>

std::string reverseString(std::string string)
{

    std::string stringReverse = string;

    for (int x = 0, len = string.length(); x < len; x++)
    {
        stringReverse[len - x - 1] = string[x];
    }

    std::cout << stringReverse;

    return stringReverse;
}
```