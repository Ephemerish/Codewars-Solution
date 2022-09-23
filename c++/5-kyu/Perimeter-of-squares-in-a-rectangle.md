## Description

The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 5, 8. It's easy to see that the sum of the perimeters of these squares is : `4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80` 

Could you give the sum of the perimeters of all the squares in a rectangle when there are n + 1 squares disposed in the same manner as in the drawing:

![Fibonacci sequence](https://i.imgur.com/EYcuB1wm.jpg)

### Hint: 

See Fibonacci sequence

### Ref: 
http://oeis.org/A000045

The function perimeter has for parameter n where n + 1 is the number of squares (they are numbered from 0 to n) and returns the total perimeter of all the squares.

    perimeter(5)  should return 80
    perimeter(7)  should return 216



**Kata's link:** [Perimeter of squares in a rectangle](https://www.codewars.com/kata/559a28007caad2ac4e000083/cpp)

## Best Practices

**First:**
```cpp
typedef unsigned long long ull;
class SumFct
{
public:
  static ull perimeter(int n) {
    ull n0 = 1;
    ull n1 = 1;
    ull result = n==0?1:2;
    for (int i=2;i<=n;i++) {
      n1 = n0+n1;
      n0 = n1-n0;
      result += n1;
    }
    return result*4;
  }
};
```

**Second:**
```cpp
#include <cmath>
typedef unsigned long long ull;
class SumFct
{
  public:
  static ull perimeter(int n) {
    return (4 * round((((std::pow(1.6180339887498948482045868343656381177203091798058L, n + 3) - std::pow(-0.6180339887498948482045868343656381177203091798058L, (n + 3))) / sqrt(5))) - 1));
  }
};
```

## My Solutions
```cpp
typedef unsigned long long ull;
class SumFct
{
  public:
  static ull perimeter(int n);
};

ull SumFct::perimeter(int n)
  {
    n += 1;
    std::vector<long> fibonacci;
    long sum = 0;
    long result = 0;
    if(n != 0)
    {
      fibonacci.reserve(n);
      for(int i = 0; i < n; i++)
      {
        if(i < 2)
          fibonacci.emplace_back(1); 
        else 
          fibonacci.emplace_back( fibonacci[i-2] + fibonacci[i-1] );
    }
      for(unsigned long i = 0; i < fibonacci.size(); i++)
      {
        sum += fibonacci[i];
      }
   }
    result = sum * 4;
    return result;
  }
```
