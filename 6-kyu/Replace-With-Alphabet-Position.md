## Description

Welcome.

In this kata you are required to, given a string, replace every letter with its position in the alphabet.

If anything in the text isn't a letter, ignore it and don't return it.

"a" = 1, "b" = 2, etc.

Example

```cpp
alphabet_position("The sunset sets at twelve o' clock.")

Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" ( as a string )
```

**Kata's link:** [Replace With Alphabet Position](https://www.codewars.com/kata/546f922b54af40e1e90001da/cpp)

## Best Practices

**First:**
```cpp
#include <string>
#include <string.h>

std::string alphabet_position(const std::string& text) {
  const char* c_str = text.c_str();
  std::string result;
  for (int i = 0; i < (int)strlen(c_str); i++) {
    if (isalpha(c_str[i])) {
      if (result != "")
        result += " ";
      result += std::to_string((int)tolower(c_str[i]) - 96);
    }
  }
  return result;
}
```

**Second:**
```cpp
#include <cctype>
#include <sstream>
#include <string>

std::string alphabet_position(const std::string &s) {
  std::stringstream ss;
  for (auto &x : s) if (std::isalpha(x)) ss << (x | 32) - 96 << ' ';
  std::string r = ss.str();
  if (r.size()) r.pop_back();
  return r;
}
```

## My Solutions
```cpp
#include <string>

std::string alphabet_position(const std::string& text)
{
  std::string result;
  for (unsigned long i = 0; i < text.size(); i++)
  {
    if (text[i] != ' ')
    {
      if (text[i] > 96 && text[i] < 123)
      {
        result += std::to_string(text[i] - 96);
        result += ' ';
      }
      else if (text[i] > 64 && text[i] < 91)
      {
        result += std::to_string(text[i] - 64);
        result += ' ';
      }
    }
    if (i + 1 == text.size())
      if (!result.empty())
        result.pop_back();
  }
  return result;
}
```
