## Description:

Welcome.In this kata, you are asked to square every digit of a numberand concatenate them.

### For example
    if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1.

Note : The function accepts an integer and returns an integer

**Kata's link:** [Square Every Digit](https://www.codewars.com/kata/546e2562b03326a88e000020/cpp)

## Best Practices

**First:**
```cpp

```

**Second:**
```cpp

```

## My Solutions
```cpp
int square_digits(int num)
{
    int concatenate = 0;

    for (int temp, factor = 1; num != 0; factor *= 10)
    {
        temp = num % 10;
        num /= 10;
        concatenate += (temp * temp * factor);
        if (temp > 3)
            factor *= 10;
    }

    return concatenate;
}