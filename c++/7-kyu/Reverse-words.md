## Description:

Complete the function that accepts a string parameter, and reverses each word in the string.All spaces in the string should be retained.

### Examples

    "This is an example!" ==> "sihT si na !elpmaxe"
    "double  spaces" ==> "elbuod  secaps"

**Kata's link:** [Reverse words](https://www.codewars.com/kata/5259b20d6021e9e14c0010d4/cpp)

## Best Practices

**First:**
```cpp
std::string reverse_words(std::string str)
{
  std::string out;
  std::string cword;
  for (char c : str) {
    if (c == ' ') {
      out += cword;
      out += c;
      cword = "";
      continue;
    }
    cword = c + cword;
  }
  out += cword;
  return out;
}
```

**Second:**
```cpp
#include <iostream>
#include <string>
std::string reverse_words(std::string str)
{
    auto begin = str.begin();
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if (*it == ' ')
        {
            auto end = it;
            std::reverse(begin, end);
            begin = it + 1;
        }
    }
    std::reverse(begin, str.end());
    return str;
}
```

## My Solutions
```cpp
#include <string>
#include <algorithm>

std::string reverse_words(std::string str)
{
    int n = str.size(), s = 0, e;
    std::string result(n, '\0');
    for (int index = 0; index <= n; index++)
    {
        if ((str[index] == ' ') || (index == n))
        {
            e = n - index;
            reverse(str.begin() + s, str.end() - e);
            s = index + 1;
        }
    }
    return str;
}
```