## Description

An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.

### Example: (Input --> Output)

    "Dermatoglyphics" --> true
    "aba" --> false
    "moOse" --> false (ignore letter case)



**Kata's link:** [Isograms](https://www.codewars.com/kata/54ba84be607a92aa900000f1/cpp)

## Best Practices

**First:**
```cpp
#include <cctype>
#include <unordered_set>

bool is_isogram(std::string str)
{
    std::unordered_set<char> char_set;
    for (const auto &c : str) {
        auto c_lower = std::tolower(c);
        if (char_set.count(c_lower) == 0) char_set.insert(c_lower);
        else return false;
    }
    return true;
}
```

**Second:**
```cpp
bool is_isogram(std::string str) {
  for (int i = 0; i < str.length(); i++)
  {
    for (int j = i + 1; j < str.length(); j++)
    {
      if (tolower(str[i]) == tolower(str[j]))
      {
        return false;
      }
    }
  }
  return true;
}
```

## My Solutions
```cpp
#include <ctype.h>

bool is_isogram(std::string str)
{
  bool isogramFlag = true;
  std::string caseRedundancy;
  for (uint i = 0; i < str.length(); i++)
  {
    caseRedundancy = caseRedundancy + char(toupper(str[i]));
  }

  for (uint x = 0; x < caseRedundancy.length(); x++)
  {
    for (uint y = x + 1; y < caseRedundancy.length(); y++)
    {
      if (caseRedundancy[x] == caseRedundancy[y])
      {
        isogramFlag = false;
          break;
      }
    }

    if (isogramFlag == false)
    {
      break;
    }
  }
  return isogramFlag;
}
```
