## Description:

You might know some pretty large perfect squares.But what about the NEXT one ?

Complete the `findNextSquare` method that finds the next integral perfect square after the one passed as a parameter.Recall that an integral perfect square is an integer n such that sqrt(n) is also an integer.

If the parameter is itself not a perfect square then `- 1` should be returned.You may assume the parameter is non - negative.

### Examples : (Input-- > Output)

	121 -- > 144
	625 -- > 676
	114 -- > -1 since 114 is not a perfect square

**Kata's link:** [Find-the-next-perfect-square!](https://www.codewars.com/kata/56269eb78ad2e4ced1000013/cpp)

## Best Practices

**First:**
```cpp
#include <cmath>    
long int findNextSquare(long int sq) {
  if(sqrt(sq) != (int)sqrt(sq)){return -1;}
  return  pow(sqrt(sq) + 1,2);
}
```

**Second:**
```cpp
long int findNextSquare(long int sq) {
  auto sqrt = std::sqrt(sq);

  return std::modf(sqrt, &sqrt) == 0 ? std::pow(sqrt + 1, 2) : -1;
}
```

## My Solutions
```cpp
#include <cmath>

long int findNextSquare(long int sq) {
	if (sq % (long int)sqrt(sq)) return -1;
	else return (sqrt(sq) + 1) * (sqrt(sq) + 1);
}
```