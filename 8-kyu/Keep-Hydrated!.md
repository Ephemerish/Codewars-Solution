## Description:

Nathan loves cycling.

Because Nathan knows it is important to stay hydrated, he drinks 0.5 litres of water per hour of cycling.

You get given the time in hours and you need to return the number of litres Nathan will drink, rounded to the smallest value.

### For example :

    time = 3 ---- > litres = 1

    time = 6.7--->litres = 3

    time = 11.8-- > litres = 5

**Kata's link:** [Keep Hydrated!](https://www.codewars.com/kata/582cb0224e56e068d800003c/cpp)

## Best Practices

**First:**
```cpp
int litres(double time) {
    return time*0.5;
}
```

**Second:**
```cpp
int litres(double time) {
    return time / 2;
}
```

## My Solutions
```cpp
#include <cmath>

int litres(double time) {
    return floor(time * 0.5);
}
```