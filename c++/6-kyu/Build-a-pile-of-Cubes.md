## Description

Your task is to construct a building which will be a pile of n cubes. The cube at the bottom will have a volume of `n^3`, the cube above will have volume of `(n-1)^3` and so on until the top which will have a volume of `1^3`.

You are given the total volume m of the building. Being given m can you find the number n of cubes you will have to build?

The parameter of the function findNb (find_nb, find-nb, findNb, ...) will be an integer m and you have to return the integer n such as `n^3 + (n-1)^3 + ... + 1^3 = m` if such a n exists or `-1`if there is no such n.

### Examples:

    findNb(1071225) --> 45

    findNb(91716553919377) --> -1


**Kata's link:** [Build a pile of Cubes](https://www.codewars.com/kata/5592e3bd57b64d00f3000047/cpp)

## Best Practices

**First:**
```cpp
class ASum
{
  public:
  static long long findNb(long long m)
  {
      long long i = 1;
      long long sum = 0;
      do {
          sum += i * i * i;
          if (m == sum) return i;
          i++;
      } while (sum < m);
      return -1;
  }
};
```

**Second:**
```cpp
#include <cmath>

class ASum
{
  public:
  static long long findNb(long long m) {
    // 1^3 + 2^3 + ... n^3 = [n*(n+1)/2] ^2 = m
    // => n = (1 + sqrt(1 + 8 * sqrt(m))) / 2
    auto sqrt_m = (long long)std::sqrt(m);
    if (sqrt_m * sqrt_m != m)
      return -1;
    
    auto det = 1 +  8 * sqrt_m;
    auto sqrt_det = (long long)std::sqrt(det);
    if (sqrt_det * sqrt_det != det)
      return -1;
    
    if (sqrt_det % 2 == 0)
      return -1;
    return (1 + sqrt_det) / 2 - 1;
  }
};
```

## My Solutions
```cpp
class ASum
{
  public:
  static long long findNb(long long m);
};

long long ASum::findNb(long long m)
{
  long long total = 0;
  long long n = 0;
  
  while(total < m)
  {
    n++;
    total += n*n*n;
  }
  
  return (total == m) ? n : -1;
}
```
