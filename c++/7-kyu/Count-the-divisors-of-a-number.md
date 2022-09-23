## Description:

Count the number of divisors of a positive integer n.

Random tests go up to n = 500000.

### Examples (input --> output)

    4 --> 3 (1, 2, 4)
    5 --> 2 (1, 5)
    12 --> 6 (1, 2, 3, 4, 6, 12)
    30 --> 8 (1, 2, 3, 5, 6, 10, 15, 30)


**Kata's link:** [Count the divisors of a number](https://www.codewars.com/kata/542c0f198e077084c0000c2e/cpp)

## Best Practices

**First:**
```cpp
int divisors(int n){  
  int cnt = 1;
  for (int i = 1 ; i <= n/2 ; i++)
      if (n%i==0)
        cnt++;
  return cnt;
}
```

**Second:**
```cpp
#include <vector>

int divisors(int n){
  std::vector<int> divs; 
  for (int div = 1; div <= n; div++){
    if (n % div == 0)
      divs.emplace_back(div);
  }
  return divs.size();
}
```

## My Solutions
```cpp
int divisors(int n) {
    int counter = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            counter++;

    return counter;
}
```