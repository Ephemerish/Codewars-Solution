## Description:

Create a function with two arguments that will return an array of the first `n` multiples of `x`.

Assume both the given number and the number of times to count will be positive numbers greater than `0`.

Return the results as an array or list(depending on language).

### Examples
```cpp
countBy(1, 10)  should return  { 1,2,3,4,5,6,7,8,9,10 }
countBy(2, 5)  should return { 2,4,6,8,10 }
```

**Kata's link:** [Count by X](https://www.codewars.com/kata/5513795bd3fafb56c200049e/cpp)

## Best Practices

**First:**
```cpp
#include <vector>
std::vector<int> countBy(int x,int n){

  std::vector<int> z;
  if(x == 0){return {};}
  if(n == 0){return {};}
  
  int i;
  for(i=1;i<=n;i++){
    z.push_back(i*x);
  }
  
  return z;
}
```

**Second:**
```cpp
#include <algorithm>
#include <vector>

std::vector<int> countBy(int x,int n){
  std::vector<int> v(n);
  std::generate(v.begin(), v.end(), [k=0, &x] () mutable {return k+=x;});
  return v;
}
```

## My Solutions
```cpp
#include <vector>
std::vector<int> countBy(int x, int n)
{
    std::vector<int> result;
    for (int i = 1; i <= n; i++)
        result.push_back(x * i);
    return result;
}
```