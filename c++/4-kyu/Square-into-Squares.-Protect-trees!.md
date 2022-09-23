## Description

My little sister came back home from school with the following task: given a squared sheet of paper she has to cut it in pieces which, when assembled, give squares the sides of which form an increasing sequence of numbers. At the beginning it was lot of fun but little by little we were tired of seeing the pile of torn paper. So we decided to write a program that could help us and protects trees.

### **Task**

Given a positive integral number n, return a strictly increasing sequence (list/array/string depending on the language) of numbers, so that the sum of the squares is equal to n².

If there are multiple solutions (and there will be), return as far as possible the result with the largest possible values:

### **Examples**

`decompose(11)` must return `[1,2,4,10]`. Note that there are actually two ways to decompose 11², 11² = 121 = 1 + 4 + 16 + 100 = 1² + 2² + 4² + 10² but don't return `[2,6,9]`, since 9 is smaller than 10.

For `decompose(50)` don't return `[1, 1, 4, 9, 49]` but `[1, 3, 5, 8, 49]` since `[1, 1, 4, 9, 49]` doesn't form a strictly increasing sequence.

### **Note**

Neither `[n]` nor `[1,1,1,…,1]` are valid solutions. If no valid solution exists, return `nil`, `null`, `Nothing`, `None` (depending on the language) or `"[]"` (C) ,`{}` (C++), `[]` (Swift, Go).

The function "decompose" will take a positive integer n and return the decomposition of N = n² as:

* [x1 ... xk] or
* "x1 ... xk" or
* Just [x1 ... xk] or
* Some [x1 ... xk] or
* {x1 ... xk} or
* "[x1,x2, ... ,xk]"

depending on the language (see "Sample tests")

## **Note for Bash**
```bash
decompose 50 returns "1,3,5,8,49"
decompose 4  returns "Nothing"
```
## **Hint**

Very often xk will be n-1.
****

**Kata's link:** [Square into Squares. Protect trees!](https://www.codewars.com/kata/54eb33e5bc1a25440d000891/cpp)

## Best Practices

**First:**
```cpp
#include <vector>

class Decomp
{
  public:
  static std::vector<long long> decompose(long long n);
  private:
  static bool Divide(std::vector<long long> &numbers, double remain, long long last);
};

std::vector<long long> Decomp::decompose(long long n)
{
  auto list = std::vector<long long>();
  if (Divide(list, n * n, n))
      return list;
  return std::vector<long long>() = {};
}

bool Decomp::Divide(std::vector<long long> &numbers, double remain, long long last)
{
    if (remain <= 0)
        return remain == 0;
    for (long long i = last - 1; i > 0; i--)
    {
        if (Divide(numbers, remain - (i * i), i))
        {
            numbers.push_back(i);
            return true;
        }
    }
    return false;
}
```

**Second:**
```cpp
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Decomp
{
  public:
  static std::vector<long long> decompose(long long n);
};

/*
 * What we want to do is loop backwards through the integers 1 to n 
 * (using a for loop, variable 'i') and deduct i*i from 'remaining',
 * which starts at n*n.
 *
 * Whenever we hit a 1, if 'remaining' is not 0, we have to take a step
 * back and retry the last index, but with the previous index being 
 * deducted by one.
 *
 * When we hit a 1 and remaining is 0, the correct solution is found.
 * 
 */
vector<long long> Decomp::decompose(long long n)
{
  vector<long long> v;

  long long nsquared = pow(n, 2);  // total value to achieve with our squared numbers
  long long remaining = nsquared;  // remaining value to get there
  
  for(int i = n-1; i > 0; i--)
  { 
    if(pow(i, 2) <= remaining)
    {
      // number (squared) fits in 'remaining' value, add to vector
      v.insert(v.begin(), i);
      remaining -= pow(i, 2);
    }
    
    while(i == 1 && remaining > 0)
    {
      // reached a 1 and 'nsquared' is still not reached
      // erase index and try again with preceding value -1
      v.erase(v.begin());
      v[0] -= 1;
      i = v[0];
      
      // recalculate 'remaining'
      remaining = nsquared;
      for(auto j : v)
        remaining -= pow(j, 2);    
    }

  }
    
  return v;
} 
```

## My Solutions
```cpp
class Decomp
{
  public:
  static std::vector<long long> decompose(long long n)
  {
    std::vector<long long> ans = {n};
    long long goal = 0;
    
    while (!ans.empty())
    {
      long long current = ans.back();
      ans.pop_back();
      
      goal += current * current;
      for (long long i = current - 1; i > 0; i--)
      {
        if (goal - (i * i) >= 0)
        {
          goal -= i * i;
          ans.push_back(i);
          if (goal == 0)
          {
            std::sort(ans.begin(), ans.end());
            return ans;
          }
        }
      }
    }
    return ans;
  }
};
```
