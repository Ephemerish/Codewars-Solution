## Description:

Create a function that takes an integer as an argumentand returns `"Even"` for even numbers or `"Odd"` for odd numbers.

**Kata's link:** [Even or Odd](https://www.codewars.com/kata/53da3dbb4a5168369a0000fe/cpp)

## Best Practices

**First:**
```cpp
std::string even_or_odd(int num) 
{
  return (num%2==0)?"Even":"Odd";
}
```

**Second:**
```cpp
std::string even_or_odd(int number) 
{
  return number % 2 == 0 ? "Even" : "Odd";
}
```

## My Solutions
```cpp
#include <string>

std::string even_or_odd(int number)
{
	return number % 2 ? "Odd" : "Even";
}
```