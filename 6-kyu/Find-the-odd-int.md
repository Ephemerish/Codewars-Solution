## Description:

Given an array of integers, find the one that appears an odd number of times.

There will always be only one integer that appears an odd number of times.
Examples:

    [7] should return 7, because it occurs 1 time(which is odd).
    [0] should return 0, because it occurs 1 time(which is odd).
    [1, 1, 2] should return 2, because it occurs 1 time(which is odd).
    [0, 1, 0, 1, 0] should return 0, because it occurs 3 times(which is odd).
    [1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1] should return 4, because it appears 1 time(which is odd).

**Kata's link:** [Find the odd int](https://www.codewars.com/kata/54da5a58ea159efa38000836/cpp)

## Best Practices

**First:**
```cpp
#include <vector>

int findOdd(const std::vector<int>& numbers){
  for (auto elem: numbers){
    if (std::count(numbers.begin(), numbers.end(), elem) % 2 != 0) {
      return elem;
    }
  }
  return 0;
}
```

**Second:**
```cpp
#include <functional>
#include <numeric>
#include <vector>

int findOdd(const std::vector<int>& numbers) {
  return std::accumulate(numbers.cbegin(), numbers.cend(), 0, std::bit_xor<>());
}
```

## My Solutions
```cpp
#include <vector>

int findOdd(const std::vector<int>& numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        int count = 0;

        for (int x = 0; x < numbers.size(); x++)
        {
            if (numbers[x] == numbers[i])
                count++;
        }

        if (count % 2 != 0)
            return numbers[i];
    }
}
```