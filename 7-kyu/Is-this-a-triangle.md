## Description:

Implement a function that accepts 3 integer values a, b, c.The function should return true if a triangle can be built with the sides of given length and false in any other case.

(In this case, all triangles must have surface greater than 0 to be accepted).

>You can think of the triangle as having the side lengths a, b, and c and the theorem being an inequality, which states: a+b > c, a+c > b, and b+c > a

**Kata's link:** [Is this a triangle](https://www.codewars.com/kata/56606694ec01347ce800001b/cpp)

## Best Practices

**First:**
```cpp
namespace Triangle
{
  bool isTriangle(int a, int b, int c)
  {
    return a-b<c && b-c<a && c-a<b;
  }
};
```

**Second:**
```cpp
namespace Triangle
{
  bool isTriangle(long a, long b, long c)
  {
    if (a > 0 && b > 0 && c > 0)
    {
        long max = std::max(std::max(a, b), c);
        return (a + b + c) - max > max;
    }
    return false;
  }
};
```

## My Solutions
```cpp
namespace Triangle
{
    bool isTriangle(int a, int b, int c)
    {
        if (a <= 0 || b <= 0 || c <= 0) return false;

        if ((long)a + b > c && (long)a + c > b && (long)b + c > a) 
            return true;
        else 
            return false;
    }
};
```