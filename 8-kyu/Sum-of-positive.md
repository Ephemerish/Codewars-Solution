## Description:

You get an array of numbers, return the sum of all of the positives ones.

Example `[1, -4, 7, 12]` => `1 + 7 + 12 = 20`

Note: if there is nothing to sum, the sum is default to 0.

**Kata's link:** [Sum of positive](https://www.codewars.com/kata/5715eaedb436cf5606000381/cpp)

## Best Practices

**First:**
```cpp
#include <vector>

int positive_sum (const std::vector<int> &arr){
  int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] > 0) sum += arr[i];
    }
  return sum;
}
```

**Second:**
```cpp
#include <vector>

int positive_sum (const std::vector<int> array)
{
    int result = 0;
    for(int number : array) 
    {
        result += number > 0 ? number : 0;
    }
    return result;
}
```

## My Solutions
```cpp
#include <vector>
#include <string>

int positive_sum(const std::vector<int> arr) {
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
        if (arr[i] > 0)
            sum += arr[i];

    return sum;
}
```