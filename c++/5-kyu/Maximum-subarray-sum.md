## Description

The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

```cpp
maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});
//should be 6: {4, -1, 2, 1}
```

Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. If the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.


**Kata's link:** [Maximum subarray sum](https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c/cpp)

## Best Practices

**First:**
```cpp
#include <vector>

using namespace std;

int maxSequence(const vector<int>& arr) {
  int localmax=0;
  int globalmax=0;
  for (int i = 0;i<arr.size();i++)
  {
    localmax = localmax + arr[i];
    if (localmax > globalmax)
      globalmax = localmax;
    if (localmax < 0)
      localmax = 0;
  }
  return globalmax;
}
```

**Second:**
```cpp
#include <vector>

using namespace std;

int maxSequence(const vector<int>& arr) noexcept {
  int max = 0, local = 0;
  for (auto x : arr) {
    local = std::max(0, x + local);
    max = std::max(max, local);
  }
  return max;
}
```

## My Solutions
```cpp
#include <vector>

int maxSequence(const std::vector<int>& arr)
{ 
  int sum = 0;
  int largestSum = 0;
  for (unsigned long i = 0; i < arr.size(); i++)
  {
    sum = 0;
    for (unsigned long j = i; j < arr.size(); j++)
    {
      sum += arr[j];
      if (sum > largestSum)
        largestSum = sum;
    }
  }

  return largestSum;
}
```
