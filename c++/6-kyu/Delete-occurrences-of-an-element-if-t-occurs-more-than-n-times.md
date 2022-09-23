## Description

**Enough is enough!**

Alice and Bob were on a holiday. Both of them took many pictures of the places they've been, and now they want to show Charlie their entire collection. However, Charlie doesn't like these sessions, since the motif usually repeats. He isn't fond of seeing the Eiffel tower 40 times.
He tells them that he will only sit for the session if they show the same motif at most `N` times. Luckily, Alice and Bob are able to encode the motif as a number. Can you help them to remove numbers such that their list contains each number only up to `N` times, without changing the order?
Task

Given a list and a number, create a new list that contains each number of `list` at most `N` times, without reordering.
For example if the input number is `2`, and the input list is `[1,2,3,1,2,1,2,3]`, you take `[1,2,3,1,2]`, drop the next `[1,2]` since this would lead to `1` and `2` being in the result `3` times, and then take `3`, which leads to `[1,2,3,1,2,3]`.
With list `[20,37,20,21]` and number 1, the result would be `[20,37,21]`.

### For C:

    Assign the return array length to the pointer parameter *szout.
    Do not mutate the input array.

**Kata's link:** [Delete occurrences of an element if it occurs more than n times](https://www.codewars.com/kata/554ca54ffa7d91b236000023/cpp)

## Best Practices

**First:**
```cpp
#include <unordered_map>
#include <vector>

std::vector<int> deleteNth(const std::vector<int>& xs, int n) {
  std::vector<int> res;
  std::unordered_map<int, int> ns;
  for (int x : xs)
    if (ns[x]++ < n)
      res.push_back(x);
  return res;
}
```

**Second:**
```cpp
std::vector<int> deleteNth(std::vector<int> arr, int n)
{
 std::vector<int> result;
  for (int x:arr)
    if (std::count(result.begin(),result.end(), x) < n) result.push_back(x);
  return result;
}
```

## My Solutions
```cpp
std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  for (unsigned int i = 0; i < arr.size(); i++)
  {
    int repeats = 0;
    for (unsigned int x = i; x < arr.size(); x++)
    {
      if(arr[i] == arr[x])
        repeats++;
      if (n < repeats && arr[i] == arr[x])
      {
        arr.erase(arr.begin() + x);
        x--;
      }
    }
  }
  return arr;
}
```
