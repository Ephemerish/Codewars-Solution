## Description:

If you can't sleep, just count sheep!!

### Task :

Given a non - negative integer, `3`for example, return a string with a murmur : `"1 sheep...2 sheep...3 sheep..."`.Input will always be valid, i.e.no negative integers.

**Kata's link:** [If you can't sleep, just count sheep!!](https://www.codewars.com/kata/5b077ebdaf15be5c7f000077/cpp)

## Best Practices

**First:**
```cpp
#include <string>

std::string countSheep(int number) {
  std::string res = "";
  for (int i = 1; i <= number; ++i) 
    res += std::to_string(i) + " sheep...";
  return res;
}
```

**Second:**
```cpp
#include <sstream>
#include <string>

std::string countSheep(int n) {
  std::stringstream ss;
  for (int i = 1; i <= n; i++) {
    ss << i << " sheep...";
  }
  return ss.str();
}
```

## My Solutions
```cpp
#include <string>

std::string countSheep(int number) {
    std::string murmur;
    for (int sheep = 1; sheep <= number; sheep++)
    {
        murmur += std::to_string(sheep) + " sheep...";
    }
    return murmur;
}
```