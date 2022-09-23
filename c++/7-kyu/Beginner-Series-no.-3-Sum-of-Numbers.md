## Description:

Given two integers `a` and `b`, which can be positive or negative, find the sum of all the integers betweenand including themand return it.If the two numbers are equal return `a` or `b`.

Note : `a` and `b` are not ordered!
Examples(a, b)-- > output(explanation)

    (1, 0)-- > 1 (1 + 0 = 1)
    (1, 2)-- > 3 (1 + 2 = 3)
    (0, 1)-- > 1 (0 + 1 = 1)
    (1, 1)-- > 1 (1 since both are same)
    (-1, 0)-- > -1 (-1 + 0 = -1)
    (-1, 2)-- > 2 (-1 + 0 + 1 + 2 = 2)

**Kata's link:** [Beginner Series no. 3 Sum of Numbers](https://www.codewars.com/kata/55f2b110f61eb01779000053/cpp)

## Best Practices

**First:**
```cpp
int get_sum(int a, int b)
{
  int n = (a < b ? b - a : a - b) + 1;
  return n *(a + b)/ 2;
}
```

**Second:**
```cpp
int get_sum(int a, int b)
{
  return (a + b) * (std::abs(a - b) + 1) / 2;
}
```

## My Solutions
```cpp
int get_sum(int a, int b)
{
    int start, end, sum;
    a < b ? (start = a, end = b) : (start = b, end = a);

    for (sum = 0; start <= end; start++)
        sum += start;

    return sum;
}
```