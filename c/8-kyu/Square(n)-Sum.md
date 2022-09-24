## Description:

Complete the square sum function so that it squares each number passed into it and then sums the results together.

For example, for `[1, 2, 2]` it should return `9` because `1^2 + 2^2 + 2^2 = 9`.


**Kata's link:** [Square(n) Sum](https://www.codewars.com/kata/515e271a311df0350d00000f)

## Best Practices

**First:**
```cpp
#include <stddef.h>

int square_sum(const int *values, size_t count){
  int sum = 0;
  for (int i = 0; i < count; i++)
    sum += (values[i])*(values[i]);
  return sum;
};
```

**Second:**
```cpp
#include <stddef.h>
#include <math.h>
int square_sum(const int *values, size_t count)
{
  int result = 0;
  for(int i= 0;i< count;i++)
  {
    result += pow(*(values+i),2);
  }
  return result;
}
```

## My Solutions
```cpp
#include <stddef.h>

int square_sum(const int *values, size_t count)
{
  int result = 0;
  
  for(size_t i = 0; i < count; i++)
  {
    result += values[i] * values[i];
  }
  
  return result;
}
```