## Description

Let's pretend your company just hired your friend from college and paid you a referral bonus. Awesome! To celebrate, you're taking your team out to the terrible dive bar next door and using the referral bonus to buy, and build, the largest three-dimensional beer can pyramid you can. And then probably drink those beers, because let's pretend it's Friday too.

A beer can pyramid will square the number of cans in each level - 1 can in the top level, 4 in the second, 9 in the next, 16, 25...

Complete the beeramid function to return the number of complete levels of a beer can pyramid you can make, given the parameters of:

1. your referral bonus, and

1. the price of a beer can

### For example:
```cpp
beeramid(1500, 2); // should === 12
beeramid(5000, 3); // should === 16
```

**Kata's link:** [Beeramid](https://www.codewars.com/kata/51e04f6b544cf3f6550000c1/cpp)

## Best Practices

**First:**
```cpp
int beeramid(int bonus, double price)
{ 
  int cans = bonus / price;
  int levels = 0;
  for (int i = 1; cans >= i*i; i++) {
    cans = cans - i*i;
    levels++;
  }
  return levels;
}
```

**Second:**
```cpp
#include <cmath>

// Returns number of complete beeramid levels
int beeramid(int bonus, double price)
{
  const unsigned int beer_count = bonus > 0 ? bonus / price : 0;

  // The number of levels follow the Fibonacci sequence
  //   1^2 + 2^2 + 3^2 + 4^2 + 5^2 + ... + n^2 = n*(n+1)*(2*n+1) = br
  // where n is the number of beeramid leves and the sum is the number of beers required
  // Using the cubic formula to get an expression of how many levels you get with a specific beer_count (bc)
  // n = (3*bc/2 + (((3bc/2)^2 - 1/1728)^(1/2))^(1/3) + (3*bc/2 - (((3bc/2)^2 - 1/1728)^(1/2))^(1/3) - 1/2
  // An approximation that 1/1728~=0 is good enough in this case
  // n ~= n_aprx = (3*bc)^(1/3) - 1/2
  // However if bc is close to the next level the n_aprx could get a value closer to n+1 rather than to n
  // That is round(n_aprx) is equal to n or n+1
  // To find out the real value of n we can check how many beers are required for round(n_aprx)
  // If more beers are required than beer_count then n=round(n_aprx)-1 else n=round(n_aprx)
  const unsigned int n = std::cbrt(3*beer_count); // round(n_aprx) = floor(n_aprx + 0.5)
  return beer_count >= n*(n+1)*(2*n+1)/6 ? n : n-1;
}
```

## My Solutions
```cpp
int beeramid(int bonus, double price)
{
  int moneyCanBuy = bonus/price;
  int levels = 0;
  int temp = 0;

  for(; moneyCanBuy >= temp; levels++)
  {
    temp += (levels)*(levels);
  }
  
  return levels-2;
}
```
